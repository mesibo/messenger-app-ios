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


#define AUDIO_INBUILT                   0
#define AUDIO_SPEAKER                   1
#define AUDIO_BLUETOOTH                 2
#define AUDIO_HEADPHONE                 3

#define MESIBO_FORMAT_DEFAULT           0
#define MESIBO_FORMAT_HEX               1
#define MESIBO_FORMAT_DECIMAL           2

#define MESIBO_STATUS_UNKNOWN            0
#define MESIBO_STATUS_ONLINE            1
#define MESIBO_STATUS_OFFLINE           2
#define MESIBO_STATUS_SIGNOUT           3
#define MESIBO_STATUS_AUTHFAIL          4
#define MESIBO_STATUS_STOPPED           5
#define MESIBO_STATUS_CONNECTING        6
#define MESIBO_STATUS_CONNECTFAILURE    7
#define MESIBO_STATUS_NONETWORK         8
#define MESIBO_STATUS_ONPREMISEERROR         9
#define MESIBO_STATUS_SUSPEND         10
#define MESIBO_STATUS_UPDATE         20
#define MESIBO_STATUS_MANDUPDATE        21
#define MESIBO_STATUS_SHUTDOWN          22
#define MESIBO_STATUS_ACTIVITY          -1

#define MESIBO_MSGSTATUS_OUTBOX         0
#define MESIBO_MSGSTATUS_SENT           1
#define MESIBO_MSGSTATUS_DELIVERED      2
#define MESIBO_MSGSTATUS_READ           3
#define MESIBO_MSGSTATUS_RECEIVEDNEW    0x12
#define MESIBO_MSGSTATUS_RECEIVEDREAD   0x13
#define MESIBO_MSGSTATUS_CALLMISSED     0x15
#define MESIBO_MSGSTATUS_CALLINCOMING   0x16
#define MESIBO_MSGSTATUS_CALLOUTGOING   0x17
#define MESIBO_MSGSTATUS_CUSTOM         0x20

//#define MESIBO_MSGSTATUS_DELETED         0x21
//#define MESIBO_MSGSTATUS_WIPED           0x22
#define MESIBO_MSGSTATUS_E2E             0x23
#define MESIBO_MSGSTATUS_E2E             0x23
#define MESIBO_MSGSTATUS_DATETIME        0x24
#define MESIBO_MSGSTATUS_HEADER          0x25
#define MESIBO_MSGSTATUS_INVISIBLE       0x26
#define MESIBO_MSGSTATUS_EMPTY           0x27

// ONLY FOR UI USAGE
#define MESIBO_MSGSTATUS_TIMESTAMP      0x30

#define MESIBO_MSGSTATUS_FAIL           0x80
#define MESIBO_MSGSTATUS_USEROFFLINE    0x81
#define MESIBO_MSGSTATUS_INBOXFULL      0x82
#define MESIBO_MSGSTATUS_INVALIDDEST    0x83
#define MESIBO_MSGSTATUS_EXPIRED        0x84
#define MESIBO_MSGSTATUS_BLOCKED        0x88
#define MESIBO_MSGSTATUS_GROUPPAUSED    0x90
#define MESIBO_MSGSTATUS_NOTMEMBER      0x91


#define MESIBO_RESULT_OK                0
#define MESIBO_RESULT_FAIL              0x80
#define MESIBO_RESULT_GENERROR          0x81
#define MESIBO_RESULT_NOSUCHERROR       0x83
#define MESIBO_RESULT_INBOXFULL         0x84
#define MESIBO_RESULT_BADREQ            0x85
#define MESIBO_RESULT_OVERCAPACITY      0x86
#define MESIBO_RESULT_RETRYLATER        0x87
#define MESIBO_RESULT_E2EERROR          0x8A

#define MESIBO_RESULT_TIMEOUT           0xB0
#define MESIBO_RESULT_CONNECTFAIL       0xB1
#define MESIBO_RESULT_DISCONNECTED      0xB2
#define MESIBO_RESULT_REQINPROGRESS     0xB3
#define MESIBO_RESULT_BUFFERFULL        0xB4

#define MESIBO_RESULT_AUTHFAIL          0xC0
#define MESIBO_RESULT_DENIED            0xC1

#define MESIBO_ORIGIN_REALTIME        0
#define MESIBO_ORIGIN_DBMESSAGE    1
#define MESIBO_ORIGIN_DBSUMMARY    2
#define MESIBO_ORIGIN_PENDING        3

#define MESIBO_ADDRESSSTRING_MAXLENGTH  63



#define MESIBO_PRESENCE_NONE            0
#define MESIBO_PRESENCE_REQUEST            0
#define MESIBO_PRESENCE_ONLINE          1
#define MESIBO_PRESENCE_OFFLINE      2
#define MESIBO_PRESENCE_TYPING          3
#define MESIBO_PRESENCE_TYPINGCLEARED   4
#define MESIBO_PRESENCE_JOINED          10
#define MESIBO_PRESENCE_LEFT            11
#define MESIBO_PRESENCE_RESERVED            255



#define MESIBO_SERVERTYPE_STUN                  0
#define MESIBO_SERVERTYPE_TURN                  1

#define MESIBO_MUTESTATUS_AUDIO   1
#define MESIBO_MUTESTATUS_VIDEO   2
#define MESIBO_MUTESTATUS_HOLD    4

#define MESIBO_RETRACT_MODIFY       1
#define MESIBO_RETRACT_WIPE     2
#define MESIBO_RETRACT_DELETE   4
#define MESIBO_RETRACT_DELUNREAD   0x10
#define MESIBO_RETRACT_DELREAD   0x20
#define MESIBO_RETRACT_DELMEDIA   0x40
#define MESIBO_RETRACT_DELTHREAD   0x80
#define MESIBO_RETRACT_DELALL  0x100
#define MESIBO_RETRACT_DELCONTACT  0x1000

#define MESIBO_CONTACT_UPDATE           0
#define MESIBO_CONTACT_DELETE           1

//MUST be same as internal CONNECTION_DISCONNECTED, etc
#define MESIBO_CONNECTIVITY_DISCONNECTED 0xFF
#define MESIBO_CONNECTIVITY_UNKNOWN      -1
#define MESIBO_CONNECTIVITY_WIFI         0
#define MESIBO_CONNECTIVITY_2G           1
#define MESIBO_CONNECTIVITY_3G           2
#define MESIBO_CONNECTIVITY_4G           3

#define MESIBO_DBTABLE_MESSAGES          1
#define MESIBO_DBTABLE_PROFILES          2
#define MESIBO_DBTABLE_KEYS              4

#define MESIBO_DBTABLE_ALL (MESIBO_DBTABLE_MESSAGES|MESIBO_DBTABLE_PROFILES|MESIBO_DBTABLE_KEYS)

#define MESIBO_CONFIGTYPE_CALLFLAGS             0x100
#define MESIBO_CONFIGTYPE_CALLANSWERMODE        0x101
#define MESIBO_CONFIGTYPE_CALLREQTO             0x110
#define MESIBO_CONFIGTYPE_CALLANSTO             0x111
#define MESIBO_CONFIGTYPE_CALLCONNECTTO         0x112


#define MESIBO_VISIBILITY_NONE         0
#define MESIBO_VISIBILITY_PUBLIC       1
#define MESIBO_VISIBILITY_SEARCHABLE      3
#if 0
#define MESIBO_VISIBILITY_CONTACT      2
#define MESIBO_VISIBILITY_CUSTOM       4
#define MESIBO_VISIBILITY_LOCAL        8
#endif

#define MESIBO_SYNCTYPE_REALTIME               0
#define MESIBO_SYNCTYPE_LAZY                   1
#define MESIBO_SYNCTYPE_ONLINEONLY             2
#define MESIBO_SYNCTYPE_RECENTONLY             3

#define MESIBO_ONLINEMODE_LOGIN         1
#define MESIBO_ONLINEMODE_FOREGROUND    2
#define MESIBO_ONLINEMODE_MANUAL        3


#define MESIBO_MEMBERFLAG_SEND    1
#define MESIBO_MEMBERFLAG_RECV    2
#define MESIBO_MEMBERFLAG_PUBL    4
#define MESIBO_MEMBERFLAG_SUBS    8
#define MESIBO_MEMBERFLAG_LIST    0x10
#define MESIBO_MEMBERFLAG_RECORD  0x20
#define MEMBERFLAG_EXPIRYTS       0x100
#define MEMBERFLAG_DELETEWITHPIN  0x200
#define MEMBERFLAG_NOSELFDELETE   0x800

#define MESIBO_MEMBERFLAG_ADMIN   0x1000
    // prevents user from deleting itself
#define MESIBO_MEMBERFLAG_NOSELFDELETE    0x2000
#define MESIBO_MEMBERFLAG_SHAREDPIN      0x8000

#define MESIBO_MEMBERFLAG_DELETE  0x80000000

/*
 * C macros that are more complex than simple constant definitions have no counterpart in Swift.
 * Currently, Swift does not support MACRO with more than two vars.
 * A|B supported, A|B|C not supported
 https://developer.apple.com/documentation/swift/imported_c_and_objective-c_apis/using_imported_c_macros_in_swift
 */
#if 0
#define MESIBO_MEMBERFLAG_ALL    (MESIBO_MEMBERFLAG_SEND|MESIBO_MEMBERFLAG_RECV|MESIBO_MEMBERFLAG_PUBL|MESIBO_MEMBERFLAG_SUBS|MESIBO_MEMBERFLAG_LIST)
#else
#define MESIBO_MEMBERFLAG_ALL    0x1F
#endif


#define MESIBO_ADMINFLAG_MODIFY       1
#define MESIBO_ADMINFLAG_ADDUSER      0x10
#define MESIBO_ADMINFLAG_REMUSER      0x20
#define MESIBO_ADMINFLAG_ADDADMIN     0x40
#define MESIBO_ADMINFLAG_REMADMIN     0x80
#define MESIBO_ADMINFLAG_REMOWNER     0x100
#define MESIBO_ADMINFLAG_REMGROUP     0x200
#define MESIBO_ADMINFLAG_CALLCONTROL  0x400
#define MESIBO_ADMINFLAG_HANGUP       0x800
#define MESIBO_ADMINFLAG_OWNER        0x1000
#define MESIBO_ADMINFLAG_ADDPIN       0x2000
#define MESIBO_ADMINFLAG_REMOVEPIN    0x4000
#define MESIBO_ADMINFLAG_LISTPIN      0x8000


#define MESIBO_OWNERFLAG_ALL          0xFFFF
#define MESIBO_ADMINFLAG_ALL          (MESIBO_OWNERFLAG_ALL & ~MESIBO_ADMINFLAG_OWNER)

#define MESIBO_GROUPFLAG_SENDBYSELECTED      1
#define MESIBO_GROUPFLAG_SENDBYANYONE        2
#define MESIBO_GROUPFLAG_AUTOADDMEMBER       8
#define MESIBO_GROUPFLAG_RECVBYSELECTED      0x10
#define MESIBO_GROUPFLAG_RECVROUNDROBIN      0x20
#define MESIBO_GROUPFLAG_NOSTORAGE           0x40
#define MESIBO_GROUPFLAG_RECVLOOPBACK        0x80
#define MESIBO_GROUPFLAG_PUBBYSELECTED       0x100
#define MESIBO_GROUPFLAG_PUBBYANYONE         0x200
#define MESIBO_GROUPFLAG_SUBBYSELECTED       0x1000
#define MESIBO_GROUPFLAG_SUBBYANYONE         0x2000
#define MESIBO_GROUPFLAG_LISTBYSELECTED      0x10000
#define MESIBO_GROUPFLAG_LISTBYANYONE        0x20000
    //members can't delete themselves
