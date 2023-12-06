/******************************************************************************
* By accessing or copying this work, you agree to comply with the following   *
* terms:                                                                      *
*                                                                             *
* Copyright (c) 2019-2023 mesibo                                              *
* https://mesibo.com                                                          *
* All rights reserved.                                                        *
*                                                                             *
* Redistribution is not permitted. Use of this software is subject to the     *
* conditions specified at https://mesibo.com . When using the source code,    *
* maintain the copyright notice, conditions, disclaimer, and  links to mesibo * 
* website, documentation and the source code repository.                      *
*                                                                             *
* Do not use the name of mesibo or its contributors to endorse products from  *
* this software without prior written permission.                             *
*                                                                             *
* This software is provided "as is" without warranties. mesibo and its        *
* contributors are not liable for any damages arising from its use.           *
*                                                                             *
* Documentation: https://mesibo.com/documentation/                            *
*                                                                             *
* Source Code Repository: https://github.com/mesibo/                          *
*******************************************************************************/

#import "AppDelegate.h"
#import "UIColors.h"
#import "SampleAPI.h"
#import "EditProfileController.h"
#import "CommonAppUtils.h"
#import "UIManager.h"
#import "AppAlert.h"
#import "AppUIManager.h"

#import "NSDictionary+NilObject.h"

#import "MesiboUIHelper/MesiboUIHelper.h"
#import "MesiboCall/MesiboCall.h"
#import "SamplePushKitNotify.h"
#import "UIListener.h"

#import <Intents/Intents.h>

@interface AppDelegate () <MesiboCallIncomingListener>

@end






@implementation AppDelegate


{
    MesiboUIHelper *mMesiboUIHelper;
    MesiboUiHelperConfig *mAppLaunchData;
    NSArray * imagesArraytest;
    NSArray * labelsArraytest;
    NSArray * imagesArray;
    
    NSString * tempName ;
    long tempgroupid ;
    NSString * temppath ;
    NSString * tempstatus ;
    MesiboUI *mMUILauncher ;
    MesiboCall *mesiboCall;
    
    SamplePushKitNotify *pushNotify;
    UIListener *uiListener;
    
    AppDelegate *_thiz;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    _thiz = self;
    
    [MesiboInstance addListener:self];
    
    if ([application respondsToSelector:@selector(isRegisteredForRemoteNotifications)])
    {
        // for iOS 8
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil]];
        [application registerForRemoteNotifications];
    }
    application.applicationIconBadgeNumber = 0;
    
    
#if 0
    // Enable it for your own file handler
    _fileTranserHandler = [[SampleAppFileTransferHandler alloc] init];
    [_fileTranserHandler initialize];
#endif
    
    
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    
    
    [[UINavigationBar appearance] setBarTintColor:[UIColor getColor:PRIMARY_COLOR]];
    [[UINavigationBar appearance] setTranslucent:NO];
    
    
    NSDictionary *attributes = @{
        NSUnderlineStyleAttributeName: @1,
        NSForegroundColorAttributeName : [UIColor getColor:TITLE_TXT_COLOR],
        NSFontAttributeName: [UIFont fontWithName:@"HelveticaNeue-Bold" size:17]
    };
    
    [[UINavigationBar appearance] setTitleTextAttributes:attributes];
    
    
    
    mMesiboUIHelper = [[MesiboUIHelper alloc] init];
    mAppLaunchData = [[MesiboUiHelperConfig alloc] init];
    
    
    [MesiboInstance addListener:self];
    
    SampleAPIInstance; // just to intitialize
    
    [SampleAPIInstance setOnLogout:^(id parent) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if(parent) {
                [(UIViewController *)parent dismissViewControllerAnimated:NO completion:nil];
            }
            [self launchLoginUI];
        });
    }];
    
    
    // If token is not nil, SampleAPI will start Mesibo as well
    if(nil != [SampleAPIInstance getToken]) {
        [self launchMainUI];
    } else {
        
        [self doLaunchWelcomeController];
    }
    
    
    pushNotify = [SamplePushKitNotify getInstance];
    
    UNUserNotificationCenter* center = [UNUserNotificationCenter currentNotificationCenter];
    center.delegate = self;

    return YES;
}

