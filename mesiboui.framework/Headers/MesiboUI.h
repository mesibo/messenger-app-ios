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

#ifndef __MESIBOUI_H
#define __MESIBOUI_H
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Mesibo/Mesibo.h"

#define MESIBOUI_TAG_NEWMESSAGE 0x1000

#define USERLIST_MODE_CONTACTS      1
#define USERLIST_MODE_FORWARD       2
#define USERLIST_MODE_GROUPS        3
#define USERLIST_MODE_EDITGROUP     4
#define USERLIST_MODE_MESSAGES      5

#define MESIBO_DEFAULTICON_MESSAGE          @"ic_message_white"
#define MESIBO_DEFAULTICON_AUDIOCALL        @"ic_call_white"
#define MESIBO_DEFAULTICON_VIDEOCALL         @"ic_videocam_white"
#define MESIBO_DEFAULTICON_GROUPAUDIOCALL   @"ic_call_add_white"
#define MESIBO_DEFAULTICON_GROUPVIDEOCALL    @"ic_videocam_add_white"


@interface MesiboScreenOptions : NSObject
@property (assign, nonatomic) long sid;
@property (nonatomic, nullable) id userObject;
@end

@interface MesiboScreen : NSObject
@property (nonatomic, nonnull) UIViewController *parent;
@property (nonatomic, nonnull) UITableView *table;
//@property (nonatomic, nullable) UINavigationController *toolbar;
@property (nonatomic, nullable) NSArray *buttons;
@property (nonatomic, nonnull) UILabel *title;
@property (nonatomic, nonnull) UILabel *subtitle;
@property (nonatomic, nonnull) UIView *titleArea;
@property (nonatomic) BOOL userList;
@property (nonatomic, nonnull) MesiboScreenOptions *options;
-(void) reset;
@end

@interface MesiboUserListScreen : MesiboScreen
@property (nonatomic) int mode;
@property (nonatomic, nonnull) UISearchController *search;
-(void) reset;

@end

@interface MesiboMessageScreenControls : NSObject
@property (nonatomic, nonnull) UITextView *editText;
@property (nonatomic, nonnull) UIButton *cameraButton;
@property (nonatomic, nonnull) UIButton *imageButton;
// _videoButton is not in use in iOS, instead use imageButton to select images and video
//@property (nonatomic, nonnull) UIButton *videoButton;
@property (nonatomic, nonnull) UIButton *audioButton;
@property (nonatomic, nonnull) UIButton *fileButton;
@property (nonatomic, nonnull) UIButton *locationButton;
@property (nonatomic, nonnull) UIButton *attachButton;
@property (nonatomic, nonnull) UIButton *moreButton;
@property (nonatomic, nonnull) UIButton *sendButton;
@end

@interface MesiboMessageScreen : MesiboScreen
@property (nonatomic, nonnull) MesiboProfile *profile;
@property (nonatomic, nonnull) UIButton *profileImage;
@property (nonatomic, nonnull) MesiboMessageScreenControls *controls;

-(void) reset;
@end

@interface MesiboRow : NSObject
@property (nonatomic, nonnull) UITableViewCell *row;
@property (nonatomic, nullable) MesiboMessage *message;
@property (nonatomic, nullable) MesiboScreen *screen;
-(void) reset;
@end

@interface MesiboUserListRow : MesiboRow
@property (nonatomic, nonnull) MesiboProfile *profile;
@property (nonatomic, nonnull) UILabel *name;
@property (nonatomic, nonnull) UILabel *subtitle;
@property (nonatomic, nonnull) UILabel *timestamp;
@property (nonatomic, nonnull) UIImageView *image;
-(void) reset;
@end

