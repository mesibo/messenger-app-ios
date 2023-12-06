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

#pragma once

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Mesibo/Mesibo.h"

#define MESIBOCALL_NOTIFY_INCOMING  0
#define MESIBOCALL_NOTIFY_MISSED    4

#define MESIBOCALL_VIDEO_FIT_ZOOM        0
#define MESIBOCALL_VIDEO_FIT_LETTERBOX   1

#define MESIBOCALL_UI_STATE_SHOWINCOMING         1
#define MESIBOCALL_UI_STATE_SHOWINPROGRESS       2
#define MESIBOCALL_UI_STATE_SHOWCONTROLS         3

#define MESIBOCALL_HANGUP_REASON_USER       1
#define MESIBOCALL_HANGUP_REASON_REMOTE     2
#define MESIBOCALL_HANGUP_REASON_ERROR      3
#define MESIBOCALL_HANGUP_REASON_BACKGROUND      4

#define MESIBOCALL_CODEC_VP8           1
#define MESIBOCALL_CODEC_VP9           2
#define MESIBOCALL_CODEC_H264          4
#define MESIBOCALL_CODEC_H265          8
#define MESIBOCALL_CODEC_OPUS       0x100

#define MESIBOCALL_VIDEOSOURCE_CAMERADEFAULT        0
#define MESIBOCALL_VIDEOSOURCE_CAMERAFRONT          1
#define MESIBOCALL_VIDEOSOURCE_CAMERAREAR           2
#define MESIBOCALL_VIDEOSOURCE_SCREEN               4

#define MESIBO_CALLSTATUS_NONE                  0x00
#define MESIBO_CALLSTATUS_INCOMING         0x01
#define MESIBO_CALLSTATUS_INPROGRESS            0x02
#define MESIBO_CALLSTATUS_RINGING               0x03
#define MESIBO_CALLSTATUS_ANSWER                0x05
#define MESIBO_CALLSTATUS_UPDATE                0x06
#define MESIBO_CALLSTATUS_DTMF                  0x07
#define MESIBO_CALLSTATUS_SDP                   0x08
#define MESIBO_CALLSTATUS_MUTE                  0x09
#define MESIBO_CALLSTATUS_UNMUTE                0x0A
#define MESIBO_CALLSTATUS_HOLD                  0x0B
#define MESIBO_CALLSTATUS_UNHOLD                0x0C

#define MESIBO_CALLSTATUS_CONNECTED             0x30
#define MESIBO_CALLSTATUS_RECONNECTING          0x32

#define MESIBO_CALLSTATUS_COMPLETE              0x40
#define MESIBO_CALLSTATUS_CANCEL                0x41
#define MESIBO_CALLSTATUS_NOANSWER              0x42
#define MESIBO_CALLSTATUS_BUSY                  0x43
#define MESIBO_CALLSTATUS_UNREACHABLE           0x44
#define MESIBO_CALLSTATUS_OFFLINE               0x45
#define MESIBO_CALLSTATUS_INVALIDDEST           0x46
#define MESIBO_CALLSTATUS_INVALIDSTATE          0x47
#define MESIBO_CALLSTATUS_NOCALLS               0x48
#define MESIBO_CALLSTATUS_NOVIDEOCALLS          0x49
#define MESIBO_CALLSTATUS_NOTALLOWED            0x4A
#define MESIBO_CALLSTATUS_BLOCKED               0x4B
#define MESIBO_CALLSTATUS_DURATIONEXCEEDED      0x4C
#define MESIBO_CALLSTATUS_SWITCHED              0x4D

// Generic Errors
#define MESIBO_CALLSTATUS_ERROR                 0x60
#define MESIBO_CALLSTATUS_HWERROR               0x61
#define MESIBO_CALLSTATUS_NETWORKERROR          0x62
#define MESIBO_CALLSTATUS_NETWORKBLOCKED        0x63


//forward declaration
//@protocol MesiboCallInProgressListener;