-(void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler {
    
    completionHandler(UNNotificationPresentationOptionBadge | UNNotificationPresentationOptionAlert | UNNotificationPresentationOptionSound);
    
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)(void))completionHandler {
    completionHandler();
}

- (void)applicationWillResignActive:(UIApplication *)application {
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    [MesiboInstance setAppInForeground:self screenId:0 foreground:NO];
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    [MesiboInstance setAppInForeground:self screenId:0 foreground:YES];
    //[MesiboCallInstance showCallInProgress];
}


- (void)applicationWillTerminate:(UIApplication *)application {
}

- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken {
    NSString * deviceTokenString = [[[[deviceToken description] stringByReplacingOccurrencesOfString: @"<" withString: @""] stringByReplacingOccurrencesOfString: @">" withString: @""]   stringByReplacingOccurrencesOfString: @" " withString: @""];

    NSUInteger capacity = deviceToken.length * 2;
    NSMutableString *sbuf = [NSMutableString stringWithCapacity:capacity];
    const unsigned char *buf = deviceToken.bytes;
    NSInteger i;
    for (i=0; i < deviceToken.length; ++i) {
        [sbuf appendFormat:@"%02X", (int)buf[i]];
    }
    
    [MesiboInstance setPushToken:sbuf voip:NO];
}

-(void) application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    
    completionHandler(UIBackgroundFetchResultNoData);
}


-(void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    
    [MesiboInstance didReceiveRemoteNotification:userInfo fetchCompletionHandler:completionHandler];
    return;
    
}

- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error {
    Log(@"Failed to get token, error: %@", error);
}

-(BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler {
    
    
    INInteraction *interaction = userActivity.interaction;
    INStartAudioCallIntent *startAudioCallIntent = (INStartAudioCallIntent *)interaction.intent;
    INPerson *contact = startAudioCallIntent.contacts[0];
    INPersonHandle *personHandle = contact.personHandle;
    NSString *phoneNum = personHandle.value;
    //[CallManager sharedInstance].delegate = self;
    //[[CallManager sharedInstance] startCallWithPhoneNumber:phoneNum];
    [MesiboCallInstance callUiForExistingCall:nil];
    return YES;
}

-(void) Mesibo_onConnectionStatus:(int)status {
    Log(@"OnConnectionStatus status: %d", status);
    
    if(status == MESIBO_STATUS_SIGNOUT) {
        [self logoutFromApplication:nil];
        [AppAlert showDialogue:@"You have been loggeed out from this device. Kindly signin to continue" withTitle:@"Logged out"];
        
    }else if(status == MESIBO_STATUS_AUTHFAIL) {
        [self logoutFromApplication:nil];
    }
}

-(void) setRootController:(UIViewController *) controller {
    self.window.rootViewController = controller;
    [self.window setRootViewController:controller];
    [self.window makeKeyAndVisible];
}

- (void)  onLogin:(NSString*)phone code:(NSString*)code akToken:(NSString *)akToken caller:(id)caller handler:(PhoneVerificationResultBlock) resultHandler {
    
    [[UIManager getInstance] addProgress:((UIViewController *)(caller)).view];
    [[UIManager getInstance] showProgress];
    
    SampleAPI_onResponse handler = ^(int result, NSDictionary *response) {
        [[UIManager getInstance] hideProgress];
        NSLog(@"%@" ,response);
        NSString *op = (NSString *)[response objectForKey:@"op"];
        NSString *resultz = (NSString *)[response objectForKey:@"result"];
        if([op isEqualToString:@"login"]) {
            if(nil != [SampleAPIInstance getToken] && [resultz isEqualToString:@"OK"]) {
                [self dismissAndlaunchMainUI:(UIViewController*)caller];
            }
            
            if(resultHandler) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    resultHandler([resultz isEqualToString:@"OK"]);
                });
            }
        }
    };
    
    
    [SampleAPIInstance login:phone code:code handler:handler];
    
}