#define MESIBO_GROUPFLAG_NOSELFDELETE        0x40000
#define MESIBO_GROUPFLAG_PAUSE               0x8000000
    // these flags are not to be saved in database but sent by group_set request in profile_t
#define MESIBO_GROUPFLAG_DELETE              0x80000000

#define MESIBO_GROUPERROR_NOTMEMBER       1
#define MESIBO_GROUPERROR_PERMISSION      2
#define MESIBO_GROUPERROR_BADPIN          3
#define MESIBO_GROUPERROR_ACCESSDENIED    4
#define MESIBO_GROUPERROR_NOTSHAREDPIN    5
#define MESIBO_GROUPERROR_GENERAL         10
#define MESIBO_GROUPERROR_DELETED         11

#define MESIBO_RESOLUTION_DEFAULT          0
#define MESIBO_RESOLUTION_QVGA             1
#define MESIBO_RESOLUTION_VGA              2
#define MESIBO_RESOLUTION_HD               3
#define MESIBO_RESOLUTION_FHD              4
#define MESIBO_RESOLUTION_4K               5
#define MESIBO_RESOLUTION_QQVGA            8
#define MESIBO_RESOLUTION_180P             9
#define MESIBO_RESOLUTION_NHD              10
#define MESIBO_RESOLUTION_MAX              10

#define MESIBO_GROUPCALLFLAG_VALID           1
#define MESIBO_GROUPCALLFLAG_AUDIO           2
#define MESIBO_GROUPCALLFLAG_VIDEO           4
#define MESIBO_GROUPCALLFLAG_DATA            8
#define MESIBO_GROUPCALLFLAG_SCREEN          0x100
#define MESIBO_GROUPCALLFLAG_SIMULCAST       0x200
#define MESIBO_GROUPCALLFLAG_SIMULCAST2      0x400
#define MESIBO_GROUPCALLFLAG_4_3             0x800
#define MESIBO_GROUPCALLFLAG_RECORD          0x1000
#define MESIBO_GROUPCALLFLAG_VAD             0x8000
#define MESIBO_GROUPCALLFLAG_TALKING         0x8000
#define MESIBO_GROUPCALLFLAG_FIXEDBITRATE    0x10000
#define MESIBO_GROUPCALLFLAG_FIXEDRESOLUTION        0x20000
#define MESIBO_GROUPCALLFLAG_FIXEDFRAMERATE  0x40000
#define MESIBO_GROUPCALLFLAG_PREFER264       0x80000

#if 0
#define MESIBO_GROUPCALLFLAG_DEFAULT          (MESIBO_GROUPCALLFLAG_AUDIO|MESIBO_GROUPCALLFLAG_VIDEO|MESIBO_GROUPCALLFLAG_SCREEN|MESIBO_GROUPCALLFLAG_VAD)
#else
#define MESIBO_GROUPCALLFLAG_DEFAULT 0x8107
#endif

#define MESIBO_GROUP_SUBSCRIBERS                 2
#define MESIBO_GROUP_KNOWNSUBSCRIBERS            3
#define MESIBO_GROUP_PROVSUBSCRIBERS             4
#define MESIBO_GROUP_KNOWNPROVSUBSCRIBERS        5
#define MESIBO_GROUP_SUBSCRIBERSALL              6
#define MESIBO_GROUP_KNOWNSUBSCRIBERSALL         7
#define MESIBO_GROUP_CONTACTS                    8
#define MESIBO_GROUP_CONTACTSUBSCRIBERS          9
#define MESIBO_GROUP_SUBSCRIBED                  10
#define MESIBO_GROUP_PROVSUBSCRIBED              11

#define MESIBO_E2ECIPHER_AESGCM 1
#define MESIBO_E2ECIPHER_CHACHAPOLY1305 2
//#define MESIBO_E2ECIPHER_AESCBCHMAC 8
#define MESIBO_E2ECIPHER_AESCBC 0x20
#define MESIBO_E2ECIPHER_CHACHA20 0x40

#define MESIBO_E2ESTATUS_NONE 0
#define MESIBO_E2ESTATUS_ACTIVE 1
#define MESIBO_E2ESTATUS_INACTIVE 2
#define MESIBO_E2ESTATUS_IDENTITYCHANGED 3
#define MESIBO_E2ESTATUS_FAILED 0x80
#define MESIBO_E2ESTATUS_IDENTITYFAILED 0x81
#define MESIBO_E2ESTATUS_SUSPICIOUS 0x82

@class MesiboMessage; // forward declaration
@class MesiboPresence;
@class MesiboMessageProperties;
@class MesiboProfile;
@class MesiboSelfProfile;
@class MesiboDateTime;
@class MesiboLocationManager;
@class MesiboProfileSearch;

@interface MesiboLocationConfig : NSObject
@property (nonatomic) uint32_t minDistance;
@property (nonatomic) uint32_t minDistanceSharing;
@property (nonatomic) uint32_t minInterval;
@property (nonatomic) uint32_t maxInterval;
@property (nonatomic) BOOL backgroundRefresh;
@property (nonatomic) BOOL fineLocation;
@property (nonatomic) BOOL aggressive;
@end

@interface MesiboLocation : NSObject
@property (nonatomic) double latitude;
@property (nonatomic) double longitude;
@property (nonatomic) double altitude;
@property (nonatomic) double speed;
@property (nonatomic) double distance;
@property (nonatomic) double accuracy;
@property (nonatomic) uint64_t ts;
@property (nonatomic) uint32_t flags;

-(MesiboDateTime * _Nullable) getTimestamp;
@end

@interface MesiboProfileLocation : NSObject
-(void) share:(uint32_t)duration minDistance:(uint32_t)minDistance sendRealLocation:(BOOL)sendRealLocation;
-(void) share:(uint32_t)duration minDistance:(uint32_t)minDistance;
-(void) share:(uint32_t)duration;
-(void) endSharing;
-(void) cancelSubscription;
-(int) getSubscriptionStatus;
 
-(MesiboLocation * _Nullable) subscribe:(uint32_t)duration maxDistance:(uint32_t)maxDistance;
-(MesiboLocation * _Nullable) subscribe:(uint32_t)duration;
-(MesiboLocation * _Nullable) get;
@end


@interface MesiboEndToEndEncryption : NSObject
-(void) enable:(BOOL) enable;
-(BOOL) isEnabled;
-(void) enableSecureOnly:(BOOL) enable;
-(BOOL) reset:(NSString * _Nonnull) address;
-(int) getStatus:(NSString * _Nonnull) address;
-(BOOL) isActive:(NSString * _Nonnull) address;
-(int) setLevel:(int) level;
-(int) setCiphers:(uint32_t)supported preferred:(uint32_t) preferred;
-(BOOL) setPassword:(NSString * _Nullable) address password:(NSString * _Nonnull) password;
-(BOOL) setPassword:(NSString * _Nonnull) password;
-(int) setAuthenticationTaglen:(int) len;
-(BOOL) setAuthenticationData:(NSString * _Nullable) address  add:(NSString * _Nonnull) aad;
-(BOOL) setAuthenticationData:(NSString * _Nonnull) aad;
-(NSString * _Nonnull) getPublicCertificate;
-(BOOL) setPrivateCertificate:(NSString * _Nonnull) filename;
-(BOOL) setPeerCertificate:(NSString * _Nonnull) address filename:(NSString * _Nonnull) filename;
-(NSString * _Nonnull) getPeerCertificateOrg:(NSString * _Nonnull) address;
-(NSString * _Nonnull) getPeerCertificateCommonName:(NSString * _Nonnull) address;
-(NSString * _Nonnull) getFingerprint:(NSString * _Nonnull) address;
-(NSString * _Nonnull) getUserFingerprint:(NSString * _Nonnull) address;
-(NSString * _Nonnull) getFingerprintPart:(NSString * _Nonnull) fingerprint part:(int) part;
-(int) setConfig:(int)level minopns:(uint32_t) minops maxops:(uint32_t) maxops minDuration:(uint32_t) minDuration maxDuration:(uint32_t) maxDuration;

@end

@interface MesiboProfileEndToEndEncryption : NSObject
-(BOOL) reset;
-(int) getStatus;
-(BOOL) isActive;
-(BOOL) setPassword:(NSString * _Nullable) password;
-(BOOL) setAuthenticationData:(NSString * _Nullable) aad;
-(BOOL) setPeerCertificate:(NSString * _Nullable) filename;
-(NSString * _Nonnull) getPeerCertificateOrg;
-(NSString * _Nonnull) getPeerCertificateCommonName;
-(NSString * _Nonnull) getFingerprint;
-(NSString * _Nonnull) getUserFingerprint;
@end

@interface MesiboGroupSettings : NSObject
@property (nonatomic) NSString * _Nullable name;
@property (nonatomic) uint32_t flags;
@property (nonatomic) uint32_t callFlags;
@property (nonatomic) uint32_t callDuration;
@property (nonatomic) uint32_t videoResolution;
@property (nonatomic) uint32_t expiry;
@end

@interface MesiboMemberPermissions : NSObject
@property (nonatomic) uint32_t flags;
@property (nonatomic) uint32_t adminFlags;
@property (nonatomic) uint32_t callFlags;
@property (nonatomic) uint32_t callDuration;
@property (nonatomic) uint32_t videoResolution;
@property (nonatomic) uint32_t expiry;
@end

@interface MesiboGroupPin : NSObject
@property (nonatomic) uint32_t pin;
@property (nonatomic, nullable) MesiboMemberPermissions *permissions;
@end

#define MESIBO_PHONETYPE_INVALID  -1
#define MESIBO_PHONETYPE_MAYBE  0
#define MESIBO_PHONETYPE_VALID  1
#define MESIBO_PHONETYPE_MOBILE  2
#define MESIBO_PHONETYPE_FIXED  3
#define MESIBO_PHONETYPE_TOLLFREE  4
#define MESIBO_PHONETYPE_PREMIUM  5
#define MESIBO_PHONETYPE_VOIP  6
#define MESIBO_PHONETYPE_PRIVATE  7
#define MESIBO_PHONETYPE_COUNTRY  10

@interface MesiboPhoneContact : NSObject
@property (nonatomic) MesiboProfile * _Nullable profile;
@property (nonatomic) NSString * _Nullable name;
@property (nonatomic) NSString * _Nullable phoneNumber;
@property (nonatomic) NSString * _Nullable nationalNumber;
@property (nonatomic) NSString * _Nullable formattedPhoneNumber;
@property (nonatomic) NSString * _Nullable country;
@property (nonatomic) NSString * _Nullable countryIsoCode;
@property (nonatomic) int countryPhoneCode;
@property (nonatomic) int type;
@property (nonatomic) BOOL valid;
@property (nonatomic) BOOL possiblyValid;
@end

@interface MesiboContactSynchronizer : NSObject
+(BOOL) isAutoSyncEnabled;
+(void) enableAutoSync:(BOOL) enable;