@interface MesiboCallNotification : NSObject
@property (nonatomic) BOOL enabled;
@property (nonatomic) NSString * _Nullable title;
@property (nonatomic) NSString * _Nullable message;
@property (nonatomic) NSString * _Nullable answer;
@property (nonatomic) NSString * _Nullable answerCallWaiting;
@property (nonatomic) NSString * _Nullable hangup;
@property (nonatomic) NSString * _Nullable silentJoin;
@property (nonatomic) BOOL vibrate;
@property (nonatomic) BOOL sound;
@property (nonatomic) int color;
@property (nonatomic) int duration;
@property (nonatomic) NSURL * _Nullable soundFileUrl;
- (id _Nonnull)initWith:(BOOL)video group:(BOOL)group;
@end

@interface MesiboVideoProperties : NSObject
@property (nonatomic) BOOL enabled;
@property (nonatomic) BOOL sendVideo;
@property (nonatomic) BOOL receiveVideo;
@property (nonatomic) int width;
@property (nonatomic) int height;
@property (nonatomic) int fps;
@property (nonatomic) int bitrate; //kbps
@property (nonatomic) int quality;
@property (nonatomic) int codec;
@property (nonatomic) int source;
@property (nonatomic) float zoom;
@property (nonatomic) BOOL fitZoom;
@property (nonatomic) BOOL hardwareAcceleration;
@property (nonatomic) NSString * _Nullable fileName;
@end

@interface MesiboAudioProperties : NSObject
@property (nonatomic) BOOL enabled;
@property (nonatomic) BOOL sendAudio;
@property (nonatomic) BOOL receiveAudio;
@property (nonatomic) int bitrate; //kbps
@property (nonatomic) int quality;
@property (nonatomic) int codec;
@property (nonatomic) BOOL speaker;
@property (nonatomic) BOOL disableEarpiece;
@end

@interface MesiboCallUiProperties : NSObject
@property (nonatomic) NSString * _Nullable title;
@property (nonatomic) UIImage * _Nullable userImage;
@property (nonatomic) UIImage * _Nullable userImageSmall;
@property (nonatomic) uint32_t backgroundColor;
@property (nonatomic) BOOL showScreenSharing;
@property (nonatomic) BOOL autoHideControls;
@property (nonatomic) BOOL autoSwapVideoViews;
@property (nonatomic) BOOL useMetalKit;
@property (nonatomic) id _Nullable inProgressListener; // only a few listeners will be invoked
@property (nonatomic) NSString * _Nullable callStatusText;

@end

@interface MesiboIceServer : NSObject
@property (nonatomic) int type;
@property (nonatomic) NSMutableArray * _Nullable urls;
@property (nonatomic) NSString * _Nullable username;
@property (nonatomic) NSString * _Nullable credential;
@end

@interface MesiboCallProperties : NSObject

@property (nonatomic, weak) id _Nullable parent;
@property (nonatomic, weak) id _Nullable controller;
@property (nonatomic) MesiboProfile * _Nullable user;
@property (nonatomic) MesiboProfile * _Nullable groupProfile;



@property (nonatomic) MesiboVideoProperties * _Nullable video;
@property (nonatomic) MesiboAudioProperties * _Nullable audio;
@property (nonatomic) MesiboVideoProperties * _Nullable record;

@property (nonatomic) MesiboCallUiProperties * _Nullable ui;
@property (nonatomic) MesiboCallNotification * _Nullable notify;
@property (nonatomic) id _Nullable other;

@property (nonatomic) int batteryLowThreshold; // 0 to disable

@property (nonatomic) BOOL hangup;
@property (nonatomic) BOOL autoAnswer;
@property (nonatomic) BOOL autoDetectAppState;
@property (nonatomic) BOOL disableSpeakerOnProximity;
@property (nonatomic) BOOL hideOnProximity;
@property (nonatomic) BOOL runInBackground;
@property (nonatomic) BOOL stopVideoInBackground;
@property (nonatomic) BOOL holdOnCellularIncoming;
@property (nonatomic) BOOL checkNetworkConnection;

@property (nonatomic) NSMutableArray * _Nullable iceServers;