@interface MesiboMessageRow : MesiboRow
@property (nonatomic, nonnull) UILabel *title;
@property (nonatomic, nonnull) UILabel *subtitle;
@property (nonatomic, nonnull) UITextView *messageText;
@property (nonatomic, nonnull) UILabel *filename;
@property (nonatomic, nonnull) UILabel *filesize;
@property (nonatomic, nonnull) UILabel *name;
@property (nonatomic, nonnull) UILabel *heading;
@property (nonatomic, nullable) UILabel *footer;
@property (nonatomic, nonnull) UILabel *timestamp;
@property (nonatomic, nonnull) UIImageView *image;
@property (nonatomic, nonnull) UIImageView *status;
@property (nonatomic, nonnull) UIView *replyView;
@property (nonatomic, nonnull) UIView *titleView;
@property (nonatomic) BOOL selected;
-(void) reset;
@end

@interface MesiboOnClickObject : NSObject
@property (nonatomic, nullable) id object;
@property (nonatomic, nullable) MesiboScreen *screen;
-(void) reset;
@end


@interface MesiboCell : UITableViewCell {
    
}
@end



@protocol MesiboUIListener <NSObject>
@required
-(BOOL) MesiboUI_onInitScreen:(MesiboScreen * _Nonnull)screen NS_SWIFT_NAME(MesiboUI_onInitScreen(screen:));

-(BOOL) MesiboUI_onShowScreen:(MesiboScreen * _Nonnull)screen NS_SWIFT_NAME(MesiboUI_onShowScreen(screen:));

/* return height of the cell if creating custom cell - return -1 otherwise*/
-(CGFloat) MesiboUI_onGetCustomRowHeight:(MesiboScreen * _Nonnull)screen row:(MesiboRow * _Nonnull) row NS_SWIFT_NAME(MesiboUI_onGetCustomRowHeight(screen:row:));

/* You can create custom cell and return for message view. UI will pass the cell to Table controller without any modification. You MUST handle MesiboUI_onGetCustomCellHeight as well.
 
   Return nil for default
 */
-(MesiboCell * _Nullable) MesiboUI_onGetCustomRow:(MesiboScreen * _Nonnull)screen row:(MesiboRow * _Nonnull) row NS_SWIFT_NAME(MesiboUI_onGetCustomRow(screen:row:));


/* UI will call this before returning the cell to Table controller.
   - Cast row to MesiboUserListRow or MesiboMessageRow depnding on row.userList
   - Modify the cell as you prefer, for example, colors, background, etc.
   - Ensure that modification does not change height. Hence changing font is not recommended
   - Ensure to check presence status (isTyping, etc) to use appropriate color (especially for user list)
 */
-(BOOL) MesiboUI_onUpdateRow:(MesiboScreen * _Nonnull)screen row:(MesiboRow * _Nonnull) row last:(BOOL)last NS_SWIFT_NAME(MesiboUI_onUpdateRow(screen:row:last:));

-(BOOL) MesiboUI_onClickedRow:(MesiboScreen * _Nonnull)screen row:(MesiboRow * _Nonnull) row  NS_SWIFT_NAME(MesiboUI_onClickedRow(screen:row:));

@end

#define LOCATION_APP_APPLE      0
#define LOCATION_APP_GOOGLEMAP  1
#define LOCATION_APP_PROMPT     2
#define LOCATION_APP_PROMPTONCE 3

@interface MesiboUiDefaults : NSObject
@property (nonatomic, nullable) UIImage *contactPlaceHolder;
@property (nonatomic, nullable) UIImage *messagingBackground;

@property (nonatomic) BOOL useLetterTitleImage;

@property (nonatomic) BOOL enableForward;
@property (nonatomic) BOOL enableEdit;
@property (nonatomic) BOOL enableReply;
@property (nonatomic) BOOL enableSearch;
@property (nonatomic) BOOL enableBackButton;
@property (nonatomic) BOOL enableMessageButton;
@property (nonatomic) BOOL hidesBottomBarWhenPushed;
@property (nonatomic) BOOL alwaysShowSearchBar;
@property (nonatomic) BOOL showRichMessageButtons;


@property (nonatomic) BOOL e2eIndicator;