-(void) subscribe:(BOOL)subscribe;
-(void) setContact:(BOOL)contact __deprecated_msg("Use setProfileAccessLevels(levels) instead.");
-(BOOL) setProfileAccessLevels:(NSArray<NSNumber *> * _Nullable) profileAccessLevels;

-(void) sync:(NSArray<NSString *> * _Nonnull)addresses syncNow:(BOOL)syncNow;
-(void) sync:(NSArray<NSString *> * _Nonnull)addresses;
-(void) syncAsUpdate:(NSArray<NSString *> * _Nonnull)addresses syncNow:(BOOL)syncNow;
-(void) syncAsUpdate:(NSArray<NSString *> * _Nonnull)addresses;
-(void) syncNow;
@end

@protocol MesiboPhoneContactsListener <NSObject>
-(BOOL) Mesibo_onPhoneContactsChanged  NS_SWIFT_NAME(Mesibo_onPhoneContactsChanged());
-(BOOL) Mesibo_onPhoneContactsAdded:(NSArray<NSString *> * _Nonnull) phones  NS_SWIFT_NAME(Mesibo_onPhoneContactsAdded(phones:));
-(BOOL) Mesibo_onPhoneContactsDeleted:(NSArray<NSString *> * _Nonnull) phones  NS_SWIFT_NAME(Mesibo_onPhoneContactsDeleted(phones:));
@end

@interface MesiboPhoneContactsManager : NSObject
+(MesiboPhoneContactsManager * _Nonnull) getInstance;
-(void) setListener:(id<MesiboPhoneContactsListener>  _Nonnull) listener;
-(void) setSynchronizers:(MesiboContactSynchronizer * _Nullable) addSyncer deleteSyncer:(MesiboContactSynchronizer * _Nullable) deleteSyncer;
-(void) syncMobileNumbers:(BOOL) enable;
-(void) syncLandlineNumbers:(BOOL) enable;
-(void) syncTollfreeNumbers:(BOOL) enable;
-(void) syncPremiumNumbers:(BOOL) enable;
-(void) syncVoipNumbers:(BOOL) enable;
-(void) syncPrivateNumbers:(BOOL) enable;
-(void) syncUnknownNumbers:(BOOL) enable;
-(void) ignoreInvalidCharacters:(BOOL) enable;
-(void) ignoreInvalidLength:(BOOL) enable;
-(void) truncateLongNumbers:(BOOL) enable;
-(void) forcePrefixCountryCode:(BOOL) enable;
-(void) detectMissingCountryCode:(BOOL) enable;
-(void) enableNameLookup:(BOOL) enable;
-(void) syncValidNumbers:(BOOL) enable;
-(void) syncPossiblyValidNumbers:(BOOL) enable;
-(void) syncInvalidNumbers:(BOOL) enable;
-(void) overrideProfileName:(BOOL) enable;
-(BOOL) canOverrideProfileName;
-(BOOL) start:(BOOL) listenChanges;
-(BOOL) start;
-(BOOL) isStarted;
-(void) reset;
-(MesiboPhoneContact * _Nonnull) setCountryCodeFromPhoneNumber:(NSString * _Nonnull) phone;
-(MesiboPhoneContact * _Nonnull) setCountryCodeFromPhoneNumber:(NSString * _Nonnull) phone code:(NSString * _Nullable) code;
-(MesiboPhoneContact * _Nonnull) setCountryCode:(NSString * _Nullable) code;
-(MesiboPhoneContact * _Nonnull) getCountryCode:(NSString * _Nullable) code;
-(MesiboPhoneContact * _Nonnull) getCountryCode;
// Removed because of iOS 16 CTCarrier deprecation
//-(MesiboPhoneContact * _Nonnull) getNetworkCountryCode;
//-(MesiboPhoneContact * _Nonnull) getSimCountryCode;
-(MesiboPhoneContact * _Nonnull) getPhoneNumberInfo:(NSString * _Nonnull) phone;
-(MesiboPhoneContact * _Nonnull) getPhoneNumberInfo:(NSString * _Nonnull) phone format:(BOOL)format;
  -(MesiboPhoneContact * _Nonnull) getPhoneNumberInfo:(NSString * _Nonnull) phone code:(NSString * _Nullable)code format:(BOOL)format;
@end

@class MesiboGroupProfile; // foward declaration
@protocol MesiboProfileDelegate;
@class MesiboMessageProperties;
@class MesiboReadSession;
@class MesiboFile;
@class MesiboDateTime;

@protocol MesiboProfileCustomizationListener <NSObject>
-(BOOL) Mesibo_onCustomizeProfile:(MesiboProfile * _Nonnull)profile NS_SWIFT_NAME(Mesibo_onCustomizeProfile(profile:));
-(NSString * _Nullable) Mesibo_onGetProfileName:(MesiboProfile * _Nonnull)profile NS_SWIFT_NAME(Mesibo_onGetProfileName(profile:));
-(UIImage * _Nullable) Mesibo_onGetProfileImage:(MesiboProfile * _Nonnull)profile NS_SWIFT_NAME(Mesibo_onGetProfileImage(profile:));
@end

@interface MesiboProfileImage : NSObject
-(MesiboProfile * _Nullable) getProfile;
-(int) getIndex;
-(BOOL) isEmpty;
-(UIImage * _Nullable) getImage;
-(UIImage * _Nullable) getThumbnail;
-(UIImage * _Nullable) getImageOrThumbnail;
-(NSString * _Nullable) getUrl;
-(NSString * _Nullable) getImagePath;
-(NSString * _Nullable) getThumbnailPath;
-(NSString * _Nullable) getImageOrThumbnailPath;
-(MesiboProfileImage * _Nullable) getNext;
-(MesiboProfileImage * _Nullable) getPrevious;
@end

@interface MesiboProfile : NSObject

+(MesiboProfile * _Nullable) get:(uint32_t)code;
+(MesiboProfile * _Nonnull) getProfile:(NSString * _Nonnull) address;
+(MesiboProfile * _Nonnull) getGroupProfile:(uint32_t) groupid;
+(MesiboSelfProfile * _Nonnull) getSelfProfile;

-(uint32_t) getHashCode;

-(void) reset;
-(BOOL) isActive;

-(void) favorite:(BOOL)enable;
-(void) archive:(BOOL)enable;
-(void) setHidden:(BOOL) enable;
-(void) setMuted:(BOOL) enable;
-(void) toggleHidden;
-(void) toggleMute;
-(BOOL) isArchived;
-(BOOL) isFavorite;
-(BOOL) isMuted;
-(BOOL) isHidden;

-(void) toggleMark;
-(BOOL) isMarked;
-(void) setMark:(BOOL) enable;
-(BOOL) isSelfProfile;
-(BOOL) isGroup;
-(BOOL) isLookedup;

-(BOOL) isCallInProgres;
-(BOOL) isVideoCallInProgress;
-(BOOL) isVoiceCallInProgress;

-(BOOL) isValidDestination;

-(BOOL) isProfileSynced;
-(BOOL) isSyncedProfileRecent;

-(BOOL) isDeleted;
-(void) setDeleted;

-(BOOL) isOnline;
-(BOOL) isTyping;
-(BOOL) isTypingInGroup:(uint32_t)gid;
-(BOOL) isChatting;
-(BOOL) isChattingInGroup:(uint32_t)gid;

-(BOOL) isUpdateRealtime;

-(BOOL) matches:(MesiboMessageProperties * _Nonnull) m;

-(BOOL) toggleBlock;
-(void) block:(BOOL) enable;
-(void) blockMessages:(BOOL) enable;
-(void) blockCalls:(BOOL) enable;
-(void) blockVideoCalls:(BOOL) enable;
-(void) blockGroupMessages:(BOOL) enable;
-(void) blockProfile:(BOOL) enable;
-(void) blockProfileSubscription:(BOOL) enable;
-(BOOL) isBlocked;
-(BOOL) isMessageBlocked;
-(BOOL) isCallBlocked;
-(BOOL) isGroupMessageBlocked;
-(BOOL) isVideoCallBlocked;
-(BOOL) isProfileSubscriptionBlocked;

-(void) setPrivate:(BOOL) enable;
-(void) setRecent:(BOOL) enable;

-(void) requestProfileRemoval:(BOOL) enable;

-(uint32_t) getUid;
-(uint32_t) getGroupId;
-(NSString * _Nullable) getAddress;

-(MesiboDateTime * _Nullable) getLastSeen;

-(NSString * _Nullable) getAdmin ;

-(void) setName:(NSString * _Nonnull)name ;
-(void) setTemporaryName:(NSString * _Nullable)name;
-(void) setOverrideName:(NSString * _Nonnull)name ;

-(NSString * _Nullable) getName ;
-(NSString * _Nonnull) getNameOrAddress;
-(NSString * _Nullable) getFirstName ;
-(NSString * _Nonnull) getFirstNameOrAddress;

-(void) setDraft:(NSString * _Nullable)val ;
-(NSString * _Nullable) getDraft ;
-(void) setUserData:(id _Nullable)val ;
-(id _Nullable) getUserData ;

-(void) setString:(NSString * _Nonnull) name value:(NSString * _Nullable) value;
-(void) setLong:(NSString * _Nonnull) name value:(long) value;
-(void) setInt:(NSString * _Nonnull) name value:(int) value;
-(void) setDouble:(NSString * _Nonnull) name value:(double) value;
-(void) setBoolean:(NSString * _Nonnull) name value:(BOOL) value;

-(int) hasValue:(NSString * _Nonnull) name;
-(NSDictionary * _Nonnull) getValues;
-(id _Nullable) getValue:(NSString * _Nonnull) name;
-(NSString * _Nullable) getString:(NSString * _Nonnull) name defval:(NSString * _Nullable) defval;
-(long) getLong:(NSString * _Nonnull) name defval:(long) defval;
-(int) getInt:(NSString * _Nonnull) name defval:(int) defval;
-(double) getDouble:(NSString * _Nonnull) name defval:(double) defval;
-(BOOL) getBoolean:(NSString * _Nonnull) name defval:(BOOL) defval;

-(BOOL) setImage:(UIImage * _Nullable)image index:(int)index;
-(BOOL) setImage:(UIImage * _Nullable)image;
-(BOOL) setImageFromFile:(NSString * _Nullable)path index:(int)index;
-(BOOL) setImageFromFile:(NSString * _Nullable)path;
-(BOOL) setImageUrl:(NSString * _Nonnull) url index:(int)index;
-(BOOL) setImageUrl:(NSString * _Nonnull) url;

-(MesiboProfileImage * _Nonnull) getImage:(int)index;
-(MesiboProfileImage * _Nonnull) getImage;
-(BOOL) prefetchImages;


-(MesiboProfile * _Nonnull) cloneProfile;

-(MesiboProfileEndToEndEncryption * _Nonnull) e2ee;
-(MesiboProfileLocation * _Nonnull) location;

-(BOOL) addListener:(id<MesiboProfileDelegate> _Nonnull) delegate ;
-(void) removeListener:(id<MesiboProfileDelegate> _Nonnull) delegate ;

