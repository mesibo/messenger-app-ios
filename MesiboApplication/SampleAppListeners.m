//
//  SampleAppListeners.m
//  MesiboApplication
//

#import "SampleAppListeners.h"
#import "SampleAPI.h"
#import "SampleAppNotify.h"
#import "UIManager.h"

@implementation SampleAppListeners {
    int _screen;   // the last mesibo screen shown: 0 the chat list, 1 a chat
}

+ (SampleAppListeners *)getInstance {
    static SampleAppListeners *instance = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        instance = [SampleAppListeners new];
        [MesiboInstance addListener:instance];
    });
    return instance;
}

/**
 * A notification for a message the user can't see: not for the chat that is open, nor while the
 * chat list is on screen (it shows the message); otherwise also while the app is open.
 */
- (void)Mesibo_onMessage:(MesiboMessage *)msg {
    if ([MesiboInstance isReading:msg] || [msg isCall])
        return;
    if ([MesiboInstance isAppInForeground] && 0 == _screen)
        return;
    [SampleAppNotifyInstance notifyMessage:msg];
}

/** messages of type 1 are for notifications only and are not kept (normal messages are type 0); calls are kept */
- (BOOL)Mesibo_onMessageFilter:(MesiboMessage *)msg {
    if (1 != msg.type || [msg isCall])
        return YES;
    return NO;
}

- (void)Mesibo_onConnectionStatus:(NSInteger)status {
    if (MESIBO_STATUS_SIGNOUT == status) {
        [UIManager alert:@"Signed Out" message:@"You have signed-in from other device and hence signed out here"];
        [SampleAPIInstance logout:YES parent:nil];
    } else if (MESIBO_STATUS_AUTHFAIL == status) {
        [UIManager alert:@"Signed Out" message:@"Login Expired. Login again to continue."];
        [SampleAPIInstance logout:YES parent:nil];
    }
}

- (void)Mesibo_onGroupJoined:(MesiboProfile *)groupProfile {
    [SampleAppNotifyInstance notify:SAMPLEAPP_NOTIFYTYPE_OTHER subject:@"Joined a group"
                            message:[NSString stringWithFormat:@"You have been added to the group %@", [groupProfile getName]]];
}

- (void)Mesibo_onGroupLeft:(MesiboProfile *)groupProfile {
    [SampleAppNotifyInstance notify:SAMPLEAPP_NOTIFYTYPE_OTHER subject:@"Left a group"
                            message:[NSString stringWithFormat:@"You left the group %@", [groupProfile getName]]];
}

- (void)Mesibo_onForeground:(id)parent screenId:(int)screenId foreground:(BOOL)foreground {
    if (foreground)
        _screen = screenId;
    // the chat list: clear message notifications
    if (foreground && 0 == screenId)
        [SampleAppNotifyInstance clear];
}

- (BOOL)Mesibo_onCustomizeProfile:(MesiboProfile *)profile {
    return YES;
}

/** nil: the default (no custom picture) */
- (UIImage *)Mesibo_onGetProfileImage:(MesiboProfile *)profile {
    return nil;
}

/** the formatted phone number for a contact without a name; nil: the default */
- (NSString *)Mesibo_onGetProfileName:(MesiboProfile *)profile {
    if ([profile isGroup])
        return nil;
    MesiboPhoneContact *c = [[MesiboInstance getPhoneContactsManager] getPhoneNumberInfo:[profile getAddress] format:YES];
    return c.formattedPhoneNumber;
}

@end