@property (nonatomic) BOOL enableCallKit; // requires CallKit to be enabled first

@property (nonatomic) BOOL incoming;
@property (nonatomic) BOOL waiting;

@property (nonatomic) uint32_t callid;



-(void) reset:(BOOL)videoEnabled group:(BOOL)group waiting:(BOOL)waiting;
-(id _Nonnull )initWith:(BOOL)video group:(BOOL)group;
-(id _Nonnull )initWith:(BOOL)video group:(BOOL)group waiting:(BOOL)waiting;
@end

@interface MesiboVideoView : UIView

-(void) enableHardwareScaler:(BOOL) enable;
-(void) enableOverlay:(BOOL) enable;
-(void) enablePip:(BOOL) enable;
-(void) enableMirror:(BOOL) enable;
-(void) scaleToFit:(BOOL) enable;
-(void) scaleToFill:(BOOL) enable;
-(void) zoom:(float)zoom;
-(BOOL) fitLetterBox:(CGRect)bounds;
-(BOOL) fitZoom:(CGRect)bounds;
-(BOOL) position:(int)size aspect:(float)aspect xpadding:(int)xpadding ypadding:(int)ypadding bounds:(CGRect)bounds;

@end

//

@class MesiboCallApi;
@class MesiboCallInProgressListener;
@class MesiboCallIncomingListener;

@protocol MesiboCallIncomingListener
-(MesiboCallProperties * _Nullable) MesiboCall_OnIncoming:(MesiboProfile *_Nonnull)profile video:(BOOL)video waiting:(BOOL)waiting NS_SWIFT_NAME(MesiboCall_OnIncoming(profile:video:waiting:));
-(BOOL) MesiboCall_OnShowUserInterface:(id _Nullable )call properties:(MesiboCallProperties *_Nullable)cp NS_SWIFT_NAME(MesiboCall_OnShowUserInterface(call:properties:));
-(BOOL) MesiboCall_OnNotify:(int)type profile:(MesiboProfile *_Nonnull)profile video:(BOOL)video NS_SWIFT_NAME(MesiboCall_OnNotify(type:profile:video:));
-(void) MesiboCall_OnError:(MesiboCallProperties*_Nonnull)cp error:(int) error NS_SWIFT_NAME(MesiboCall_OnError(cp:error:));
@end

@interface MesiboCallApi : NSObject

-(void)setListener:(_Nullable id)listener;
-(MesiboCallProperties *_Nullable) getCallProperties;

-(void) start:(_Nullable id) controller listner:(_Nullable id) listener;
-(void) answer:(BOOL) video;
//-(void) answer;
-(void) sendDTMF:(int) digit;
-(void) hangup;

-(void) switchCamera;
-(void) switchSource;
-(void) changeVideoFormat:(int)width height:(int)height framerate:(int)framerate;
-(void) setVideoSource:(int)source index:(int)index;
-(int) getVideoSource;

-(void) mute:(BOOL)audio video:(BOOL)video enabled:(BOOL)enabled;
-(BOOL) toggleAudioMute;
-(BOOL) toggleVideoMute;

-(void) setAudioDevice:(int) device enable:(BOOL) enable;
-(int) getActiveAudioDevice;
-(BOOL) toggleAudioDevice:(int)device;

-(void) setVideoView:(MesiboVideoView *_Nullable) v remote:(BOOL)remote;
-(MesiboVideoView *_Nullable) getVideoView:(BOOL)remote;
-(void) setVideoViewsSwapped:(BOOL)swapped;
-(BOOL) isVideoViewsSwapped;

-(uint64_t) getAnswerTime;
-(BOOL) isVideoCall;
-(BOOL) isIncoming;
-(BOOL) isCallInProgress;
-(BOOL) isLinkUp;
-(BOOL) isCallConnected;
-(BOOL) isAnswered;
-(BOOL) getMuteStatus:(BOOL)audio video:(BOOL)video remote:(BOOL)remote;

-(void) playInCallSound:(NSURL * _Nullable)url volume:(float)volume loops:(int)loops;
-(void) stopInCallSound;

