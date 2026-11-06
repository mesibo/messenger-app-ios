//
//  UIManager.m
//  MesiboApplication
//

#import "UIManager.h"
#import "SampleAPI.h"
#import "UIListener.h"
#import "CallListeners.h"
#import "SettingsViewController.h"
#import "SampleAppNotify.h"

#define BRAND_COLOR 0xff00868b
#define THEME_KEY @"theme"

@interface UIManager () <MesiboEditProfileListener>
@end

@implementation UIManager {
    UIWindow *_window;
    UIListener *_uiListener;
}

+ (UIManager *)getInstance {
    static UIManager *instance = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ instance = [UIManager new]; });
    return instance;
}

- (void)start:(UIWindow *)window {
    _window = window;
    [UIManager applyTheme];
    __weak typeof(self) weakSelf = self;
    [SampleAPIInstance setOnLogout:^(id parent) {
        dispatch_async(dispatch_get_main_queue(), ^{ [weakSelf launchLogin]; });
    }];
    if (![SampleAPI isEmpty:[SampleAPIInstance getToken]])
        [self launchMain];
    else
        [self launchWelcome];
}

- (void)setRoot:(UIViewController *)vc {
    _window.rootViewController = vc;
    [_window makeKeyAndVisible];
}

#pragma mark - welcome and login

- (MesiboWelcomeOptions *)welcomeOptions {
    MesiboWelcomeOptions *w = [MesiboWelcomeOptions new];
    w.logo = [UIImage imageNamed:@"mesibo_logo_white"];
    w.title = @"Messaging & Calls in your apps";
    w.descriptionText = @"Add messaging, video and voice calls & conferencing in your apps in no time.";
    w.githubUrl = @"https://github.com/mesibo";
    w.buttonText = @"Get Started";
    // colors: MesiboUIHelper defaults (black background, white text and button)
    return w;
}

- (MesiboLoginOptions *)loginOptions {
    MesiboLoginOptions *o = [MesiboLoginOptions new];
    MesiboPhoneContact *country = [[MesiboInstance getPhoneContactsManager] getCountryCode];
    o.defaultCountryCode = (country.countryPhoneCode > 0) ? country.countryPhoneCode : 1;

    // we do not send verification codes; testers generate them from the mesibo console
    o.note = @"This demo app will NOT send verification code. You can generate yourself from the mesibo console https://console.mesibo.com";
    o.noteIcon = [UIImage systemImageNamed:@"hand.tap"];
    o.noteColor = 0xffb45309;
    o.noteBorderColor = 0x55ffb900;
    o.noteBackgroundColor = 0x14ffb900;
    o.codeMessage = @"Enter the verification code for %PHONE% generated from the mesibo console";

    o.backgroundColor = 0xffffffff;
    o.titleColor = 0xff172727;
    o.messageColor = 0xff666666;
    o.inputColor = 0xff172727;
    o.accentColor = BRAND_COLOR;
    o.buttonColor = BRAND_COLOR;
    o.buttonTextColor = 0xffffffff;
    return o;
}

- (void)launchWelcome {
    [self setRoot:[MesiboUIHelper getWelcomeViewController:[self welcomeOptions] login:[self loginOptions] listener:self]];
}

- (void)launchLogin {
    [self setRoot:[MesiboUIHelper getLoginViewController:[self loginOptions] listener:self]];
}

- (BOOL)MesiboLoginUiHelper_onLogin:(UIViewController *)parent phone:(NSString *)phone code:(NSString *)code result:(MesiboLoginResultBlock)result {
    [SampleAPIInstance login:phone code:code handler:^(int r, NSDictionary *response) {
        BOOL ok = SAMPLEAPP_RESULT_OK == r;
        dispatch_async(dispatch_get_main_queue(), ^{
            result(ok);
            // signed in: a new user sets a name and picture first
            if (ok && code && ![SampleAPI isEmpty:[SampleAPIInstance getToken]]) {
                if ([SampleAPI isNewUser:response])
                    [self launchEditProfile:nil newUser:YES];
                else
                    [self launchMain];
            }
        });
    }];
    return YES;
}

#pragma mark - main

