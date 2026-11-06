//
//  AppDelegate.m
//  MesiboApplication
//
//  App start (UIManager routes to welcome / login or the chat list), push notifications and the
//  app's foreground state.
//

#import "AppDelegate.h"
#import "SampleAPI.h"
#import "UIManager.h"
#import <Intents/Intents.h>

// reference: your own file transfer server (SampleAppFileTransferHandler), not used by default
// #import "SampleAppFileTransferHandler.h"

/**
 * The window of the app's scene (UIScene lifecycle, Info.plist UIApplicationSceneManifest). It is
 * also set as the app delegate's window, where the app and libraries look for it.
 */
@interface SceneDelegate : UIResponder <UIWindowSceneDelegate>
@property (nonatomic, strong) UIWindow *window;
@end

@implementation SceneDelegate

- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    if (![scene isKindOfClass:[UIWindowScene class]])
        return;
    self.window = [[UIWindow alloc] initWithWindowScene:(UIWindowScene *)scene];
    ((AppDelegate *)UIApplication.sharedApplication.delegate).window = self.window;
    [[UIManager getInstance] start:self.window];
    // a call from the Phone app's recents that launched the app
    for (NSUserActivity *a in connectionOptions.userActivities)
        [self scene:scene continueUserActivity:a];
}

#pragma mark foreground state

- (void)sceneDidEnterBackground:(UIScene *)scene {
    [MesiboInstance setAppInForeground:self screenId:0 foreground:NO];
}

- (void)sceneDidBecomeActive:(UIScene *)scene {
    [MesiboInstance setAppInForeground:self screenId:0 foreground:YES];
}

#pragma mark calls

// a call from the Phone app's recents (CallKit): show the call in progress
- (void)scene:(UIScene *)scene continueUserActivity:(NSUserActivity *)userActivity {
    UIViewController *top = [[UIManager getInstance] topController];
    if (top)
        [MesiboCallInstance callUiForExistingCall:top];
}

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // push notifications (message wake-ups); VoIP pushes for calls are handled by MesiboCall
    UNUserNotificationCenter.currentNotificationCenter.delegate = self;
    [application registerForRemoteNotifications];
    application.applicationIconBadgeNumber = 0;

    SampleAPIInstance;   // starts mesibo when signed in
    // the window and the first screen: SceneDelegate

    return YES;
}

// foreground / background and calls from the Phone app's recents: SceneDelegate

#pragma mark - push

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    NSMutableString *token = [NSMutableString stringWithCapacity:deviceToken.length * 2];
    const unsigned char *bytes = deviceToken.bytes;
    for (NSUInteger i = 0; i < deviceToken.length; i++)
        [token appendFormat:@"%02X", bytes[i]];
    [MesiboInstance setPushToken:token voip:NO];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSLog(@"Push registration failed: %@", error);
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
    fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    [MesiboInstance didReceiveRemoteNotification:userInfo fetchCompletionHandler:completionHandler];
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification
         withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler {
    completionHandler(UNNotificationPresentationOptionBadge | UNNotificationPresentationOptionBanner | UNNotificationPresentationOptionList | UNNotificationPresentationOptionSound);
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response
         withCompletionHandler:(void (^)(void))completionHandler {
    completionHandler();
}

@end
