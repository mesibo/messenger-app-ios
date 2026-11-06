//
//  SampleAPI.m
//  MesiboApplication
//
//  The app's backend (the messenger server, MessengerApiUrl in Info.plist): login and logout,
//  and starting mesibo with the user's token. Also keeps the app's settings.
//

#import "SampleAPI.h"
#import "SampleAppListeners.h"
#import "UIManager.h"

// keys of values saved with mesibo (setKey / readKey)
#define INVITE_KEY          @"inivte"
#define UPLOADURL_KEY       @"upload"
#define DOWNLOADURL_KEY     @"download"

// notification settings: empty (default) = enabled, "0" = disabled; same keys as Android
#define NOTIFY_MESSAGES_KEY @"notifymessages"
#define NOTIFY_GROUPS_KEY   @"notifygroups"


/** the value for key, nil for JSON null (NSNull) */
static id valueOrNil(NSDictionary *dictionary, NSString *key) {
    id value = dictionary[key];
    return value == [NSNull null] ? nil : value;
}


@implementation SampleAPI {
    NSUserDefaults *mUserDefaults;
    NSString *mApiUrl;
    NSString *mDeviceId;
    NSString *mDeviceType;

    NSString *mToken;
    NSString *mPhone;
    NSString *mInvite;
    NSString *mUploadUrl;
    NSString *mDownloadUrl;
    NSString *mNotice;
    NSString *mNoticeTitle;

    BOOL mResetSyncedContacts;
    BOOL mSyncStarted;
    SampleAPI_LogoutBlock mLogoutBlock;
}

+(SampleAPI *) getInstance {
    static SampleAPI *instance = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        instance = [SampleAPI new];
        [instance initialize];
    });
    return instance;
}

-(void) initialize {
    mApiUrl = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"MessengerApiUrl"];
    if (![mApiUrl hasPrefix:@"http://"] && ![mApiUrl hasPrefix:@"https://"]) {
        NSLog(@"************* INVALID URL - set a valid URL in MessengerApiUrl field in Info.plist *************");
    }

    mUserDefaults = [NSUserDefaults standardUserDefaults];
    mDeviceId = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    mDeviceType = [NSString stringWithFormat:@"%d", [MesiboInstance getDeviceType]];
    mToken = [mUserDefaults objectForKey:@"token"];

    // signed in before: start mesibo right away
    if (![SampleAPI isEmpty:mToken]) {
        [self startMesibo];
    }
}


#pragma mark - mesibo

-(void) startMesibo {
    // listeners first: they also do reverse lookups while mesibo starts
    [SampleAppListeners getInstance];

    NSString *documents = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    [MesiboInstance setPath:documents];
    [MesiboInstance setAccessToken:[self getToken]];
    [MesiboInstance setDatabase:@"mesiboapp.db"];

    [MesiboE2EInstance enable:YES];
    [MesiboInstance start];

    MesiboLocationConfig *locationConfig = [MesiboLocationConfig new];
    locationConfig.backgroundRefresh = NO;
    [[MesiboLocationManager getInstance] start:locationConfig];
}

-(void) startContactSync {
    @synchronized (self) {
        if (mSyncStarted)
            return;
        mSyncStarted = YES;
    }

    // a new login: sync all contacts again
    if (mResetSyncedContacts) {
        [[MesiboInstance getPhoneContactsManager] reset];
    }
    [[MesiboInstance getPhoneContactsManager] start];
}


#pragma mark - values

-(void) setOnLogout:(SampleAPI_LogoutBlock)logOutBlock {
    mLogoutBlock = logOutBlock;
}

-(NSString *) getToken {
    if ([SampleAPI isEmpty:mToken])
        return nil;
    return mToken;
}

-(NSString *) getPhone {
    if (nil == mPhone)
        mPhone = [MesiboInstance getAddress];
    return mPhone;
}

-(NSString *) getInvite {
    if (mInvite.length > 6)
        return mInvite;
    mInvite = [self savedValue:nil key:INVITE_KEY];
    return mInvite;
}

-(NSString *) getUploadUrl {
    if (mUploadUrl.length > 6)
        return mUploadUrl;
    mUploadUrl = [self savedValue:nil key:UPLOADURL_KEY];
    return mUploadUrl;
}

-(NSString *) getNotice {
    return mNotice;
}

-(NSString *) getNoticeTitle {
    return mNoticeTitle;
}

/** saves value with mesibo when given, else returns the saved one */
-(NSString *) savedValue:(NSString *)value key:(NSString *)key {
    if (value) {
        [MesiboInstance setKey:key value:value];
        return value;
    }
    return [MesiboInstance readKey:key];
}

-(void) save {
    [mUserDefaults setObject:mToken forKey:@"token"];
}


#pragma mark - notification settings

-(BOOL) getMessageNotification {
    return ![@"0" isEqualToString:[MesiboInstance readKey:NOTIFY_MESSAGES_KEY]];
}

-(void) setMessageNotification:(BOOL)enable {
    [MesiboInstance setKey:NOTIFY_MESSAGES_KEY value:enable ? @"" : @"0"];
}

-(BOOL) getGroupMessageNotification {
    return ![@"0" isEqualToString:[MesiboInstance readKey:NOTIFY_GROUPS_KEY]];
}