@end


enum MesiboAudioDevice {MESIBO_AUDIODEVICE_SPEAKER, MESIBO_AUDIODEVICE_HEADSET, MESIBO_AUDIODEVICE_EARPIECE, MESIBO_AUDIODEVICE_BLUETOOTH, MESIBO_AUDIODEVICE_DEFAULT};

#define MESIBOCALL_SOUND_RINGING    0
#define MESIBOCALL_SOUND_BUSY       1

#define MESIBOCALL_ERROR_BUSY 1
#define MESIBOCALL_ERROR_NETWORK 2

#define MESIBOCALL_HANGUP_REASON_USER      1
#define MESIBOCALL_HANGUP_REASON_REMOTE    2
#define MESIBOCALL_HANGUP_REASON_ERROR     3
#define MESIBOCALL_HANGUP_REASON_BACKGROUND     4
#define MESIBOCALL_HANGUP_REASON_DURATION     5


#define MESIBOCALL_UI_STATE_SHOWINCOMING        1
#define MESIBOCALL_UI_STATE_SHOWINPROGRESS      2
#define MESIBOCALL_UI_STATE_SHOWCONTROLS        3
#define MESIBOCALL_UI_STATE_ANSWERED            4


@protocol MesiboCallInProgressListener

@required
-(void) MesiboCall_OnSetCall:(id _Nonnull )controller call:(id _Nullable )call;
-(void) MesiboCall_OnMute:(MesiboCallProperties * _Nonnull)cp audio:(BOOL)audio video:(BOOL) video remote:(BOOL)remote;
-(BOOL) MesiboCall_OnPlayInCallSound:(MesiboCallProperties * _Nonnull)cp type:(int)type play:(BOOL) play;
-(void) MesiboCall_OnHangup:(MesiboCallProperties * _Nonnull)cp reason:(int)reason;
-(void) MesiboCall_OnStatus:(MesiboCallProperties * _Nonnull)cp status:(int) status video:(BOOL)video waiting:(BOOL)waiting;
-(void) MesiboCall_OnAudioDeviceChanged:(MesiboCallProperties * _Nonnull)cp active:(int)active inactive:(int)inactive;
-(void) MesiboCall_OnVideoSourceChanged:(MesiboCallProperties * _Nonnull)cp source:(int)source index:(int) index;
-(void) MesiboCall_OnVideo:(MesiboCallProperties * _Nonnull)cp video:(MesiboVideoProperties * _Nonnull)video remote:(BOOL)remote;
-(void) MesiboCall_OnUpdateUserInterface:(MesiboCallProperties * _Nonnull)cp state:(int)state video:(BOOL)video enable:(BOOL)enable;
-(void) MesiboCall_OnOrientationChanged:(MesiboCallProperties * _Nonnull)cp landscape:(BOOL)landscape remote:(BOOL)remote;
-(void) MesiboCall_OnBatteryStatus:(MesiboCallProperties * _Nonnull)cp lowBattery:(BOOL)low remote:(BOOL)remote;
-(void) MesiboCall_OnDTMF:(MesiboCallProperties * _Nonnull)cp digit:(int)digit;
@optional

@end

@class MesiboParticipant;
@class MesiboGroupCall;
@class MesiboGroupCallIncomingListener;

#define MesiboCallInstance [MesiboCall getInstance]

typedef void (^MesiboPermissionBlock)(BOOL granted, BOOL existing);

@protocol MesiboGroupCallIncomingListener
-(MesiboCallProperties * _Nullable) MesiboGroupcall_OnIncoming:(MesiboProfile * _Nonnull)groupProfile profile:(MesiboProfile * _Nonnull)profile active:(BOOL)active;
@end

@interface MesiboCall : NSObject

+ (MesiboCall* _Nonnull) getInstance;
+ (id _Nonnull) startWith:(_Nullable id<MesiboCallIncomingListener>)listner name:(NSString * _Nullable)appName icon:(UIImage * _Nullable)icon callKit:(BOOL)enabled;
+ (id _Nonnull) startWith:(_Nullable id<MesiboCallIncomingListener>)listner name:(NSString * _Nonnull)appName icon:(UIImage * _Nullable)icon callKit:(BOOL)enabled recentLogs:(BOOL) recentLogs;
+(void) testRing;