@property (copy, nonatomic, nonnull) NSString *messageListTitle;
@property (copy, nonatomic, nonnull) NSString *userListTitle;
@property (copy, nonatomic, nonnull) NSString *createGroupTitle;
@property (copy, nonatomic, nonnull) NSString *selectContactTitle;
@property (copy, nonatomic, nonnull) NSString *selectGroupContactsTitle;
@property (copy, nonatomic, nonnull) NSString *forwardTitle;
@property (copy, nonatomic, nonnull) NSString *forwardedTitle;
@property (copy, nonatomic, nonnull) NSString *editTitle;
@property (copy, nonatomic, nonnull) NSString *editedTitle;

@property (copy, nonatomic, nonnull) NSString *userOnlineIndicationTitle;
@property (copy, nonatomic, nullable) NSString *onlineIndicationTitle;
@property (copy, nonatomic, nonnull) NSString *offlineIndicationTitle;
@property (copy, nonatomic, nonnull) NSString *connectingIndicationTitle;
@property (copy, nonatomic, nonnull) NSString *noNetworkIndicationTitle;
@property (copy, nonatomic, nonnull) NSString *suspendedIndicationTitle;

@property (copy, nonatomic, nonnull) NSString *typingIndicationTitle;
@property (copy, nonatomic, nonnull) NSString *joinedIndicationTitle;

@property (copy, nonatomic, nonnull) NSString *groupDeletedTitle;
@property (copy, nonatomic, nonnull) NSString *groupMemberTitle;
@property (copy, nonatomic, nonnull) NSString *groupNotMemberTitle;

@property (copy, nonatomic, nonnull) NSString *e2eeActive;
@property (copy, nonatomic, nonnull) NSString *e2eeIdentityChanged;
@property (copy, nonatomic, nonnull) NSString *e2eeInactive;


@property (copy, nonatomic, nonnull) NSString *emptyUserListMessage;
@property (copy, nonatomic, nonnull) NSString *emptyMessageListMessage;
@property (copy, nonatomic, nonnull) NSString *emptySearchListMessage;
@property (copy, nonatomic, nonnull) UIFont *emptyUserListMessageFont;
@property (assign, nonatomic) int emptyUserListMessageColor;

@property (nonatomic) BOOL showRecentInForward;
@property (nonatomic) BOOL mConvertSmilyToEmoji;

@property (assign, nonatomic, nullable) int *mLetterTitleColors;
@property (assign, nonatomic) uint32_t mToolbarColor;
@property (assign, nonatomic) uint32_t mStatusBarColor;
@property (assign, nonatomic) uint32_t mToolbarTextColor;
@property (assign, nonatomic) uint32_t mUserListTypingIndicationColor;
@property (assign, nonatomic) uint32_t mUserListStatusColor;
@property (assign, nonatomic) uint32_t mUserListMaxRows;
@property (assign, nonatomic) uint32_t userListBackgroundColor;
@property (assign, nonatomic) uint32_t messageBackgroundColorForMe;
@property (assign, nonatomic) uint32_t messageBackgroundColorForPeer;
@property (assign, nonatomic) uint32_t titleBackgroundColorForMe;
@property (assign, nonatomic) uint32_t titleBackgroundColorForPeer;
@property (assign, nonatomic) uint32_t messagingBackgroundColor;
@property (assign, nonatomic) uint32_t messageInputBackgroundColor;
@property (assign, nonatomic) uint32_t messageInputButtonsColor;
@property (assign, nonatomic) uint32_t messageInputBorderColor;
@property (assign, nonatomic) uint32_t messageInputTextColor;
@property (assign, nonatomic) uint32_t messageInputTextBackgroundColor;
@property (assign, nonatomic) int messageInputTextCornerRadiusRatio;


@property (assign, nonatomic) uint32_t customTextColor;
@property (assign, nonatomic) uint32_t customBackgroundColor;
@property (assign, nonatomic) uint32_t e2eeBackgroundColor;

