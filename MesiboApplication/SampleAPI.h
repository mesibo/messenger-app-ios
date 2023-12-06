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

#import <Foundation/Foundation.h>
#import "Mesibo/Mesibo.h"


@interface SampleAPIRespose : NSObject
@property (nonatomic) NSString *result;
@property (nonatomic) NSString *op;
@property (nonatomic) NSString *error;
@property (nonatomic) NSString *token;

@property (nonatomic) NSString *name;
@property (nonatomic) NSString *status;
@property (nonatomic) NSString *photo;
@property (nonatomic) NSString *invite;
@property (nonatomic) uint32_t gid;
@property (nonatomic) int type;
@end

#define SAMPLEAPP_RESULT_OK         0
#define SAMPLEAPP_RESULT_FAIL       1
#define SAMPLEAPP_RESULT_AUTHFAIL   2


#define VISIBILITY_HIDE         0
#define VISIBILITY_VISIBLE      1
#define VISIBILITY_UNCHANGED    2

typedef void (^SampleAPI_LogoutBlock)(id parent);
typedef void (^SampleAPI_onResponse)(int result, NSDictionary *response);
typedef void (^SampleAPI_onUpdate)(BOOL update);

#define SampleAPIInstance [SampleAPI getInstance]

@interface SampleAPI : NSObject

+(SampleAPI *) getInstance;

-(void) initialize;
-(void) setOnLogout:(SampleAPI_LogoutBlock)logOutBlock;
-(NSString *) getToken;
-(NSString *) getPhone;
-(NSString *) getApiUrl;
-(NSString *) getUploadUrl;
-(NSString *) getDownloadUrl;
-(NSString *) getInvite;
-(NSString *) getNotice;
-(NSString *) getNoticeTitle;


-(void) startMesibo:(BOOL) resetProfiles;
-(void) startContactSync;
-(NSString *) getSyncedContacts;

-(void) resetDB;
-(void) logout:(BOOL) forced parent:(id)parent;
-(void) login:(NSString *)phone code:(NSString *)code handler:(SampleAPI_onResponse) handler;
-(BOOL) deleteGroup:(uint32_t) groupid handler:(SampleAPI_onResponse) handler ;

-(void) setAPNToken:(NSString *) token;
-(void) setMediaAutoDownload:(BOOL)autoDownload;
-(BOOL) getMediaAutoDownload;

+(BOOL) isEmpty:(NSString *)string; //utility
+(BOOL) equals:(NSString *)s old:(NSString *)old;

-(void) startOnlineAction;

@end