- (void)launchMain {
    [SampleAPIInstance startContactSync];
    [SampleAppNotify getInstance];   // asks for notification permission (once)

    MesiboUiDefaults *ui = [MesiboUI getUiDefaults];
    ui.emptyUserListMessage = @"No messages! Click on the message icon below to start messaging!";
    ui.showAddressInProfileView = YES;

    if (nil == _uiListener)
        _uiListener = [UIListener new];
    [CallListeners start];

    UIViewController *list = [MesiboUI getUserListViewController:[MesiboUserListScreenOptions new]];
    [self setRoot:[[UINavigationController alloc] initWithRootViewController:list]];

    // a notice from the server (e.g. limits of the demo)
    NSString *notice = [SampleAPIInstance getNotice];
    if (notice.length > 0) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [UIManager alert:[SampleAPIInstance getNoticeTitle] message:notice];
        });
    }
}

- (void)launchEditProfile:(UIViewController *)parent newUser:(BOOL)newUser {
    [MesiboUI setEditProfileListener:self];
    [[MesiboInstance getSelfProfile] setSearchable:YES];
    MesiboEditProfileOptions *opts = [MesiboEditProfileOptions new];
    opts.newUser = newUser;
    if (parent) {
        [MesiboUI launchEditProfile:parent opts:opts];
        return;
    }
    // first sign in: shown over an empty screen, then the chat list
    UIViewController *blank = [UIViewController new];
    blank.view.backgroundColor = UIColor.systemBackgroundColor;
    [self setRoot:blank];
    dispatch_async(dispatch_get_main_queue(), ^{
        [MesiboUI launchEditProfile:blank opts:opts];
    });
}

- (void)MesiboEditProfile_onSaved:(UIViewController *)parent profile:(MesiboProfile *)profile newUser:(BOOL)newUser {
    if (newUser)
        [self launchMain];
}

- (void)launchSettings:(UIViewController *)parent {
    SettingsViewController *s = [SettingsViewController new];
    if (parent.navigationController) {
        [parent.navigationController pushViewController:s animated:YES];
        return;
    }
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:s];
    nav.modalPresentationStyle = UIModalPresentationFullScreen;
    [parent presentViewController:nav animated:YES completion:nil];
}

#pragma mark - helpers

- (UIViewController *)topController {
    UIViewController *top = _window.rootViewController;
    while (top.presentedViewController)
        top = top.presentedViewController;
    if ([top isKindOfClass:UINavigationController.class])
        top = ((UINavigationController *)top).topViewController ?: top;
    return top;
}

+ (void)alert:(NSString *)title message:(NSString *)message {
    dispatch_async(dispatch_get_main_queue(), ^{
        UIViewController *top = [[UIManager getInstance] topController];
        if (top)
            [MesiboDialogs alert:top title:title message:message];
    });
}

+ (void)shareText:(NSString *)text parent:(UIViewController *)parent {
    if (0 == text.length)
        return;
    UIActivityViewController *a = [[UIActivityViewController alloc] initWithActivityItems:@[text] applicationActivities:nil];
    a.popoverPresentationController.sourceView = parent.view;
    a.popoverPresentationController.sourceRect = CGRectMake(CGRectGetMidX(parent.view.bounds), CGRectGetMidY(parent.view.bounds), 1, 1);
    [parent presentViewController:a animated:YES completion:nil];
}

#pragma mark - theme

+ (int)theme {
    return (int)[NSUserDefaults.standardUserDefaults integerForKey:THEME_KEY];   // 0: MESIBO_THEME_SYSTEM
}

+ (NSString *)themeName {
    switch ([self theme]) {
        case MESIBO_THEME_LIGHT: return @"Light";
        case MESIBO_THEME_DARK: return @"Dark";
        default: return @"System default";
    }
}

+ (void)applyTheme {
    [MesiboUI setTheme:[self theme]];
}

+ (void)chooseTheme:(UIViewController *)parent changed:(dispatch_block_t)changed {
    MesiboDialogOptions *o = [MesiboDialogOptions new];
    o.title = @"Theme";
    o.items = @[@"System default", @"Light", @"Dark"];
    o.sheet = YES;
    o.onSelect = ^(NSInteger which) {
        int theme = 1 == which ? MESIBO_THEME_LIGHT : (2 == which ? MESIBO_THEME_DARK : MESIBO_THEME_SYSTEM);
        if (theme == [UIManager theme])
            return;
        [NSUserDefaults.standardUserDefaults setInteger:theme forKey:THEME_KEY];
        if (changed) changed();
        [MesiboDialogs alert:parent title:@"Theme" message:@"The new theme will be applied when you restart the app."];
    };
    [MesiboDialogs show:parent options:o];
}

@end