-(void) setGroupMessageNotification:(BOOL)enable {
    [MesiboInstance setKey:NOTIFY_GROUPS_KEY value:enable ? @"" : @"0"];
}


#pragma mark - login and logout

-(void) login:(NSString *)phone code:(NSString *)code handler:(SampleAPI_onResponse) handler {
    NSMutableDictionary *post = [NSMutableDictionary new];
    post[@"op"] = @"login";
    post[@"appid"] = [[NSBundle mainBundle] bundleIdentifier];
    post[@"phone"] = phone;

    if (code) {
        post[@"otp"] = code;
        post[@"device"] = mDeviceId;
    }

    [self invokeApi:post handler:handler];
}

-(void) logout:(BOOL)forced parent:(id)parent {
    [MesiboInstance stop];

    if (!forced) {
        [self startLogout:^(int result, NSDictionary *response) {
            [self logout:YES parent:parent];
        }];
        return;
    }

    mToken = @"";
    mPhone = nil;
    [self save];
    [MesiboInstance reset];

    if (mLogoutBlock)
        mLogoutBlock(parent);
}

-(void) startLogout:(SampleAPI_onResponse) handler {
    if (nil == mToken)
        return;

    // even if the token is wrong, logout happens through AUTHFAIL
    NSMutableDictionary *post = [NSMutableDictionary new];
    post[@"op"] = @"logout";
    post[@"token"] = mToken;
    [self invokeApi:post handler:handler];
}


#pragma mark - API calls

-(void) invokeApi:(NSMutableDictionary *)post handler:(SampleAPI_onResponse) handler {
    post[@"dt"] = mDeviceType;

    NSData *body = [NSJSONSerialization dataWithJSONObject:post options:0 error:nil];
    if (!body) {
        if (handler)
            handler(SAMPLEAPP_RESULT_FAIL, nil);
        return;
    }

    MesiboHttp *http = [MesiboHttp new];
    http.url = mApiUrl;
    http.contentType = @"application/json";
    http.post = body;
    http.listener = ^BOOL(MesiboHttp *request, int state, int progress) {
        if (100 == progress && MESIBO_HTTPSTATE_DOWNLOAD == state) {
            [self parseResponse:[request getDataString] handler:handler];
        }

        if (progress < 0) {
            NSLog(@"invokeApi failed");
            if (handler)
                handler(SAMPLEAPP_RESULT_FAIL, nil);
        }
        return YES;
    };
    [http execute];
}

-(void) parseResponse:(NSString *)responseText handler:(SampleAPI_onResponse) handler {
    NSData *data = [responseText dataUsingEncoding:NSUTF8StringEncoding];
    id json = data ? [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:nil] : nil;
    NSDictionary *response = [json isKindOfClass:NSDictionary.class] ? json : nil;

    if (nil == response) {
        if (handler)
            handler(SAMPLEAPP_RESULT_FAIL, nil);
        return;
    }

    // failed: sign out on AUTHFAIL, else show the server's message
    if (![@"OK" isEqualToString:valueOrNil(response, @"result")]) {
        if ([@"AUTHFAIL" isEqualToString:valueOrNil(response, @"error")]) {
            [self logout:YES parent:nil];
            return;
        }

        NSString *message = valueOrNil(response, @"errmsg");
        if (message) {
            NSString *title = valueOrNil(response, @"errtitle") ?: @"Failed";
            [UIManager alert:title message:message];
        }

        if (handler)
            handler(SAMPLEAPP_RESULT_FAIL, response);
        return;
    }

    // values the server may send with any response
    NSString *invite = valueOrNil(response, @"invite");
    if (invite.length > 0) {
        mInvite = [self savedValue:invite key:INVITE_KEY];
    }

    NSDictionary *urls = valueOrNil(response, @"urls");
    if (urls) {
        mUploadUrl = [self savedValue:valueOrNil(urls, @"upload") key:UPLOADURL_KEY];
        mDownloadUrl = [self savedValue:valueOrNil(urls, @"download") key:DOWNLOADURL_KEY];
    }

    NSDictionary *notice = valueOrNil(response, @"notice");
    if (notice) {
        mNoticeTitle = valueOrNil(notice, @"title");
        mNotice = valueOrNil(notice, @"desc");
    }

    // signed in: save the token and start mesibo for this user
    if ([@"login" isEqualToString:valueOrNil(response, @"op")]) {
        mToken = valueOrNil(response, @"token");
        mPhone = valueOrNil(response, @"phone");

        if (![SampleAPI isEmpty:mToken]) {
            [self save];
            mResetSyncedContacts = YES;
            mSyncStarted = NO;
            [MesiboInstance reset];
            [self startMesibo];
        }
    }

    if (handler)
        handler(SAMPLEAPP_RESULT_OK, response);
}


#pragma mark - helpers

/** new_user in the login response: a user without a profile yet; may come as true, 1 or "1" */
+(BOOL) isNewUser:(NSDictionary *)response {
    id value = valueOrNil(response, @"new_user");
    if ([value isKindOfClass:NSNumber.class])
        return [value boolValue];
    if ([value isKindOfClass:NSString.class])
        return [value isEqualToString:@"1"] || NSOrderedSame == [value caseInsensitiveCompare:@"true"];
    return NO;
}

+(BOOL) isEmpty:(NSString *)string {
    return 0 == string.length;
}

@end