-(void) launchMesiboUI {
    
    
    MesiboUiDefaults *ui = [MesiboUI getUiDefaults];
    ui.emptyUserListMessage = @"No active conversations! Click on the message icon to send a message.";
    ui.preferredLocationApp = LOCATION_APP_PROMPTONCE;
    ui.showAddressInProfileView = YES;
    ui.showAddressAsPhoneInProfileView = YES;
    
    
    uiListener = [UIListener new];
    
    MesiboUserListScreenOptions *opts = [MesiboUserListScreenOptions new];
    
    UIViewController *mesiboController = [MesiboUI getUserListViewController:opts];
    UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:mesiboController];
    [self setRootController:navigationController];
    
    
    [AppUIManager setDefaultParent:navigationController];

    // callkit will be automatically disabled for China
    mesiboCall = [MesiboCall startWith:nil name:@"mesibo" icon:nil callKit:YES];
}

-(void) launchMainUI {
    
    [SampleAPIInstance startContactSync];
    
    MesiboProfile *sp = [MesiboInstance getSelfProfile];
    if([SampleAPI isEmpty:[sp getName]]) {
        [MesiboInstance runInThread:YES handler:^{
            [self launchEditProfile];
        }];
        return;
    }
    
        [MesiboInstance runInThread:YES handler:^{
            [self launchMesiboUI];
            
        }];
     
}

-(void) dismissAndlaunchMainUI:(UIViewController *)previousController {
    if(!previousController) {
        [self launchMainUI];
        return;
    }
    
    [previousController dismissViewControllerAnimated:NO completion:^{
        [self launchMainUI];
    }];
    
}

-(void) launchLoginUIAfterLoginUiCheck {
    UIViewController  *loginController ;
    
    loginController = [MesiboUIHelper startMobileVerification:^(id caller, NSString *phone, NSString *code, PhoneVerificationResultBlock resultBlock) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [(UIViewController*)caller resignFirstResponder];
        });
        [self onLogin:phone code:code akToken:nil caller:caller handler:resultBlock];
    }];
    
    [self setRootController:loginController];
    mAppLaunchData.mBanners = nil;
    
}

-(void) launchLoginUI {
    [self setupUiHelper];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self launchLoginUIAfterLoginUiCheck];
    });
    
}