+(void) setThumbnailProperties:(uint16_t)width height:(uint16_t)height maxside:(uint16_t)maxside maxpixels:(uint32_t)maxpixels;
+(void) setImageProperties:(uint16_t)width height:(uint16_t)height maxside:(uint16_t)maxside maxpixels:(uint32_t)maxpixels;

-(BOOL) isContact;
-(BOOL) isSubscribed;
-(void) setContact:(BOOL) enable __deprecated_msg("Use setProfileAccessLevels(levels) instead.");
-(void) subscribe:(BOOL) enable;
-(void) setProfileAccessLevels:(NSArray * _Nullable) levels;

-(void) removeLocalProfile;
-(void) removeSyncedProfile;
-(void) remove;
-(void) reload;

-(void) sendTyping;
-(void) sendJoined;
-(void) sendLeft;

-(void) broadcastChanges;
-(BOOL) publish;
-(BOOL) save;

-(MesiboGroupProfile * _Nullable) getGroupProfile;

-(BOOL) deleteMessages:(uint64_t)ts;
-(BOOL) deleteMessages;
-(BOOL) deleteMessagesOlderThan:(uint32_t) seconds;
-(BOOL) clearMessages:(uint64_t)ts;
-(BOOL) clearMessages;

-(MesiboReadSession * _Nonnull) createReadSession:(id _Nullable) delegate;
-(MesiboMessage * _Nonnull) newMessage;
-(MesiboPresence * _Nonnull) newPresence;

-(int) getMessageCount:(uint64_t)threadid status:(int)status;
-(int) getTotalMessageCount;
-(int) getSentMessageCount;
-(int) getReceivedMessageCount;
-(int) getUnreadMessageCount;
-(int) getFailedMessageCount;
-(int) unread;
-(int) markUnread;
-(int) markRead:(BOOL) sendReadReceipt;

-(int) subscribeTransient:(uint32_t)type activity:(uint32_t)activity duration:(uint32_t) duration;

@end

@interface MesiboGroupMember : NSObject
-(BOOL) isOwner;
-(BOOL) isAdmin;
-(MesiboProfile * _Nonnull) getProfile;
-(NSString * _Nonnull) getAddress;
@end

@interface MesiboGroupProfile : MesiboProfile
-(BOOL) isOwner;
-(BOOL) canAdmin;
-(BOOL) canModify;
-(BOOL) canAddMembers;
-(BOOL) canRemoveMembers;
-(BOOL) canAddAdmins;
-(BOOL) canRemoveAdmins;
-(BOOL) canRemoveOwner;
-(BOOL) canRemoveGroup;
-(uint64_t) getRequestId;
-(MesiboProfile * _Nullable) getLastAdmin;

-(int) getSettings:(id _Nonnull) listener;
-(void) setProperties:(MesiboGroupSettings * _Nonnull) settings;


-(int) getMembers:(int)count restart:(BOOL)restart listener:(id _Nonnull)listener;
-(BOOL) deleteGroup;
-(int) addMembers:(NSArray * _Nonnull)addresses permissions:(MesiboMemberPermissions * _Nonnull)permissions pin:(uint32_t)pin;
-(int) addMembers:(NSArray * _Nonnull)addresses permissions:(MesiboMemberPermissions * _Nonnull)permissions;
-(int) addMember:(NSString * _Nonnull)address permissions:(MesiboMemberPermissions * _Nonnull)permissions pin:(uint32_t)pin;
-(int) addMember:(NSString * _Nonnull)address permissions:(MesiboMemberPermissions * _Nonnull)permissions;
-(int) addMembers:(NSArray * _Nonnull)members permissions:(uint32_t)permissions adminPermissions:(uint32_t)adminPermissions;

-(int) removeMembers:(NSArray * _Nonnull)members;
-(int) removeMember:(NSString * _Nonnull)address;


-(void) addPin:(MesiboMemberPermissions *  _Nonnull)permissions listener:(id _Nonnull)listener expiry:(uint32_t)expiry count:(uint32_t)count;
-(void) addPin:(MesiboMemberPermissions *  _Nonnull)permissions listener:(id _Nonnull)listener;
-(BOOL) editPin:(uint32_t) pin permissions:(MesiboMemberPermissions *  _Nonnull)permissions expiry:(uint32_t)expiry count:(uint32_t) count;
-(BOOL) removePin:(uint32_t) pin;

-(void) join:(uint32_t) pin listener:(id  _Nonnull)listener;
-(void) leave;

@end

@interface MesiboSelfProfile : MesiboProfile
-(void) setVisibility:(int) visibility __deprecated_msg("Use setAccessLevel(name, level) instead.");
-(void) setSearchable:(BOOL) enable;
-(void) setSyncType:(int)type;
-(void) setAccessLevel:(NSString * _Nonnull)name level:(int)level;
-(void) resetAccessLevels;
-(void) setString:(NSString * _Nonnull)name value:(NSString * _Nonnull)value level:(int)level;
-(void) setLong:(NSString * _Nonnull)name value:(long)value level:(int)level;
-(void) setInt:(NSString * _Nonnull)name value:(int)value level:(int)level;
-(void) setDouble:(NSString * _Nonnull)name value:(double)value level:(int)level;
-(void) setBoolean:(NSString * _Nonnull)name value:(BOOL)value level:(int)level;
-(BOOL) setImage:(UIImage * _Nullable)image index:(int)index level:(int)level;
-(BOOL) setImageFromFile:(NSString * _Nullable)path index:(int)index level:(int)level;
-(BOOL) setImageUrl:(NSString * _Nullable)url index:(int)index level:(int)level;
@end

@protocol MesiboProfileDelegate <NSObject>
@required
-(void) MesiboProfile_onUpdate:(MesiboProfile * _Nonnull)profile NS_SWIFT_NAME(MesiboProfile_onUpdate(profile:));
-(void) MesiboProfile_onEndToEndEncryption:(MesiboProfile * _Nonnull)profile status:(int) status NS_SWIFT_NAME(MesiboProfile_onEndToEndEncryption(profile:status:));
-(void) MesiboProfile_onPublish:(MesiboProfile * _Nonnull)profile result:(BOOL)result  NS_SWIFT_NAME(MesiboProfile_onPublish(profile:result:));
@end

@interface MesiboDateTime : NSObject
@property (nonatomic) uint64_t ts;
@property (nonatomic) int year;
@property (nonatomic) int month;
@property (nonatomic) int day;
@property (nonatomic) int hour;
@property (nonatomic) int min;
@property (nonatomic) int sec;
@property (nonatomic) int wday;

+(BOOL) isMonthFirstDateFormat;
+(BOOL) is24HourTimeFormat;
+(void) setDefaultRelativeDateText:(NSString * _Nullable)today yesterday:(NSString * _Nullable) yesterday;
+(void) setDefaultDateFormat:(BOOL) monthFirst;
+(BOOL) setMonthName:(int)month name:(NSString * _Nonnull)name;

-(BOOL) isValid;
-(BOOL) setTimestamp:(uint64_t) ts;
-(BOOL) isToday;
-(BOOL) isYesterday;
-(int) getDaysElapsed;
-(int) getSecondsElapsed;
-(NSString * _Nullable) getMonthName;
-(NSString * _Nonnull) getDate;
-(NSString * _Nonnull) getNumericalDate;
-(NSString * _Nonnull) getDate:(BOOL)monthFirst today:(NSString * _Nullable)today yesterday:(NSString * _Nullable) yesterday numerical:(BOOL)numerical;
-(NSString * _Nonnull) getTime:(BOOL)seconds;
-(NSString * _Nonnull) getDateInNaturalLanguage:(int)accuracy;
-(NSString * _Nonnull) getDateInNaturalLanguage;
@end

@interface MesiboMessageProperties : NSObject
@property (nonatomic, nullable) NSString * peer;
@property (nonatomic) uint64_t mid;
@property (nonatomic) uint64_t refid;
@property (nonatomic) uint64_t rsid;
@property (nonatomic) uint64_t ts;
@property (nonatomic) int expiry;
@property (nonatomic) uint32_t groupid;
@property (nonatomic) int type;
@property (nonatomic) int status;
@property (nonatomic) uint64_t statusFlags;
@property (nonatomic) int origin;

@property (nonatomic, nullable) MesiboDateTime *date;

@property (nonatomic, nullable) MesiboProfile *profile;
@property (nonatomic, nullable) MesiboProfile *groupProfile;

-(BOOL) compare:(nullable NSString *)peer groupid:(uint32_t)groupid;
-(BOOL) compare:(nonnull MesiboMessageProperties *) p;

// for group messages only
-(nullable MesiboProfile *) getCurrentStatusSender;
-(int) getCurrentStatus;

-(uint64_t) getMessageId;
-(void) setMessageId:(uint32_t) mid;
-(uint64_t) getFlags __deprecated_msg("This function is for internal use only. It can change anytime and you should not use it.");
-(int) getStatus;
-(void) setStatus:(int)status;
-(int) getExpiry;
-(void) setExpiry:(int)expiry;
-(int) getType;
-(void) setType:(int)type;
-(int) getOrigin;
-(void) setFlag:(uint64_t) flag;
-(void) setInReplyToMessage:(MesiboMessage * _Nonnull) message;
-(void) setInReplyTo:(uint64_t) messageid;
-(uint64_t) getInReplyTo;
-(BOOL) isReply;

-(void) setPeer:(NSString * _Nonnull)peer;
-(void) setGroup:(uint32_t) group;

-(void) enableTransient:(BOOL) enable;
-(void) enablePresence:(BOOL) enable;
-(void) enableReadReceipt:(BOOL) enable;
-(void) enableDeliveryReceipt:(BOOL) enable;
-(void) enableCustom:(BOOL) enable;
-(void) enableModify:(BOOL) enable;
-(void) enableBroadcast:(BOOL) enable;

-(void) markDeleted:(BOOL) enable;
-(void) markWiped:(BOOL) enable;
-(BOOL) isDeleted;
-(BOOL) isWiped;

-(BOOL) isIncoming;
-(BOOL) isOutgoing;
-(BOOL) isInOutbox;
-(BOOL) isSent;
-(BOOL) isDelivered;
-(BOOL) isReadByPeer;
-(BOOL) isReadByUs;
//-(BOOL) isRead;
-(BOOL) isUnread;
-(BOOL) isSavedMessage;
-(BOOL) isCustom;
-(BOOL) isHeader;
-(BOOL) isInvisible;
-(BOOL) isModified; // depreciated
-(BOOL) isModifiedByPeer;
-(BOOL) isUpdated;
-(BOOL) isDynamic;
-(BOOL) isFileTransferFailed;
-(BOOL) isForwarded;
-(BOOL) isEndToEndEncrypted;
-(BOOL) isEndToEndEncryptionStatus;
-(BOOL) isPresence;
-(BOOL) isRichMessage;
-(BOOL) isPlainMessage;
-(BOOL) isMissedCall;
-(BOOL) isIncomingCall;
-(BOOL) isOutgoingCall;
-(BOOL) isCall;
-(BOOL) isVoiceCall;
-(BOOL) isVideoCall;
-(BOOL) isPstnCall;
-(BOOL) isLastMessage;

-(BOOL) isDbMessage;
-(BOOL) isDbSummaryMessage;
-(BOOL) isDbPendingMessage;
-(BOOL) isRealtimeMessage;
-(BOOL) isPendingMessage;
-(BOOL) isGroupMessage;
-(BOOL) isFromSamePeer:(MesiboMessageProperties * _Nonnull) m;