@property (assign, nonatomic) uint32_t dateTextColor;
@property (assign, nonatomic) uint32_t dateBackgroundColor;

@property (assign, nonatomic) uint32_t titleTextColor;
@property (copy, nonatomic, nonnull) UIFont *titleFont;
@property (copy, nonatomic, nonnull) UIFont *subtitleFont;
@property (copy, nonatomic, nonnull) UIFont *messageFont;
@property (copy, nonatomic, nonnull) UIFont *customFont;
@property (copy, nonatomic, nonnull) UIFont *dateFont;

@property (copy, nonatomic, nonnull) UIFont *headingFont;
@property (assign, nonatomic) uint32_t headingTextColor;

@property (assign, nonatomic) uint32_t timeTextColor;

@property (assign, nonatomic) uint32_t messageTextColor;
@property (assign, nonatomic) uint32_t messageDeletedTextColor;
@property (assign, nonatomic) uint32_t messagePictureTextColor;
@property (assign, nonatomic) uint32_t messageReplyTextColor;

@property (assign, nonatomic) uint32_t clearButtonColor;
@property (assign, nonatomic) uint32_t deleteButtonColor;
@property (assign, nonatomic) uint32_t unreadButtonColor;

@property (assign, nonatomic) uint32_t messageViewWidth;

@property (assign, nonatomic) int mediaButtonPosition;
@property (assign, nonatomic) int locationButtonPosition;
@property (assign, nonatomic) int docButtonPosition;
@property (assign, nonatomic) int audioButtonPosition;

@property (assign, nonatomic) int preferredLocationApp;

@property (assign, nonatomic) uint64_t mMaxImageFileSize;
@property (assign, nonatomic) uint64_t mMaxVideoFileSize;

@property (assign, nonatomic) BOOL mEnableNotificationBadge;

@property (copy, nonatomic, nonnull) NSString *recentUsersTitle;
@property (copy, nonatomic, nonnull) NSString *allUsersTitle;
@property (copy, nonatomic, nonnull) NSString *groupMembersTitle;

@property (nonatomic) BOOL showMonthFirst;
@property (copy, nonatomic, nonnull) NSString *today;
@property (copy, nonatomic, nonnull) NSString *yesterday;
@property (copy, nonatomic, nonnull) NSString *at;

@property (copy, nonatomic, nonnull) NSString *you;

@property (copy, nonatomic, nonnull) NSString *shareMediaTitle;
@property (copy, nonatomic, nonnull) NSString *shareMediaSubTitle;
@property (copy, nonatomic, nonnull) NSString *shareMediaCameraTitle;
@property (copy, nonatomic, nonnull) NSString *shareMediaGalleryTitle;
@property (copy, nonatomic, nonnull) NSString *shareMediaAudioTitle;
@property (copy, nonatomic, nonnull) NSString *shareMediaLocationTitle;
@property (copy, nonatomic, nonnull) NSString *shareMediaDocumentTitle;
@property (copy, nonatomic, nonnull) NSString *cancelTitle;

@property (copy, nonatomic, nonnull) NSString *missedVoiceCallTitle;
@property (copy, nonatomic, nonnull) NSString *missedVideoCallTitle;
@property (copy, nonatomic, nonnull) NSString *deletedMessageTitle;

@property (copy, nonatomic, nonnull) NSString *deleteMessagesTitle;
@property (copy, nonatomic, nonnull) NSString *deleteForEveryoneTitle;
@property (copy, nonatomic, nonnull) NSString *deleteForMeTitle;
@property (copy, nonatomic, nonnull) NSString *deleteTitle;
@property (copy, nonatomic, nonnull) NSString *deleteAlertTitle;
@property (copy, nonatomic, nonnull) NSString *unreadTitle;
@property (copy, nonatomic, nonnull) NSString *clearMessagesTitle;
@property (copy, nonatomic, nonnull) NSString *clearTitle;
@property (copy, nonatomic, nonnull) NSString *clearAlertTitle;

