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
#import <UserNotifications/UserNotifications.h>

// both defined 0, sync up with Android
#define SAMPLEAPP_NOTIFYTYPE_MESSAGE    0
#define SAMPLEAPP_NOTIFYTYPE_OTHER    0

#define SampleAppNotifyInstance [SampleAppNotify getInstance]


@interface SampleAppNotify : NSObject <UNUserNotificationCenterDelegate, MesiboDelegate>

+(SampleAppNotify *) getInstance;

-(void) notify:(int)type subject:(NSString *)subject message:(NSString *)message;
-(void) notifyMessage:(MesiboMessage *)msg;
-(void) clear;
@end