-(BOOL) isFailed;
-(BOOL) isMessageStatusInProgress;

-(BOOL) isDate;
-(BOOL) isMessage;

-(BOOL) isDestinedFor:(MesiboProfile * _Nonnull) profile;
-(MesiboProfile * _Nullable) getProfile;
-(MesiboProfile * _Nullable) getPeerProfile;
-(MesiboProfile * _Nullable) getSenderProfile;
-(MesiboGroupProfile * _Nullable) getGroupProfile;

-(void) setAge:(uint32_t) age;
-(void) setAgeAfterDelivered:(uint32_t) age;
-(void) setAgeAfterRead:(uint32_t) age;
-(uint32_t) getAge;
-(uint32_t) getAgeAfterDelivered;
-(uint32_t) getAgeAfterRead;

-(void) setUserData:(uint64_t) data;
-(uint64_t) getUserData;

-(void) setThreadId:(uint64_t) tid;
-(uint64_t) getThreadId;
        
-(void) setSensitivity:(uint32_t) val;
-(uint32_t) getSensitivity;

-(int) getCallDuration;

-(MesiboDateTime * _Nonnull) getTimestamp;
-(MesiboDateTime * _Nullable) getReadTimestamp:(NSString * _Nullable) peer;
-(MesiboDateTime * _Nullable) getDeliveryTimestamp:(NSString * _Nullable) peer;

-(MesiboReadSession * _Nullable) getReadSession;

@end

typedef MesiboProfile MesiboAddress;

#define MESIBO_FILEACTION_START   0
#define MESIBO_FILEACTION_STOP   1

#define MESIBO_FILEMODE_DOWNLOAD  0
#define MESIBO_FILEMODE_UPLOAD    1

#define MESIBO_FILESTATUS_IDLE            0
#define MESIBO_FILESTATUS_INPROGRESS      1
#define MESIBO_FILESTATUS_RETRYLATER      2
#define MESIBO_FILESTATUS_FAILED          3

#define MESIBO_FILETYPE_AUTO              0
#define MESIBO_FILETYPE_IMAGE             1
#define MESIBO_FILETYPE_VIDEO             2
#define MESIBO_FILETYPE_AUDIO             3
#define MESIBO_FILETYPE_PROFILEIMAGE      5
#define MESIBO_FILETYPE_PROFILETHUMBNAIL  6
#define MESIBO_FILETYPE_OTHER             10
#define MESIBO_FILETYPE_LOCATION          200


#define MESIBO_FILESOURCE_MESSAGE         0
#define MESIBO_FILESOURCE_PROFILE         1
#define MESIBO_FILESOURCE_GROUPPROFILE    2
#define MESIBO_FILESOURCE_THUMBNAIL       3
#define MESIBO_FILESOURCE_UNKNOWN         99
#define MESIBO_FILESOURCE_CUSTOM          100

#define MESIBO_FILETYPE_MASK                0xFF

@interface MesiboFile : NSObject
@property (nonatomic) int type;
@property (nonatomic) int subtype;
@property (nonatomic, nullable) NSString *url;
@property (nonatomic, nonnull) NSString *path;
@property (nonatomic, nullable) NSString *name;
@property (nonatomic, nullable) NSString *mimeType;
@property (nonatomic) uint64_t size;
@property (nonatomic) int progress;
@property (nonatomic) int source;
@property (nonatomic, nullable) id object;
@property (nonatomic, nullable) id asset;
@property (nonatomic, nullable) NSString *localIdentifier;
@end

@interface MesiboFileTransfer : NSObject
@property (nonatomic) BOOL upload;
@property (nonatomic) int priority;
@property (nonatomic) int progress;
@property (nonatomic) uint64_t mid;
@property (nonatomic) uint64_t ts;
@property (nonatomic) int origin;
@property (nonatomic) int source;
@property (nonatomic) int imageIndex;
@property (nonatomic) BOOL secure; 
@property (nonatomic) BOOL externalLink;
@property (nonatomic) BOOL result;
@property (nonatomic) BOOL inProgress;
@property (nonatomic) BOOL notifyProgress;

-(NSString * _Nonnull) getPath;
-(NSString * _Nullable) getUrl;
-(id _Nullable) getUserObject;
-(NSString * _Nullable) getLocalIdentifier;
-(id _Nullable) getPHAsset;
-(void) start:(NSString * _Nullable)url post:(NSDictionary * _Nullable)post;
-(void) cancel:(BOOL)retryLater;
-(void) setProgress:(int)progress;
-(void) setResult:(BOOL)success url:(NSString * _Nullable) url;
-(void) setResult:(BOOL)success;
-(void) setFileTransferContext:(id _Nullable) obj NS_SWIFT_NAME(setFileTransferContext(obj:));
-(id _Nullable) getFileTransferContext NS_SWIFT_NAME(getFileTransferContext());
@end


@interface MesiboRect : NSObject
@property (nonatomic) uint16_t x;
@property (nonatomic) uint16_t y;
@property (nonatomic) uint16_t width;
@property (nonatomic) uint16_t height;
@end

#define MESIBO_CROP_GRAVITY_CENTER 0
#define MESIBO_CROP_GRAVITY_START  1
#define MESIBO_CROP_GRAVITY_END    2

@interface MesiboMediaProperties : NSObject
@property (nonatomic) MesiboRect * _Nullable cropping;
@property (nonatomic) uint16_t quality;
// image format was specified, we can use auto (COPY, videoCopy. AudioCopy, PNG, webp, jpeg-xl, jpeg, mp3, aac, mp4, videocopy, audiocopu)
@property (nonatomic) uint16_t imageFormat;
@property (nonatomic) uint16_t effect; //blur, b&w, color, etc
@property (nonatomic) BOOL resize;
//@property (nonatomic)  boolean embedLocation = false;
//@property (nonatomic)  boolean embedExif = false;
@property (nonatomic) uint32_t flags; //@property (nonatomic) so that proguard does not remove it
@property (nonatomic) uint16_t cropGravity;

@property (nonatomic) uint16_t width;
@property (nonatomic) uint16_t height;
@property (nonatomic) uint16_t maxDimension;
@property (nonatomic) uint32_t maxPixels;
@property (nonatomic) uint32_t maxImageSize;
@property (nonatomic) uint32_t maxVideoSize;
@end

@interface MesiboPresence : MesiboMessageProperties
@property (nonatomic) uint32_t presence;
@property (nonatomic) uint32_t value;
@property (nonatomic) uint32_t interval;

-(nonnull id)initWithPeer:(NSString * _Nonnull) peer;
-(nonnull id)initWithGroupId:(uint32_t) groupid;
-(nonnull id)initWithProfile:(MesiboProfile * _Nonnull) profile;

-(int) send:(uint32_t)presence value:(uint32_t) value interval:(uint32_t) interval;
-(int) send:(uint32_t)presence;
-(int) send;
-(int) sendTyping;
-(int) sendTypingCleared;
-(int) sendJoined;
-(int) sendLeft;
-(int) sendOnline;
-(int) sendOffline;
-(int) sendRequest;

-(BOOL) isRequest;
-(BOOL) isOnline;
-(BOOL) isOffline;
-(BOOL) isTyping;
-(BOOL) isTypingCleared;
-(BOOL) isChatting;
-(BOOL) hasJoined;
-(BOOL) hasLeft;
@end

@interface MesiboMessage : MesiboMessageProperties
@property (nonatomic, nullable) NSData *data;
@property (nonatomic, nullable) NSString *title;
@property (nonatomic, nullable) NSString *subtitle;
@property (nonatomic, nullable) NSString *message;
@property (nonatomic, nullable) NSString *footer;

@property (nonatomic) double latitude;
@property (nonatomic) double longitude;

@property (nonatomic, nullable) id asset;
@property (nonatomic, nullable) NSString *localIdentifier;
@property (nonatomic, weak, nullable) id fileTransferContext;

@property (nonatomic)  BOOL copyFiles;
@property (nonatomic)  BOOL urlPreview;
@property (nonatomic)  BOOL urlPreviewServer;
@property (nonatomic)  BOOL urlPreviewCache;
@property (nonatomic)  BOOL urlPreviewShare;

@property (nonatomic)  BOOL extractUrlFromMessage;
@property (nonatomic)  BOOL sendFileName;
@property (nonatomic)  BOOL imageProcessing;
@property (nonatomic)  BOOL sendThumbnail;
@property (nonatomic)  BOOL extractThumbnail; // on receive side
@property (nonatomic)  BOOL sendHqThumbnail;
@property (nonatomic)  BOOL horizontalThumbnail;
@property (nonatomic)  BOOL verticalThumbnail;
@property (nonatomic)  BOOL matureContent; //may be instead of this, we can have level
@property (nonatomic)  BOOL emojify;
@property (nonatomic)  int contentRating;

@property (nonatomic)  BOOL saveImageUrl;
@property (nonatomic)  BOOL saveVideoUrl;
@property (nonatomic)  BOOL saveAudioUrl;
@property (nonatomic)  BOOL saveAllFileUrl;

@property (nonatomic)  uint16_t thumbnailMaxSide;
@property (nonatomic)  double thumbnailAspectRatio;
@property (nonatomic)  uint32_t maxPreviewSize;
@property (nonatomic)  int trackingProtectionLevel;
@property (nonatomic)  uint32_t passthroughSize;
@property (nonatomic)  uint32_t urlTransferSize;
@property (nonatomic)  uint32_t urlPreviewExpiry;
@property (nonatomic)  BOOL secureDownload;
@property (nonatomic)  BOOL openExternally;

@property (nonatomic)  BOOL markForwarded;

+(void) setDefaults:(MesiboMessage * _Nullable) defaults;

-(nonnull id)initWithPeer:(NSString * _Nonnull) peer;
-(nonnull id)initWithGroupId:(uint32_t) groupid;
-(nonnull id)initWithProfile:(MesiboProfile * _Nonnull) profile;
-(void) initDefaults;
-(BOOL) canSend;
-(void) setObject:(nullable id) obj;
-(nullable id) getObject;
-(nullable MesiboMessage *) getRepliedToMessage;
-(BOOL) hasFile;
-(BOOL) isFileReady;
-(BOOL) isFilePending;
-(nullable MesiboFile *) getFile;
-(int) getFileType;
-(nullable NSString *) getMimeType;
-(nullable NSString *) getFileName;
-(long) getFileSize;
-(nullable NSString *) getFilePath;

-(BOOL) isImage;
-(BOOL) isVideo;
-(BOOL) isAudio;
-(BOOL) isDocument;
-(BOOL) hasImage;
-(BOOL) hasVideo;
-(BOOL) hasAudio;
-(BOOL) hasDocument;
-(BOOL) hasLocation;
-(BOOL) hasThumbnail;
-(BOOL) isMatureContent;
-(void) setContentType:(int) type;
-(void) setMediaProperties:(MesiboMediaProperties * _Nonnull)properties;
-(void) setContent:(nonnull id) filePathOrUrlOrImage;
-(void) setThumbnail:(nonnull UIImage *) thumbnail;
-(nullable UIImage *) getThumbnail;
-(BOOL) startFileTransfer:(int) priority;
-(BOOL) stopFileTransfer;
-(BOOL) toggleFileTransfer:(int) priority;
-(BOOL) Mesibo_onFileTransferProgress:(MesiboFileTransfer * _Nonnull) ft;
-(BOOL) isFileTransferInProgress;
-(BOOL) isFileTransferRequired;
-(BOOL) isUploadRequired;
-(BOOL) isDownloadRequired;
-(BOOL) replaceThumbnailImage:(nullable UIImage *) bmp;
-(BOOL) replaceThumbnail:(nonnull NSString *) pathOrUrl;
-(BOOL) replaceThumbnailWithLocation:(int) zoom key:(nullable NSString *)Key;

