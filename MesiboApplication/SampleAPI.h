//
//  SampleAPI.h
//  MesiboApplication
//
//  The app's backend (the messenger server, MessengerApiUrl in Info.plist): login and logout,
//  and starting mesibo with the user's token. Also keeps the app's settings.
//

#import <Foundation/Foundation.h>
#import <mesibo/Mesibo.h>

// results of the API calls
#define SAMPLEAPP_RESULT_OK         0
#define SAMPLEAPP_RESULT_FAIL       1
#define SAMPLEAPP_RESULT_AUTHFAIL   2

typedef void (^SampleAPI_LogoutBlock)(id parent);
typedef void (^SampleAPI_onResponse)(int result, NSDictionary *response);

#define SampleAPIInstance [SampleAPI getInstance]

@interface SampleAPI : NSObject

/** the instance; starts mesibo when the user signed in before */
+(SampleAPI *) getInstance;

-(void) setOnLogout:(SampleAPI_LogoutBlock)logOutBlock;
-(NSString *) getToken;
-(NSString *) getPhone;
-(NSString *) getInvite;
-(NSString *) getUploadUrl;
/** a notice from the server (e.g. limits of the demo) */
-(NSString *) getNotice;
-(NSString *) getNoticeTitle;

/** finds which phone contacts use the app (once per start) */
-(void) startContactSync;

/** without code: asks for a code; with code: signs in */
-(void) login:(NSString *)phone code:(NSString *)code handler:(SampleAPI_onResponse) handler;
/** forced: sign out here only, without telling the server */
-(void) logout:(BOOL) forced parent:(id)parent;

/** notifications for messages / group messages (Settings) */
-(BOOL) getMessageNotification;
-(void) setMessageNotification:(BOOL)enable;
-(BOOL) getGroupMessageNotification;
-(void) setGroupMessageNotification:(BOOL)enable;

/** the login response says the user has no profile yet (new_user) */
+(BOOL) isNewUser:(NSDictionary *)response;

+(BOOL) isEmpty:(NSString *)string;

@end
