//
//  UIManager.h
//  MesiboApplication
//
//  The app's screens and navigation: welcome and login (MesiboUIHelper), the new user's profile,
//  the chat list (MesiboUI), settings; the theme setting and alerts. Same as UIManager on
//  Android.
//

#import <Foundation/Foundation.h>
#import "Includes.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIManager : NSObject <MesiboLoginUiHelperListener>

+ (UIManager *)getInstance;

/** the first screen: the chat list when signed in, else the welcome screen */
- (void)start:(UIWindow *)window;
- (void)launchWelcome;
/** after logout */
- (void)launchLogin;
/** the chat list (signed in) */
- (void)launchMain;
/** the user's profile; newUser: the "profile info" step after the first sign in, then the chat list */
- (void)launchEditProfile:(nullable UIViewController *)parent newUser:(BOOL)newUser;
- (void)launchSettings:(UIViewController *)parent;

/** the screen on top, for alerts */
- (nullable UIViewController *)topController;
+ (void)alert:(nullable NSString *)title message:(nullable NSString *)message;
+ (void)shareText:(NSString *)text parent:(UIViewController *)parent;

// -- theme (Settings): applied when the app starts --
/** MESIBO_THEME_SYSTEM (default), MESIBO_THEME_LIGHT or MESIBO_THEME_DARK */
+ (int)theme;
+ (NSString *)themeName;
+ (void)applyTheme;
/** System default / Light / Dark; saved, applied the next time the app starts */
+ (void)chooseTheme:(UIViewController *)parent changed:(nullable dispatch_block_t)changed;

@end

NS_ASSUME_NONNULL_END