-(void) setupUiHelper {
    mAppLaunchData = [[MesiboUiHelperConfig alloc] init];
    int countryCode = 1;
    
    //query_mesibo_webrtc();
    
    mAppLaunchData.mCountryCode = [NSString stringWithFormat:@"%d", countryCode];
    mAppLaunchData.mAppName = @"Mesibo";
    mAppLaunchData.mAppTag = @"Messaging, Calls and Conferences";
    mAppLaunchData.mAppUrl = @"https://www.mesibo.com";
    mAppLaunchData.mAppWriteUp = @"";
    
    mAppLaunchData.mLoginTitle = @"welcome To mesibo";
    mAppLaunchData.mLoginDesc = @"Enter a valid phone number to begin";
    mAppLaunchData.mLoginBottomDesc = @"IMPORTANT: We will NOT send OTP.  Instead, you can generate OTP from the mesibo console. Sign up at https://mesibo.com/console";
    mAppLaunchData.mOtpTitle = @"Enter OTP";
    mAppLaunchData.mOtpDesc = @"Enter OTP for %@";
    mAppLaunchData.mOtpBottomDesc = mAppLaunchData.mLoginBottomDesc;
    
    mAppLaunchData.mLoginTitleColor = 0xFF00868b;
    mAppLaunchData.mLoginDescColor = 0xFF444444;
    mAppLaunchData.mLoginBottomDescColor = 0xAAFF0000;
    
    mAppLaunchData.mTextColor = 0xFF172727;
    mAppLaunchData.mBackgroundColor = 0xFFFFFFFF;
    mAppLaunchData.mButtonBackgroundColor = 0xFF00868b;
    mAppLaunchData.mButtonTextColor = 0xFFFFFFFF;
    mAppLaunchData.mSecondaryTextColor = 0xFF666666;
    mAppLaunchData.mBannerTitleColor = 0xFFFFFFFF;
    mAppLaunchData.mBannerDescColor =  0xEEFFFFFF;
    
    NSMutableArray *banners = [NSMutableArray new];
    
    WelcomeBanner *banner = nil;
    
    banner = [WelcomeBanner new];
    banner.mTitle = @"Messaging, Calls and Conferences";
    banner.mDescription = @"Add messaging, Video and Voice calls & conferencing in your apps in no time. Mesibo is built from ground-up to power this!";
    banner.mImage = [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"welcome"] ofType:@"png"]];
    banner.mColor = 0xff00868b; //0xff0f9d58;
    [banners addObject:banner];
    
    banner = [WelcomeBanner new];
    banner.mTitle = @"Messaging, Voice, & Video";
    banner.mDescription = @"Complete infrastructure with powerful APIs to get you started, rightaway!";
    banner.mImage = [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"plug_play"] ofType:@"png"]];
    banner.mColor = 0xff0f9d58; //0xff00bcd4; //0xfff4b400;
    [banners addObject:banner];
    
#if 0
    banner = [WelcomeBanner new];
    banner.mTitle = @"Plug & Play Modules";
    banner.mDescription = @"Not just the API, you can even use mesibo UI modules to quickly enable Voice, Video & Messaging in your app";
    banner.mImage = [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"plug_play"] ofType:@"png"]];
    banner.mColor = 0xfff4b400; //0xfff4b400;
    [banners addObject:banner];
#endif
    
    banner = [WelcomeBanner new];
    banner.mTitle = @"Open Source";
    banner.mDescription = @"Quickly integrate Mesibo in your own apps by downloading our source code from GitHub";
    banner.mImage = [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"opensource_ios"] ofType:@"png"]];
    banner.mColor = 0xff054a61; //0xfff4b400;
    [banners addObject:banner];
    
#if 0
    banner = [WelcomeBanner new];
    banner.mTitle = @"No Sweat Pricing";
    banner.mDescription = @"Start free & only pay as you grow!";
    banner.mImage = [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"users"] ofType:@"png"]];
    banner.mColor = 0xff00bcd4;
    [banners addObject:banner];
#endif
    
    mAppLaunchData.mBanners = banners;
    
    [MesiboUIHelper setUiConfig:mAppLaunchData];
}

//extern void *query_mesibo_webrtc();
- (void) doLaunchWelcomeController {
    
    [self setupUiHelper];
    
    UIViewController *welcomeController = [MesiboUIHelper getWelcomeViewController:^(UIViewController *parent, BOOL result) {
        
        [self launchLoginUI];
        [parent dismissViewControllerAnimated:NO completion:nil];
    }];
    
    [self setRootController:welcomeController];
}

-(void) launchEditProfile {
    NSBundle *bundle = [NSBundle mainBundle];
    UIStoryboard *storybord = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    EditProfileController *editSelfProfileController =[storybord instantiateViewControllerWithIdentifier:@"EditSelfProfileViewController"];
    
    [editSelfProfileController setLaunchMesiboCallback:^{
        [self launchMainUI];
    }];
    
    [editSelfProfileController setProfile:[MesiboInstance getSelfProfile]];
    
    [self setRootController:editSelfProfileController];
    
}

- (void) Mesibo_onDeleteProfile:(id)parent profile:(MesiboProfile *)profile handler:(Mesibo_onSetGroupHandler)handler{
    
    
}

-(void) logoutFromApplication:(UIViewController *)sender {
    [self launchLoginUI];
    

}




@end