-(int) send;
-(BOOL) resend;
-(int) sendUpdate;
-(int) sendPresence;
-(int) sendToWebhook;
-(void) setForwarded:(NSArray<NSNumber *> * _Nonnull) fids;
-(void) setForwardedMid:(uint64_t) fid;
-(MesiboMessage * _Nonnull) forward:(MesiboProfile * _Nonnull) profile;
-(MesiboMessage * _Nonnull) reply;
-(MesiboMessage * _Nonnull) replyToPeer;

-(int) save;
-(BOOL) delete;
-(BOOL) wipe;
-(BOOL) recall;
-(BOOL) wipeAndRecall;
-(BOOL) mayBeRetracted;
-(int) getProgress;
-(MesiboMessage * _Nonnull) cloneDate;
-(void) setString:(NSString * _Nonnull)name value:(NSString * _Nonnull) value;
-(void) setLong:(NSString * _Nonnull)name value:(long) value;
-(void) setInt:(NSString * _Nonnull)name value:(int) value;
-(void) setDouble:(NSString * _Nonnull)name value:(double) value;
-(void) setBoolean:(NSString * _Nonnull)name value:(BOOL) value;
-(NSString * _Nullable) getString:(NSString * _Nonnull) name defval:(NSString * _Nullable) defval;
-(long) getLong:(NSString * _Nonnull) name defval:(long) defval;
-(int) getInt:(NSString * _Nonnull) name defval:(int) defval;
-(double) getDouble:(NSString * _Nonnull) name defval:(double) defval;
-(BOOL) getBoolean:(NSString * _Nonnull) name defval:(BOOL) defval;

-(id _Nullable) getUiContext;
-(void) setUiContext:(id _Nullable) context;

#if 0
+(MesiboMessage * _Nonnull) forPeer:(NSString * _Nonnull) peer;
+(MesiboMessage * _Nonnull) forGroup:(uint32_t) gid;
+(MesiboMessage * _Nonnull) forProfile:(MesiboProfile * _Nonnull) profile;
#endif
@end


@interface MesiboReadSession : NSObject
+(MesiboReadSession * _Nullable) getSession:(uint64_t)sessionid;
+(MesiboReadSession * _Nonnull) createReadSummarySession:(id _Nonnull) listener;
+(MesiboReadSession * _Nonnull) createReadSession:(id _Nonnull) listener;

- (uint64_t) getSession;

+(void)endAllSessions;

//private function - only for internal use
-(void)_onsync:(int) count flags:(uint32_t)flags;


-(BOOL) isReading:(MesiboMessageProperties * _Nonnull)params ;

-(id _Nullable) getDelegate:(uint64_t)flags;
-(int) start;
-(void) stop ;
-(void) restart ;

-(int) read:(int)count;
-(void)sync:(int)count listener:(id _Nullable)listener ;
-(void) setThreadId:(uint64_t) tid;
-(void) setQuery:(NSString * _Nullable) query;

-(BOOL) isSummary;
-(MesiboProfile * _Nullable) getProfile;

-(int) getMessageCount:(int) status;
-(int) getTotalMessageCount;
-(int) getSentMessageCount;
-(int) getReceivedMessageCount;
-(int) getUnreadMessageCount;
-(int) getFailedMessageCount;
-(void) enableReadReceipt:(BOOL) enable ;
-(void) enableFifo:(BOOL) enable ;
-(void) enableFiles:(BOOL) enable ;
-(void) enableThreads:(BOOL) enable;
-(void) enableMessages:(BOOL) enable ;
-(void) enableMissedCalls:(BOOL) enable ;
-(void) enableIncomingCalls:(BOOL) enable ;
-(void) enableOutgoingCalls:(BOOL) enable ;
-(void) enableCalls:(BOOL) enable ;

-(void) enableFlagInternalUseOnly:(int)flag enable:(BOOL)enable __deprecated_msg("This function is for internal use only. Use other enable* functions.");

@end

#define MESIBO_HTTPSTATE_UPLOAD     0
#define MESIBO_HTTPSTATE_DOWNLOAD   1
#define MESIBO_HTTPSTATE_DONE       2

@class MesiboHttp; //forward declaration so that we can declare in block definition below
typedef BOOL (^Mesibo_onHTTPProgress)(MesiboHttp * _Nonnull http, int state, int progress);

@interface MesiboHttp : NSObject
@property (nonatomic) NSString * _Nullable url;
@property (nonatomic) NSString * _Nullable proxy;

@property (nonatomic) NSData * _Nullable post;
@property (nonatomic) NSDictionary * _Nullable postBundle;
@property (nonatomic) NSString * _Nullable contentType;

@property (nonatomic) NSString * _Nullable cookie;

@property (nonatomic) NSString * _Nullable caCertificateFile;

@property (nonatomic) NSString * _Nullable downloadFile;

@property (nonatomic) id        _Nullable uploadPhAsset;
@property (nonatomic) NSString * _Nullable uploadLocalIdentifier;

@property (nonatomic) NSString * _Nullable uploadFile;
@property (nonatomic) NSString * _Nullable uploadFileField;
@property (nonatomic) NSString * _Nullable uploadFileOffsetField;
@property (nonatomic) NSString * _Nullable uploadFileName;
@property (nonatomic) NSString * _Nullable uploadFileType;
@property (nonatomic) NSString * _Nullable uploadFileCheckUrl;

@property (nonatomic) NSString * _Nullable extraHeaders;
@property (nonatomic) NSString * _Nullable userAgent;
@property (nonatomic) NSString * _Nullable referrer;
@property (nonatomic) NSString * _Nullable origin;
@property (nonatomic) NSString * _Nullable encoding;
@property (nonatomic) NSString * _Nullable cacheControl;
@property (nonatomic) NSString * _Nullable accept;

@property (nonatomic) int bufferSize;
@property (nonatomic) uint64_t connectionTimeout;
@property (nonatomic) uint64_t headerTimeout;
@property (nonatomic) uint64_t bodyTimeout;

@property (nonatomic) uint64_t downloadOffset;
@property (nonatomic) uint64_t downloadEnd;
@property (nonatomic) uint64_t uploadOffset;
@property (nonatomic) uint64_t uploadEnd;
@property (nonatomic) uint64_t ims;
@property (nonatomic) int maxRedirects;
@property (nonatomic) int maxRetries;

@property (nonatomic) BOOL headerOnly;
@property (nonatomic) BOOL resume;
@property (nonatomic) BOOL noCache;
@property (nonatomic) BOOL concatData;
@property (nonatomic) BOOL notifyOnCompleteOnly;
@property (nonatomic) BOOL onMainThread;

@property (nonatomic) uint64_t ts;

@property (nonatomic) Mesibo_onHTTPProgress _Nullable listener;

@property (nonatomic) int result;
@property (nonatomic) int respCode;
@property (nonatomic) int errorCode;
@property (nonatomic) NSString * _Nullable error;
@property (nonatomic) int state;

@property (nonatomic) int progress;
@property (nonatomic) uint64_t contentLength;
@property (nonatomic) uint64_t offset;

@property (nonatomic) NSString * _Nullable respEncoding;
@property (nonatomic) NSString * _Nullable respDisposition;
@property (nonatomic) NSString * _Nullable respETag;
@property (nonatomic) BOOL respCached;

@property (nonatomic) long contentAge ;
@property (nonatomic) long respFlag;




@property (nonatomic) NSMutableData * _Nullable data;

@property (nonatomic) id _Nullable other; // user data object

@property (nonatomic) dispatch_queue_t _Nullable dispatchQueue;


-(BOOL) execute;
-(BOOL) executeAndWait;
-(void) cancel;
-(NSData * _Nullable) getData;
-(NSString * _Nullable) getDataString;
-(NSString * _Nullable) urlEncode:(nullable NSDictionary *) post;

@end

@interface MesiboServer : NSObject
@property (nonatomic) int type;
@property (nonatomic, nonnull) NSString *host;
@property (nonatomic, nullable) NSString *username;
@property (nonatomic, nullable) NSString *password;
@end


/*
 typedef void (^MesiboConnectionStatusBlock)(int status);
 typedef BOOL (^MesiboMessageFilterBlock)(MesiboParams *params, NSData *data, int type, NSString *url, NSString *tnurl);
 typedef BOOL (^MesiboFileTransferHandlerBlock)(int action, uint64_t mid, MesiboFileInfo *file);
 typedef BOOL (^MesiboFileTransferListenerBlock)(MesiboFileInfo *file);
 //typedef BOOL (^MesiboUserProfileLookupBlock)(NSString *peer, MesiboUserProfile *user);
 */


typedef BOOL (^Mesibo_onHTTPUtilsProgress)(id _Nullable cbdata, int progress, NSString * _Nullable result);
typedef void (^Mesibo_onSetGroupHandler)(uint32_t groupid);
typedef void (^Mesibo_onRunHandler)(void);

@protocol MesiboInitListener <NSObject>
-(void) Mesibo_onInit:(BOOL)started NS_SWIFT_NAME(Mesibo_onInit(started:));
@end

@protocol MesiboDelegate <NSObject>
@required

@optional
-(void) Mesibo_onMessage:(MesiboMessage * _Nonnull)message NS_SWIFT_NAME(Mesibo_onMessage(message:));
-(void) Mesibo_onMessageUpdate:(MesiboMessage * _Nonnull)message NS_SWIFT_NAME(Mesibo_onMessageUpdate(message:));
-(void) Mesibo_onMessageStatus:(MesiboMessage * _Nonnull)message NS_SWIFT_NAME(Mesibo_onMessageStatus(message:));
-(BOOL) Mesibo_onMessageFilter:(MesiboMessage * _Nonnull)message NS_SWIFT_NAME(Mesibo_onMessageFilter(message:));

-(void) Mesibo_onPresence:(MesiboPresence * _Nonnull)message NS_SWIFT_NAME(Mesibo_onPresence(message:));
-(void) Mesibo_onPresenceRequest:(MesiboPresence * _Nonnull)message NS_SWIFT_NAME(Mesibo_onPresenceRequest(message:));

-(void) Mesibo_onConnectionStatus:(NSInteger) status NS_SWIFT_NAME(Mesibo_onConnectionStatus(status:));

-(void) Mesibo_onSync:(MesiboReadSession * _Nonnull)readSession count:(NSInteger)count NS_SWIFT_NAME(Mesibo_onSync(readSession:count:));

-(BOOL) Mesibo_onCall:(uint32_t)peerid callid:(uint32_t)callid profile:(MesiboProfile * _Nonnull)profile flags:(uint64_t)flags;

-(BOOL) Mesibo_onCallStatus:(uint32_t)peerid callid:(uint32_t)callid status:(int)status flags:(uint64_t)flags info:(uint64_t)info resolution:(uint64_t)resolution desc:(NSString * _Nullable)desc;

