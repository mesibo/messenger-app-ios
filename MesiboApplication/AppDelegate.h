//
//  AppDelegate.h
//  MesiboApplication
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import "Includes.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate, UNUserNotificationCenterDelegate>

@property (strong, nonatomic) UIWindow *window;

@end