@property (assign, nonatomic) int clearMessageMode;
@property (assign, nonatomic) BOOL clearedMessageContactTimestamp;


@property (assign, nonatomic) int verticalImageWidth;
@property (assign, nonatomic) int horizontalImageWidth;

@property (nonatomic) BOOL showAddressInProfileView;
@property (nonatomic) BOOL showAddressAsPhoneInProfileView;
@property (nonatomic) BOOL showLastSeenInProfileView;
@property (nonatomic) BOOL showGroupMembersInProfileView;

@property (assign, nonatomic) UITableViewCellAccessoryType userListCellAccessoryType;

@end

@interface MesiboUserListScreenOptions : MesiboScreenOptions
@property (assign, nonatomic) int mode;
//@property (assign, nonatomic) BOOL startInBackground;
//@property (assign, nonatomic) BOOL keepRunning;
@property (assign, nullable) NSArray *forwardIds;
//@property (assign, nonatomic) BOOL forwardAndClose;
//@property (copy, nonatomic, nullable) NSString *forwardedMessage;
@property (assign, nonatomic) uint32_t groupid;
//@property (copy, nonatomic, nullable) NSString *readQuery;
//@property (copy, nonatomic, nullable) NSString *searchQuery;
@property (assign, nonatomic, nullable) id<MesiboUIListener> listener;
@property (assign, nonatomic, nullable) id<MesiboUIListener> mlistener;
@end

@interface MesiboMessageScreenOptions : MesiboScreenOptions
@property (assign, nonatomic, nullable) MesiboProfile *profile;
@property (assign, nonatomic, nullable) id<MesiboUIListener> listener;
@property (assign, nonatomic, nullable) id<MesiboUIListener> ulistener;
@property (assign, nonatomic) BOOL navigation;
@end

@interface MesiboUI : NSObject
+(void) setListener:(id<MesiboUIListener> _Nullable) delegate;
+(nullable id<MesiboUIListener>) getListener;

+(MesiboScreen * _Nullable) getParentScreen:(id _Nonnull)view NS_SWIFT_NAME(getParentScreen(_:));

+(MesiboUiDefaults * _Nonnull) getUiDefaults NS_SWIFT_NAME(getUiDefaults());
+(BOOL) addTarget:(id _Nonnull)parent screen:(MesiboScreen * _Nonnull)screen view:(id _Nonnull)view action:(SEL _Nonnull)action;

+(UIViewController * _Nullable) getUserListViewController:(MesiboUserListScreenOptions * _Nonnull)opts;
+(UIViewController * _Nullable) getMessageViewController:(MesiboMessageScreenOptions * _Nonnull)opts;
+(UIViewController * _Nullable) getE2EViewController:(MesiboProfile * _Nullable)profile ;

/* depreciated functions. We suggest to use getUserListViewController or getMessageViewController and launch it yourself */
+(void) launchUserList:(UIViewController * _Nonnull)parent opts:(MesiboUserListScreenOptions * _Nonnull) opts __deprecated_msg("Use getUserListViewController instead.");
+(void) launchMessaging:(UIViewController * _Nonnull) parent opts:(MesiboMessageScreenOptions * _Nonnull) opts __deprecated_msg("Use getMessageViewController instead.");

+(void) launchEditGroupDetails:(id _Nonnull)parent groupid:(uint32_t) groupid;
+(void) showEndToEncEncryptionInfo:(UIViewController * _Nonnull) parent profile:(MesiboProfile* _Nonnull)profile;
+(void) showBasicProfileInfo:(id _Nonnull)parent profile:(MesiboProfile * _Nonnull)profile;

+(NSBundle * _Nonnull) getMesiboUIBumble;
+(UIImage * _Nullable) getDefaultImage:(BOOL) group;
+(UIImage * _Nullable) imageNamed:(NSString * _Nonnull)imageName color:(uint32_t)color;
+(UIImage * _Nullable) imageNamed:(NSString * _Nonnull)imageName;
@end


#endif