-(MesiboCallApi *_Nullable) getActiveCall;
-(NSBundle * _Nullable) getResourceBundle;

-(void) setListener:(_Nonnull id<MesiboCallIncomingListener>) delegate;
-(void) setGroupCallListener:(_Nonnull id<MesiboGroupCallIncomingListener>) delegate;
-(void) start;
-(MesiboCallApi * _Nullable)call:(MesiboCallProperties * _Nonnull)cc;

-(BOOL) callUi:(MesiboCallProperties * _Nonnull)cc;
-(BOOL) callUi:(id _Nonnull)parent profile:(MesiboProfile * _Nonnull)profile video:(BOOL)video;
-(BOOL) callUi:(id _Nonnull)parent profile:(MesiboProfile * _Nonnull)profile video:(BOOL)video audio:(BOOL)audio videoMute:(BOOL)videoMute audioMute:(BOOL)audioMute;
-(BOOL) callUiForExistingCall:(id _Nonnull)parent;

-(MesiboCallProperties * _Nonnull) createCallProperties:(BOOL)video;
-(MesiboCallProperties * _Nonnull) createGroupCallProperties:(BOOL)video;

-(BOOL) isAppInBackground;
-(BOOL) isCallKitAllowed; 
-(BOOL) enableCallKit:(BOOL)detectRegulatoryRestrictions icon:(UIImage *_Nonnull)icon;
-(BOOL) enableCallKit:(BOOL)detectRegulatoryRestrictions icon:(UIImage *_Nonnull)icon recentLogs:(BOOL) recentLogs;
-(void) enablePushKit:(BOOL) enable; // mandatory call
-(void) enableCallWaiting:(BOOL)enable;

+(UIImage * _Nullable) getImage:(NSBundle * _Nonnull)bundle name:(NSString * _Nonnull)name;
+(UIImage * _Nullable) getColoredImage:(NSBundle * _Nonnull)bundle name:(NSString * _Nonnull)name color:(UIColor * _Nullable)color;

+(BOOL) checkPermissions:(BOOL)video handler:(MesiboPermissionBlock _Nonnull) handler;

-(void) setDefaultPicture:(UIImage * _Nonnull) image;
-(UIImage * _Nullable) getDefaultPicture;
-(UIImage * _Nullable) getDefaultThumbnail;

-(void) setDefaultUiParent:(id _Nonnull)parent;
-(void) setDefaultUiProperties:(MesiboCallUiProperties * _Nullable)properties;
-(MesiboCallUiProperties * _Nullable)getDefaultUiProperties;
-(void) setDefaultUiTitle:(NSString * _Nonnull)name;
-(NSString * _Nonnull) getDefaultUiTitle;

-(MesiboGroupCall * _Nullable) getActiveGroupCall;
-(MesiboGroupCall * _Nullable) groupCall:(id _Nonnull)controller groupid:(uint32_t) groupid;

-(BOOL) groupCallJoinRoomUi:(id _Nonnull)parent;
-(BOOL) groupCallUi:(id _Nonnull)parent profile:(MesiboProfile * _Nonnull)profile video:(BOOL)video audio:(BOOL)audio videoMute:(BOOL)videoMute audioMute:(BOOL)audioMute publish:(BOOL)publish;

-(void) notify:(MesiboCallProperties * _Nonnull)cp;
@end