-(void) Mesibo_onServer:(int)type url:(NSString * _Nullable)url username:(NSString * _Nullable)username credential:(NSString * _Nullable)credential;

-(void) Mesibo_onConfParitcipant:(uint32_t)uid sid:(uint32_t)sid address:(NSString * _Nullable)address name:(NSString * _Nullable)name role:(uint32_t) role flags:(uint32_t) flags callflags:(uint32_t) callflags;

-(void) Mesibo_onConfCall:(uint32_t)uid sid:(uint32_t)sid op:(int)op source:(uint32_t)source resolution:(uint32_t)resolution fps:(int)fps bw:(uint32_t)bw flags:(uint32_t)flags sdp:(NSString * _Nullable)sdp mid:(NSString * _Nullable)mid mline:(int) mline;

-(BOOL) Mesibo_onStartFileTransfer:(MesiboFileTransfer * _Nonnull)ft NS_SWIFT_NAME(Mesibo_onStartFileTransfer(ft:));
-(BOOL) Mesibo_onStopFileTransfer:(MesiboFileTransfer * _Nonnull) ft NS_SWIFT_NAME(Mesibo_onStopFileTransfer(ft:));

-(BOOL) Mesibo_onFileTransferProgress:(MesiboFileTransfer * _Nonnull) ft;


-(void) Mesibo_onProfileUpdated:(MesiboProfile * _Nonnull)profile NS_SWIFT_NAME(Mesibo_onProfileUpdated(profile:));

-(void) Mesibo_onGroupCreated:(MesiboProfile * _Nonnull) groupProfile NS_SWIFT_NAME(Mesibo_onGroupCreated(groupProfile:));
-(void) Mesibo_onGroupJoined:(MesiboProfile * _Nonnull) groupProfile NS_SWIFT_NAME(Mesibo_onGroupJoined(groupProfile:));
-(void) Mesibo_onGroupLeft:(MesiboProfile * _Nonnull) groupProfile NS_SWIFT_NAME(Mesibo_onGroupLeft(groupProfile:));
-(void) Mesibo_onGroupMembers:(MesiboProfile * _Nonnull) groupProfile members:(NSArray<MesiboGroupMember *> * _Nonnull)members NS_SWIFT_NAME(Mesibo_onGroupMembers(groupProfile:members:));
-(void) Mesibo_onGroupMembersJoined:(MesiboProfile * _Nonnull) groupProfile members:(NSArray<MesiboGroupMember *> * _Nonnull)members NS_SWIFT_NAME(Mesibo_onGroupMembersJoined(groupProfile:members:));
-(void) Mesibo_onGroupMembersRemoved:(MesiboProfile * _Nonnull) groupProfile members:(NSArray<MesiboGroupMember *> * _Nonnull)members NS_SWIFT_NAME(Mesibo_onGroupMembersRemoved(groupProfile:members:));
-(void) Mesibo_onGroupSettings:(MesiboProfile * _Nonnull) groupProfile settings:(MesiboGroupSettings * _Nonnull)settings permissions:(MesiboMemberPermissions * _Nonnull)permissions pins:(NSArray<MesiboGroupPin *> * _Nullable) pins NS_SWIFT_NAME(Mesibo_onGroupSettings(groupProfile:settings:permissions:pins:));
-(void) Mesibo_onGroupError:(MesiboProfile * _Nonnull) groupProfile error:(uint32_t)error NS_SWIFT_NAME(Mesibo_onGroupError(groupProfile:error:));

-(void) Mesibo_onEndToEndEncryption:(MesiboProfile * _Nonnull)profile status:(int)status NS_SWIFT_NAME(Mesibo_onEndToEndEncryption(profile:status:));

//UI helper
//-(void) Mesibo_onShowProfilesList;
-(void) Mesibo_onForeground:(id _Nonnull)parent screenId:(int)screenId foreground:(BOOL)foreground NS_SWIFT_NAME(Mesibo_onForeground(parent:screenId:foreground:));


@end

#define MesiboInstance [Mesibo getInstance]
#define MesiboE2EInstance [[Mesibo getInstance] e2ee]
#define MesiboE2EEInstance [[Mesibo getInstance] e2ee]



@interface Mesibo : NSObject

+(Mesibo * _Nonnull) getInstance;

//********************** Init ************************************************
//-(void) someInit; //TBD
-(void) reset;
-(BOOL) setPath:(NSString * _Nullable)path;
-(NSString * _Nonnull) getAppIdForAccessToken;
-(int) setAccessToken:(NSString * _Nullable)accessToken;
-(int) setPushToken:(NSString * _Nonnull)pushToken voip:(BOOL)voip;
-(void) setPushRegistryCompletion:(nullable void (^)(void))completion;
-(uint32_t) getAccessTokenValidity;
-(int) setBufferLen:(int)length empty:(BOOL)empty;
-(void) setConfiuration:(uint32_t) type value:(uint32_t)value;
-(void) setConfiuration:(uint32_t) type svalue:(nullable NSString *)svalue;
//********************** Listner *********************************************
//both are same functions, setDelegate is more common in iOS world
-(BOOL) setDelegate:(nonnull id)delegate __deprecated_msg("Use addListener instead.");;
-(nullable id) getDelegates;
-(BOOL) addListener:(nonnull id)delegate;
-(BOOL) removeListner:(nonnull id)delegate;

//********************** Live Connection **************************************
-(int) start;
-(int) stop;
-(BOOL) reconnect:(int) inFocus;
-(BOOL) isAccountSuspended;
-(BOOL) isAccountPaid;
-(int) getConnectionStatus;
-(BOOL) isOnline;
-(void)setNetwork:(int)connectivity;
-(int) getDeviceType;
-(uint32_t) getUid;
-(nonnull NSString *) getAddress;
-(void) setAppName:(nonnull NSString *)name ;
-(nonnull NSString *) getAppName;
-(nonnull MesiboEndToEndEncryption *) e2ee;

-(nonnull MesiboPhoneContactsManager *) getPhoneContactsManager;
-(nonnull MesiboLocationManager *) getLocationManager;


//********************** Push Handler **************************************
-(void) didReceiveRemoteNotification:(nullable NSDictionary *)userInfo fetchCompletionHandler:(nullable void (^)( UIBackgroundFetchResult))completionHandler;
//-(void) didReceiveIncomingPushWithPayload:(PKPushPayload *)payload forType:(PKPushType)type withCompletionHandler:(void (^)(void))completion;

//********************** Database **********************************************
//-(BOOL) setDatabase:(nullable NSString *)name resetTables:(uint32_t)resetTables __deprecated_msg("Use setDatabase(name) instead.");
-(BOOL) setDatabase:(nullable NSString *)name;
-(void) resetDatabase:(uint32_t) tables;
-(NSString * _Nonnull) getDatabasePath;
-(NSString * _Nonnull) getDatabaseBackupPath:(nullable NSString *)path;
-(NSString * _Nonnull) backupDatabase:(nonnull NSString *)path;
-(NSString * _Nonnull) backupDatabase:(nonnull NSString *)path age:(uint32_t)age;

-(int) restoreDatabase:(NSString * _Nonnull)path;
-(int) databaseAge;
-(int) backupAge;
-(BOOL) isFirstInstall;

-(BOOL) setKey:(NSString * _Nonnull)key value:(NSString * _Nonnull)value;
-(nullable NSString *) readKey:(NSString * _Nonnull)key;
-(BOOL) deleteKey:(NSString * _Nonnull)key;


//********************** Status and Information *********************************
-(NSString * _Nonnull) getBasePath;
-(NSString * _Nonnull) getFilePath:(int)type sent:(BOOL) sent;
-(nullable NSString *) getImagePath:(BOOL) sent;
-(nullable NSString *) getVideoPath:(BOOL) sent;
-(nullable NSString *) getAudioPath:(BOOL) sent;
-(nullable NSString *) getDocumentPath:(BOOL) sent;
-(void) setForegroundContext:(id _Nonnull)context screenId:(int)screenId foreground:(BOOL)foreground;
-(BOOL) setAppInForeground:(id _Nonnull)context screenId:(int)screenId foreground:(BOOL)foreground;
-(nullable id) getForegroundContext;
-(BOOL) isAppInForeground;
-(NSString * _Nonnull) version; // TBD

// Time
-(uint64_t) getTimestamp;
-(uint64_t) getStartTimestamp;
-(int) daysElapsed:(uint64_t) ts;

//********************** Messaging ************************************************

-(MesiboMessage * _Nullable) getMessage:(uint64_t) mid;


-(int) cancel:(int)type msgid:(uint32_t)msgid;
//-(void) enableAutoSendOnlineStatus:(BOOL)enable;
-(void) setOnlineStatusMode:(int) mode;
-(void) setOnlinestatusTarget:(uint32_t) gid;
-(void) setOnlineStatusPrivacy:(int) privacy;

-(int) setMessageRetractionInterval:(uint32_t) interval;
-(int) getMessageRetractionInterval;
-(int) setMessageRetractionPolicy:(uint32_t) policy;
-(int) setRemoteRetractionPolicy:(uint32_t) policy;

-(BOOL) wipeAndRecallMessages:(uint64_t * _Nonnull)msgids count:(int)count;
-(BOOL) wipeAndRecallMessage:(uint64_t)msgid;
-(BOOL) wipeMessages:(uint64_t * _Nonnull)msgids count:(int)count remote:(BOOL)remote;
-(BOOL) wipeMessages:(uint64_t * _Nonnull)msgids count:(int)count;
-(BOOL) wipeMessage:(uint64_t)msgid;
-(BOOL) deleteMessages:(uint64_t * _Nonnull)msgids count:(int)count remote:(BOOL)remote;
-(BOOL) deleteMessages:(uint64_t * _Nonnull)msgids count:(int)count;
-(BOOL) deleteMessage:(uint64_t)msgid remote:(BOOL)remote;
-(BOOL) deleteMessage:(uint64_t)msgid;
-(BOOL) deleteMessages:(uint64_t) ts;
-(BOOL) deleteMessagesOlderThan:(uint32_t) seconds;

-(BOOL) deleteZombieMessages:(BOOL) groupOnly;
//-(void)setEnableReadReceipt:(BOOL)enable sendLastReceipt:(BOOL)sendLastReceipt;
-(int) sendReadReceipt:(MesiboMessageProperties * _Nonnull)p msgid:(uint64_t)msgid;
//-(id) getMessageFilter; //TBD, not implemented in IOS
-(BOOL) isReading:(MesiboMessageProperties * _Nonnull)p;

//********************** File Transfer ********************************************

-(BOOL) isFileTransferEnabled;
-(void) enableFileTransfer:(BOOL) enable;
-(NSString * _Nullable) getUploadUrl;
-(NSString * _Nullable) getUploadAuthToken;
-(void) setUploadUrl:(NSString * _Nullable)url authToken:(NSString * _Nullable) authToken;
-(int) getFileType:(NSString * _Nonnull)path;

//********************** User Profile *********************************************

