//
//  SampleAppNotify.h
//  TestMesiboUI
//
//  Created by John on 24/03/17.
//  Copyright © 2018 Mesibo. All rights reserved.
//

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