@protocol MesiboGroupCallAdminListener
-(BOOL) MesiboGroupcallAdmin_OnStartPublishing:(MesiboProfile * _Nonnull)requester isAdmin:(BOOL)isAdmin sid:(uint32_t)sid audio:(BOOL)audio video:(BOOL)video source:(uint32_t)source index:(uint16_t)sindex;
-(BOOL) MesiboGroupcallAdmin_OnStopPublishing:(MesiboProfile * _Nonnull)requester isAdmin:(BOOL)isAdmin participant:(MesiboParticipant * _Nonnull)participant;
-(BOOL) MesiboGroupcallAdmin_OnSubscribe:(MesiboProfile * _Nonnull)requester isAdmin:(BOOL)isAdmin participant:(MesiboParticipant * _Nonnull)participant audio:(BOOL)audio video:(BOOL)video;
-(BOOL) MesiboGroupcallAdmin_OnMakeFullScreen:(MesiboProfile * _Nonnull)requester isAdmin:(BOOL)isAdmin participant:(MesiboParticipant * _Nonnull)participant;
-(BOOL) MesiboGroupcallAdmin_OnMute:(MesiboProfile * _Nonnull)requester isAdmin:(BOOL)isAdmin participant:(MesiboParticipant * _Nonnull)participant audio:(BOOL)audio video:(BOOL)video enable:(BOOL)enable;
-(BOOL) MesiboGroupcallAdmin_OnLeave:(MesiboProfile * _Nonnull)requester isAdmin:(BOOL)isAdmin;

@end


@protocol MesiboGroupCallListener
-(void) MesiboGroupcall_OnPublisher:(MesiboParticipant *_Nonnull)p joined:(BOOL) joined;
-(void) MesiboGroupcall_OnSubscriber:(MesiboParticipant *_Nonnull)p joined:(BOOL) joined;
-(void) MesiboGroupCall_OnAudioDeviceChanged:(int)active inactive:(int)inactive;
@end

@protocol MesiboGroupCallInProgressListener
-(void) MesiboGroupcall_OnMute:(MesiboParticipant * _Nonnull)p audio:(BOOL)audio video:(BOOL) video remote:(BOOL)remote;
-(void) MesiboGroupcall_OnHangup:(MesiboParticipant * _Nonnull)p reason:(int)reason;
-(void) MesiboGroupcall_OnConnected:(MesiboParticipant * _Nonnull)p connected:(BOOL) connected;
-(void) MesiboGroupcall_OnTalking:(MesiboParticipant * _Nonnull)p talking:(BOOL) talking;
-(void) MesiboGroupcall_OnVideoSourceChanged:(MesiboParticipant * _Nonnull)p source:(int)source index:(int) index;
-(void) MesiboGroupcall_OnVideo:(MesiboParticipant * _Nonnull)p aspectRatio:(float)aspectRatio landscape:(BOOL)landscape;
-(void) MesiboGroupcall_OnAudio:(MesiboParticipant * _Nonnull)p;
-(BOOL) MesiboGroupcall_OnVisibilityPreference:(MesiboParticipant * _Nonnull)p visible:(BOOL)visible fullscreen:(BOOL)fullscreen priority:(int)priority;
@end

@interface MesiboParticipantAdmin : NSObject
-(void) mute:(BOOL) audio video:(BOOL) video enable:(BOOL) enable;
-(BOOL) toggleAudioMute;
-(BOOL) toggleVideoMute;
-(void) hangup;
-(void) publish:(uint32_t)sid source:(uint32_t)source index:(uint16_t)index audio:(BOOL)audio video:(BOOL)video;
-(void) subscribe:(MesiboParticipant * _Nonnull)publisher audio:(BOOL)audio video:(BOOL)video;
@end

@interface MesiboGroupCallAdmin : NSObject
-(void) mute:(NSArray<MesiboParticipant *> * _Nullable)participants audio:(BOOL)audio video:(BOOL) video enable:(BOOL) enable;
-(void) muteAll:(BOOL) audio video:(BOOL) video enable:(BOOL) enable;
-(void) hangup:(NSArray<MesiboParticipant *> * _Nullable)participants;
-(void) hangupAll;
-(void) fullscreen:(MesiboParticipant * _Nonnull) participant;
@end

@interface MesiboParticipant : NSObject
-(void) setListener:(id<MesiboGroupCallInProgressListener> _Nonnull) listener;
-(BOOL) call:(BOOL)audio video:(BOOL)video audioMute:(BOOL)audioMute videoMute:(BOOL)videoMute listener:(id<MesiboGroupCallInProgressListener> _Nonnull) listener ;
-(void) hangup;