-(MesiboProfile * _Nonnull) getProfile:(NSString * _Nullable)peer groupid:(uint32_t)groupid;
-(MesiboProfile * _Nullable) getProfileIfExists:(NSString * _Nullable)peer groupid:(uint32_t)groupid;
-(MesiboProfile * _Nonnull) getUserProfile:(NSString * _Nullable)peer;
-(MesiboProfile * _Nonnull) getGroupProfile:(uint32_t)groupid;
-(MesiboProfile * _Nonnull) getProfileFromParams:(MesiboMessageProperties * _Nonnull)params;

-(MesiboProfile * _Nullable) getUserProfileIfExists:(NSString * _Nonnull)peer;
-(MesiboProfile * _Nullable) getGroupProfileIfExists:(uint32_t)groupid;

-(MesiboSelfProfile * _Nonnull) getSelfProfile;



-(BOOL) createGroup:(NSString * _Nonnull)name flags:(uint32_t) flags listener:(id _Nullable)listener;
-(BOOL) createGroup:(MesiboGroupSettings * _Nonnull)settings listener:(id _Nullable)listener;

-(int) subscribeTransient:(NSArray<NSString *> * _Nonnull) addresses type:(uint32_t)type activity:(uint32_t)activity duration:(uint32_t)duration;

-(void) hideInactiveGroupProfiles:(BOOL) reset;
-(NSArray * _Nonnull) getSortedProfiles;
-(NSArray * _Nonnull) getRecentProfiles;
-(uint64_t) getLastProfileUpdateTimestamp;

-(void) resetProfileCustomizations;

//********************** Utility Functions *********************************************

//-(uint32_t) random __deprecated_msg("Use getUniqueMessageId instead.");
-(uint32_t) getUniqueMessageId;
-(uint32_t) getSenderMessageId:(uint64_t)mid;

-(BOOL) createFile:(NSString * _Nonnull)path fileName:(NSString * _Nonnull)fileName data:(NSData * _Nonnull)data overwrite:(BOOL)overwrite;
-(BOOL) createPath:(NSString * _Nonnull)path;
-(BOOL) fileExists:(NSString * _Nonnull)fileName;
-(BOOL) deleteFile:(NSString * _Nonnull)path;
-(NSString * _Nonnull) getFileName:(NSString * _Nonnull) path;
-(BOOL) renameFile:(NSString * _Nonnull)srcFile destFile:(NSString * _Nonnull)destFile forced:(BOOL) forced ;


-(BOOL) isUiThread;
-(void) runInThread:(BOOL)uiThread handler:(Mesibo_onRunHandler _Nonnull) handler;
-(void) queueInThread:(BOOL)uiThread handler:(Mesibo_onRunHandler _Nonnull) handler;
-(void) queueInThread:(BOOL)uiThread delay:(int64_t)delay_ms handler:(Mesibo_onRunHandler _Nonnull) handler;
-(nullable UIImage *) loadImage:(UIImage * _Nullable)image filePath:(NSString * _Nullable)path maxside:(int)maxside;

-(MesiboProfile * _Nullable) getActiveCall;
-(MesiboProfile * _Nullable) getActiveP2PCall;
-(MesiboProfile * _Nullable) getActiveGroupCall;

//********************** Network.HTTP(S) Functions *********************************************
-(int) getNetworkConnectivity;

#if 0
-(NSString *) fetch_deprecated:(NSString *)url post:(NSDictionary *)post filePath:(NSString *) filePath;
-(int) upload_deprecated:(NSString *)url filePath:(NSString *)filePath fileField:(NSString*)fileField post:(NSDictionary *)post  progress:(Mesibo_onHTTPUtilsProgress)progress cbdata:(id) cbdata;
-(int) upload_deprecated:(NSString *)url phAsset:(id)phAsset fileField:(NSString *)fileField post:(NSDictionary *)post progress:(Mesibo_onHTTPUtilsProgress)progress cbdata:(id)cbdata;
-(int) download_deprecated:(NSString *)url filePath:(NSString *)filePath post:(NSDictionary *)post  progress:(Mesibo_onHTTPUtilsProgress)progress cbdata:(id) cbdata;
//-(NSString *)fetch:(NSString *)url post:(NSDictionary *)post filePath:(NSString *)filePath fileField:(NSString*)fileField;
#endif


//********************** UI Functions *********************************************
//-(BOOL) setMessageWidthInPercent:(int) percent;
//-(int) getMessageWidthInPoints;


+ (void) Log:(const char* _Nullable)sourceFile lineNumber:(int)lineNumber format:(NSString* _Nonnull)format, ...;
+ (void) Log:(NSString* _Nonnull)format, ...;

-(void) setCallInterface:(int)type ci:(void * _Nullable) ci;
-(int) call:(NSString * _Nonnull)phone video:(BOOL)video;
-(int) answer:(uint32_t)callid video:(BOOL)video waiting:(BOOL)waiting;
-(int) call_ack:(BOOL)cis;
-(int) call_info:(uint64_t)info width:(uint16_t)width height:(uint16_t) height;
-(uint32_t) getCallId;
-(BOOL) isCallWaiting;
-(int) mute:(BOOL)audio video:(BOOL)video enable:(BOOL)enable;
-(int) hold:(BOOL)enable;
-(int) dtmf:(int)digit;
-(int) hangup:(uint32_t)callid waiting:(BOOL)waiting;
-(int) getMuteStatus;
-(void) setCallProcessing:(int)rejectStatus currentStatus:(int)currentStatus;
-(void) setCallStatus:(int)type sdp:(NSString * _Nullable)sdp;
-(void) setCallQueue:(id _Nullable)q;
-(void) requestBackgroundTime;
-(void) remlog_start:(NSString * _Nullable)host port:(int) port;
-(void) remlog:(NSString * _Nullable)log;
//-(MesiboServer *) getServer:(int)type;

// INTERNAL USE ONLY - NOT TO BE USED


// INTERNAL USE ONLY - DO NOT invoke these functions directly
-(int) groupcall_start:(uint32_t) groupid;
-(int) groupcall_stop:(uint32_t) groupid;
-(int) groupcall_create_participant:(uint32_t) sid flags:(uint32_t) flags;
-(int) groupcall_call:(uint32_t)peer sid:(uint32_t)sid flags:(uint32_t)flags resolution:(uint32_t)resolution screen:(BOOL)screen;
-(int) groupcall_hangup:(uint32_t)peer sid:(uint32_t) sid;
-(int) groupcall_set_media:(uint32_t)peer sid:(uint32_t)sid resolution:(uint32_t)resolution screen:(BOOL)screen;
-(int) groupcall_mute:(uint32_t)peer sid:(uint32_t)sid video:(BOOL)video audio:(BOOL)audio mute:(BOOL)mute;
-(int) groupcall_sdp:(uint32_t)peer sid:(uint32_t)sid resolutioon:(uint32_t)resolution type:(int)type sdp:(NSString * _Nullable)sdp mid:(NSString * _Nullable)mid mline:(int) mline;
-(void) groupcall_admin:(uint16_t)o flags:(uint16_t)flags source:(uint32_t)source index:(uint16_t)index tuid:(uint32_t)tuid tsid:(uint32_t)tsid us:(uint32_t * _Nullable)us ss:(uint32_t * _Nullable)ss count:(int)count;
-(void) groupcall_fyi:(uint32_t)sid source:(uint32_t)source status:(NSString * _Nullable)status;

/*
 
 //+(NSString *)callstatusToString:(int) status;
 
 //-(void) setOnAlert:(MesiboAlertBlock) alertBlock;
 //-(void) setOnLogout:(MesiboLogoutBlock) onLogoutBlock;
 -(int) call:(NSString *)phone
 withHandler:(MesiboCallBlock) completionHandler;
 -(void) dtmf:(int)digit;
 -(void) hangup;
 -(void) mute:(BOOL)OnOrOff;
 -(void) routeAudio:(int)route OnOrOff:(BOOL)state;
 -(int) getCharges:(float *)charge;
 */

@end

@protocol MesiboLocationListener <NSObject>
-(void) Mesibo_onDeviceLocation:(MesiboLocation * _Nonnull) location NS_SWIFT_NAME(Mesibo_onDeviceLocation(location:));
-(void) Mesibo_onLocationReceived:(MesiboProfile * _Nonnull)profile NS_SWIFT_NAME(Mesibo_onLocationReceived(profile:));
-(void) Mesibo_onLocationRequest:(MesiboProfile * _Nonnull)profile duration:(uint32_t)duration  NS_SWIFT_NAME(Mesibo_onLocationRequest(profile:duration:));
-(void) Mesibo_onLocationShared:(MesiboProfile * _Nonnull)profile duration:(uint32_t)duration  NS_SWIFT_NAME(Mesibo_onLocationRequest(profile:duration:));
-(void) Mesibo_onLocationError:(MesiboProfile * _Nonnull)profile error:(int)error  NS_SWIFT_NAME(Mesibo_onLocationError(profile:error:));
@end

@protocol MesiboProfileSearchListener <NSObject>
-(void) Mesibo_onProfileSearchResults:(NSArray<MesiboProfile *> * _Nonnull) profiles search:(MesiboProfileSearch * _Nonnull) search NS_SWIFT_NAME(Mesibo_onProfileSearchResults(profiles:search:));
-(void) Mesibo_onProfileSearchUpdate:(NSArray<MesiboProfile *> * _Nonnull) profiles search:(MesiboProfileSearch * _Nonnull) search NS_SWIFT_NAME(Mesibo_onProfileSearchUpdate(profiles:search:));
@end


@interface MesiboProfileSearch : NSObject
-(uint64_t) getRequestId;
-(void) setListener:(id<MesiboProfileSearchListener> _Nonnull) listener;
-(void) subscribe:(uint32_t)duration;
-(void) enableGroupSearch:(BOOL)groupSearch;
-(void) enableContactSearch:(BOOL) contactSearch;
-(void) setLocation:(double)lat lon:(double)lon;
-(void) setCurrentLocation;
-(void) setDistance:(uint32_t)distance;
-(void) setMaxAge:(uint32_t)age;
-(BOOL) search;
-(BOOL) searchMore;
-(NSArray<MesiboProfile *> * _Nullable) getLastSearchResult;
-(void) clearSearchResult;
@end

@interface MesiboLocationManager : NSObject
+(MesiboLocationManager * _Nonnull) getInstance;

-(BOOL) start:(MesiboLocationConfig * _Nullable) config;
-(BOOL) start;
-(void) stop;
-(BOOL) addListener:(id<MesiboLocationListener> _Nonnull) listener;
-(void) removeListener:(id<MesiboLocationListener> _Nonnull) listener;

-(BOOL) setLocation:(MesiboLocation * _Nonnull) location timeout:(uint32_t) timeout;
-(BOOL) setLocation:(MesiboLocation * _Nonnull) location;
-(BOOL) resetLocation;

-(MesiboLocation * _Nullable) getDeviceLocation;
-(MesiboLocation * _Nullable) getCustomLocation;
-(MesiboLocation * _Nullable) getLocation;

-(void) setAccessLevels:(NSArray<NSNumber *> * _Nullable) accessLevels;

-(void) setSearchableDistance:(uint32_t) distance;

-(void) startDistanceTracking:(uint32_t)duration;
-(void) startDistanceTracking;
-(void) stopDistanceTracking;
-(double) getDistanceCovered;
@end

#ifdef MESIBO_NOLOGS
#define NSLog(args, ...) do {} while(0)
#endif
