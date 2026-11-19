//
//  UIListener.m
//  MesiboApplication
//

#import "UIListener.h"
#import "UIManager.h"
#import "SampleAPI.h"
#import "BackupRestore.h"
#import <objc/runtime.h>

@implementation UIListener

- (instancetype)init {
    if ((self = [super init]))
        [MesiboUI setListener:self];
    return self;
}

/** each new configuration of the messaging UI (a theme applied): the app's own settings */
- (void)MesiboUI_onConfig:(MesiboUiConfig *)config dark:(BOOL)dark {
    config.userList.emptyMessage = @"No messages! Click on the message icon below to start messaging!";
    config.profileViewer.showAddress = YES;
}

- (BOOL)MesiboUI_onInitScreen:(MesiboScreen *)screen {
    if (MESIBO_SCREEN_USERLIST == screen.type) {
        MesiboUserListScreen *us = (MesiboUserListScreen *)screen;
        if (MESIBO_MODE_MESSAGES == us.mode) {
            [self initUserListScreen:us];
            [self updateCallButtons:screen];
        }
    } else if (MESIBO_SCREEN_MESSAGES == screen.type) {
        [self initMessageScreen:(MesiboMessageScreen *)screen];
    } else if (MESIBO_SCREEN_PROFILE == screen.type) {
        // the buttons under the name
        [((MesiboProfileScreen *)screen).actions addObjectsFromArray:[self callItems:screen]];
    } else if (MESIBO_SCREEN_PROFILE_POPUP == screen.type) {
        // the popup's buttons, between Message and Info
        [screen.menu addObjectsFromArray:[self callItems:screen]];
    }
    return NO;
}

/**
 * Voice and video call buttons, for the profile screen and the profile popup (none for a group
 * the user left). During a call, they bring it back.
 */
- (NSArray<MesiboMenuItem *> *)callItems:(MesiboScreen *)screen {
    MesiboProfile *profile = screen.profile;
    if (nil == profile || ([profile isGroup] && ![profile isActive]))
        return @[];

    NSMutableArray<MesiboMenuItem *> *items = [NSMutableArray array];
    __weak MesiboScreen *s = screen;
    for (NSNumber *video in @[@NO, @YES]) {
        BOOL isVideo = video.boolValue;
        [items addObject:[MesiboMenuItem itemWithTitle:isVideo ? @"Video" : @"Voice"
                                                 image:[UIImage systemImageNamed:isVideo ? @"video.fill" : @"phone.fill"]
                                            identifier:isVideo ? @"videocall" : @"voicecall"
                                               handler:^(MesiboMenuItem *item) {
            if (nil == s.parent || nil == s.profile)
                return;

            // during a call: back to it
            if ([MesiboCallInstance isAnyCallInProgress]) {
                [MesiboCallInstance showCallInProgress:s.parent];
                return;
            }
            [MesiboCallInstance callUi:s.parent profile:s.profile video:isVideo];
        }]];
    }
    return items;
}

/** the chat list's "more" menu */
- (void)initUserListScreen:(MesiboUserListScreen *)screen {
    __weak MesiboUserListScreen *s = screen;
    [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"Conference" image:[UIImage systemImageNamed:@"person.3"] identifier:@"conf"
                                                 handler:^(MesiboMenuItem *item) {
        if (s.parent) [MesiboCallInstance groupCallJoinRoomUi:s.parent title:@"Mesibo Conferencing Demo"];
    }]];
    [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"End-to-end encryption" image:[UIImage systemImageNamed:@"lock"] identifier:@"e2ee"
                                                 handler:^(MesiboMenuItem *item) {
        if (s.parent) [MesiboUI showEndToEndEncryptionInfo:s.parent profile:nil];
    }]];
    [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"Call Logs" image:[UIImage systemImageNamed:@"phone.arrow.up.right"] identifier:@"calllogs"
                                                 handler:^(MesiboMenuItem *item) {
        if (s.parent) [MesiboCallInstance launchCallLogs:s.parent];
    }]];
    [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"Backup & Restore" image:[UIImage systemImageNamed:@"externaldrive"] identifier:@"backup"
                                                 handler:^(MesiboMenuItem *item) {
        if (s.parent) [BackupRestore show:s.parent];
    }]];
    [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"Invite" image:[UIImage systemImageNamed:@"square.and.arrow.up"] identifier:@"share"
                                                 handler:^(MesiboMenuItem *item) {
        if (s.parent) [UIManager shareText:[SampleAPIInstance getInvite] ?: @"" parent:s.parent];
    }]];
    [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"Customize" image:[UIImage systemImageNamed:@"paintpalette"] identifier:@"customize"
                                                 handler:^(MesiboMenuItem *item) {
        if (s.parent) [[UIManager getInstance] launchCustomize:s.parent];
    }]];
    [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"Settings" image:[UIImage systemImageNamed:@"gearshape"] identifier:@"settings"
                                                 handler:^(MesiboMenuItem *item) {
        if (s.parent) [[UIManager getInstance] launchSettings:s.parent];
    }]];
}