-(void) switchCamera;
-(void) switchSource;
-(BOOL) isFrontCamera;
-(void) changeVideoFormat:(int) width height:(int) height fps:(int)fps;
-(void) setVideoSource:(int) source index:(int) index;
-(int) getVideoSource;

-(void) mute:(BOOL) audio video:(BOOL) video enabled:(BOOL) enabled;
-(BOOL) toggleAudioMute;
-(BOOL) toggleVideoMute;
-(BOOL) getMuteStatus:(BOOL) video;

-(void) adminMute:(BOOL) audio video:(BOOL) video enabled:(BOOL) enabled;
-(MesiboParticipantAdmin * _Nullable) getAdmin;

-(void) setVideoView:(MesiboVideoView * _Nullable)v;
-(MesiboVideoView * _Nullable) getVideoView;

-(BOOL) isCallInProgress;
-(BOOL) isCallConnected;

-(BOOL) isVideoCall;
-(BOOL) hasVideo;
-(BOOL) hasAudio;
-(BOOL) isTalking;
-(uint64_t) getTalkTimestamp;

-(BOOL) isVideoLandscape;
-(float) getAspectRatio;

-(uint64_t) getId;
-(uint32_t) getSid;
-(uint32_t) getUid;

-(id _Nullable) getUserData;
-(void) setUserData:(id _Nullable) data;

-(NSString * _Nullable) getName;
-(void) setName:(NSString * _Nonnull) name;
-(NSString * _Nonnull) getAddress;
-(MesiboProfile * _Nonnull) getProfile;
-(BOOL) isMe;
-(BOOL) isPublisher;

-(BOOL) setVisibility:(BOOL) visible fullscreen:(BOOL)fullscreen priority:(int) priority;
-(BOOL) setVisible:(BOOL) visible;
-(BOOL) setFullscreen:(BOOL) fullscreen;
-(BOOL) setPriority:(int) priority;
-(BOOL) isVisible;
-(BOOL) isFullscreen;
-(int) getPriority;
-(MesiboGroupCall * _Nonnull) getGroupCall;

@end

@interface MesiboParticipantSortParams : NSObject
@property (nonatomic) BOOL orderedBySelf;
@property (nonatomic) BOOL orderedByTalking;
@property (nonatomic) BOOL orderedByName;
@property (nonatomic) BOOL orderedByVideo;

@property (nonatomic) BOOL forceAspectRatio;
@property (nonatomic) BOOL flexibleOrientation;

@property (nonatomic) float maxHorzAspectRatio;
@property (nonatomic) float minVertAspectRation;
@property (nonatomic) float multiplier;
@end

@protocol MesiboParticipantSortListener
-(MesiboParticipant * _Nonnull) ParticipantSort_onGetParticipant:(id _Nonnull)o;
-(void) ParticipantSort_onSetCoordinates:(id _Nonnull)o position:(int)position x:(float)x y:(float)y width:(float)width height:(float)height;
@end

@interface MesiboGroupCall : NSObject
-(MesiboParticipant * _Nullable) createPublisher:(uint32_t)sid;

-(void) join:(id<MesiboGroupCallListener> _Nonnull) listener adminListener:(id<MesiboGroupCallAdminListener> _Nullable) adminListener;
-(void) join:(id<MesiboGroupCallListener> _Nonnull) listener;
-(void) leave;

-(BOOL) hasAdminPermissions:(BOOL)hangup;
-(MesiboGroupCallAdmin * _Nullable) getAdmin;

-(void) setAudioDevice:(int)device enable:(BOOL)enable;

-(void) playInCallSound:(NSURL * _Nonnull)url volume:(float)volume loops:(int)loops;
-(void) stopInCallSound;

- (NSArray * _Nullable) sortStreams:(id _Nonnull) listener views:(NSArray * _Nonnull)views width:(float)width height:(float)height start:(int)start size:(int)size params:(MesiboParticipantSortParams * _Nullable) params;
@end

