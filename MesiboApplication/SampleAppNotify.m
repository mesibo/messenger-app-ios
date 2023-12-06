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

#import "SampleAppNotify.h"

//https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/RemoteNotificationsPG/index.html#//apple_ref/doc/uid/TP40008194-CH3-SW1
@implementation SampleAppNotify 

+(SampleAppNotify *)getInstance {
    static SampleAppNotify *myInstance = nil;
    if(nil == myInstance) {
        @synchronized(self) {
            if (nil == myInstance) {
                myInstance = [[self alloc] init];
                [myInstance initialize];
            }
        }
    }
    return myInstance;
}

-(void) initialize {
    UNUserNotificationCenter* center = [UNUserNotificationCenter currentNotificationCenter];
    [center requestAuthorizationWithOptions:(UNAuthorizationOptionBadge | UNAuthorizationOptionAlert | UNAuthorizationOptionSound | UNAuthorizationOptionBadge)
                          completionHandler:^(BOOL granted, NSError * _Nullable error) {
        //NSLog(@"Notify auth %d", granted?1:0);
                          }];
    
}


-(void) notify:(int)type subject:(NSString *)subject message:(NSString *)message {
    if(![message length]) return;
    
    UNMutableNotificationContent *content = [[UNMutableNotificationContent alloc] init];
    content.title = subject;
    content.body = message;
    content.sound = [UNNotificationSound defaultSound];
    //Set Badge Number
    content.badge = @([[UIApplication sharedApplication] applicationIconBadgeNumber] + 1);
    content.categoryIdentifier = [NSString stringWithFormat:@"%d", type];

    
    // Deliver the notification in five seconds.
    UNTimeIntervalNotificationTrigger* trigger = [UNTimeIntervalNotificationTrigger triggerWithTimeInterval:1.f repeats:NO];
    UNNotificationRequest* request = [UNNotificationRequest requestWithIdentifier:@"LocalNotification" content:content trigger:trigger];
    
    // Schedule the notification.
    UNUserNotificationCenter* center = [UNUserNotificationCenter currentNotificationCenter];
    [center addNotificationRequest:request withCompletionHandler:^(NSError * _Nullable error) {
        //NSLog(@"Notification Completed: %@", error);
    }];
    
}

-(void) notifyMessage:(MesiboMessage *)msg {
    if(![msg isRealtimeMessage] || [msg isInOutbox] || [msg isOutgoing])
        return;
    
    if(!msg.profile) return;
    
    if([msg.profile isMuted])
        return;
            
    NSString *name = [msg.profile getName];
    
    if(nil == name)
        return;
    
    if(msg.groupProfile) {
        if([msg.groupProfile isMuted])
            return;
        
        name = [NSString stringWithFormat:@"%@ @ %@", name, [msg.groupProfile getName]];
    }
    
    NSString *message = msg.message;
    if(!message || !message.length)
        message = msg.title;
    if(!message || !message.length) {
        if([msg hasImage]) {
            message = @"Picture";
        }
        else if([msg hasVideo]) {
            message = @"Video";
        }
        else if([msg hasAudio]) {
            message = @"Audio";
        }
        else if([msg hasDocument]) {
            message = @"Attachment";
        }
        else if([msg hasLocation]) {
            message = @"Location";
        }
    }
    
    if(!message || !message.length) {
        return;
    }
    
    [self notify:SAMPLEAPP_NOTIFYTYPE_MESSAGE subject:name message:message];
    return;
}

-(void) clear {
    [[UNUserNotificationCenter currentNotificationCenter] removeAllDeliveredNotifications];
}

@end