#define CALLBUTTON_INPROGRESS   9001
#define CALLBUTTON_VIDEO        9002
#define CALLBUTTON_VOICE        9003

/** a call started or ended (CallListeners -> MesiboUI updateScreens) */
- (void)MesiboUI_onUpdateScreen:(MesiboScreen *)screen {
    [self updateCallButtons:screen];
}

- (UIBarButtonItem *)callButton:(NSString *)symbol tag:(NSInteger)tag label:(NSString *)label screen:(MesiboScreen *)screen {
    UIBarButtonItem *b = [[UIBarButtonItem alloc] initWithImage:[UIImage systemImageNamed:symbol] style:UIBarButtonItemStylePlain
                                                         target:self action:@selector(onCallButton:)];
    b.tag = tag;
    b.accessibilityLabel = label;
    // the screen for the action
    objc_setAssociatedObject(b, @selector(onCallButton:), screen, OBJC_ASSOCIATION_ASSIGN);
    return b;
}

/** during a call: the call in progress button instead of the voice / video call buttons */
- (void)updateCallButtons:(MesiboScreen *)screen {
    NSIndexSet *ours = [screen.buttons indexesOfObjectsPassingTest:^BOOL(UIBarButtonItem *b, NSUInteger i, BOOL *stop) {
        return b.tag >= CALLBUTTON_INPROGRESS && b.tag <= CALLBUTTON_VOICE;
    }];
    [screen.buttons removeObjectsAtIndexes:ours];

    if ([MesiboCallInstance isAnyCallInProgress]) {
        UIBarButtonItem *b = [self callButton:@"phone.connection" tag:CALLBUTTON_INPROGRESS label:@"Call in progress" screen:screen];
        b.tintColor = UIColor.systemGreenColor;
        [screen.buttons insertObject:b atIndex:0];
        return;
    }

    // voice and video call buttons in chats (not for groups the user left)
    if (MESIBO_SCREEN_MESSAGES != screen.type)
        return;
    MesiboProfile *profile = screen.profile;
    if (nil == profile || ([profile isGroup] && ![profile isActive]))
        return;
    // group calls: the same icons with a "+" badge (video.badge.plus, phone.badge.plus)
    BOOL group = [profile isGroup];
    [screen.buttons addObject:[self callButton:group ? @"video.badge.plus" : @"video" tag:CALLBUTTON_VIDEO
                                         label:group ? @"Group video call" : @"Video call" screen:screen]];
    [screen.buttons addObject:[self callButton:group ? @"phone.badge.plus" : @"phone" tag:CALLBUTTON_VOICE
                                         label:group ? @"Group voice call" : @"Voice call" screen:screen]];
}

- (void)initMessageScreen:(MesiboMessageScreen *)screen {
    // the chat's "more" menu: end-to-end encryption of this chat, only while
    // end-to-end encryption is on (when off, the screen would only say the chat isn't
    // end-to-end encrypted), and not for groups
    __weak MesiboMessageScreen *s = screen;
    if ([[[Mesibo getInstance] e2ee] isEnabled] && ![screen.profile isGroup]) {
        [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"End-to-end encryption" image:[UIImage systemImageNamed:@"lock.shield"] identifier:@"e2ee"
                                                     handler:^(MesiboMenuItem *item) {
            if (s.parent && s.profile)
                [MesiboUI showEndToEndEncryptionInfo:s.parent profile:s.profile];
        }]];
    }

    // disappearing messages of this chat: how long the messages this user sends live
    [screen.menu addObject:[MesiboMenuItem itemWithTitle:@"Disappearing messages" image:[UIImage systemImageNamed:@"timer"] identifier:@"disappearing"
                                                 handler:^(MesiboMenuItem *item) {
        if (s.parent && s.profile) [MesiboUI launchDisappearingMessages:s.parent profile:s.profile];
    }]];
    [self updateCallButtons:screen];
}

/** during a call, callUi brings back the call in progress instead */
- (void)onCallButton:(UIBarButtonItem *)sender {
    MesiboScreen *screen = objc_getAssociatedObject(sender, @selector(onCallButton:));
    if (nil == screen.parent)
        return;
    if (CALLBUTTON_INPROGRESS == sender.tag) {
        [MesiboCallInstance showCallInProgress:screen.parent];
        return;
    }
    if (nil == screen.profile)
        return;
    [MesiboCallInstance callUi:screen.parent profile:screen.profile video:(CALLBUTTON_VIDEO == sender.tag)];
}

@end
