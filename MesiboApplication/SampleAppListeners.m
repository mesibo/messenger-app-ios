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

#import "SampleAppListeners.h"
#import "SampleAPI.h"
#import "NSDictionary+NilObject.h"
#import "UIManager.h"
#import "AppUIManager.h"
#import "SampleAppNotify.h"
#import "AppAlert.h"
#import "MesiboCall/MesiboCall.h"

@implementation SampleAppListeners

+(SampleAppListeners *)getInstance {
    static SampleAppListeners *myInstance = nil;
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
    [MesiboInstance addListener:self];
    //[MesiboCallInstance setListener:self];
}

-(void) Mesibo_onMessage:(MesiboMessage *)msg {
    if([MesiboInstance isReading:msg])
        return;
    

    //TBD, we need to handle missed and incoming call from here
    //currently done from MesiboCall_onNotifyIncoming (below)
    if([msg isCall]) return;
    
    [SampleAppNotifyInstance notifyMessage:msg];
}

-(void) Mesibo_onConnectionStatus:(NSInteger)status {
    
    NSLog(@"Connection status: %d", (int) status);
    
    if (MESIBO_STATUS_SIGNOUT == status) {
        //TBD, inform user
        [AppAlert showDialogue:@"You have been loggeed out from this device since you loggedin from another device." withTitle:@"Logged out"];
        
        [SampleAPIInstance logout:YES parent:nil];
        
    } else if (MESIBO_STATUS_AUTHFAIL == status) {
        [SampleAPIInstance logout:YES parent:nil];
    }
    
    if(MESIBO_STATUS_ONLINE == status) {
        [SampleAPIInstance startOnlineAction];
    }
    
    
}


-(void) Mesibo_onGroupJoined:(MesiboProfile *) groupProfile {
    NSString *msg = [NSString stringWithFormat:@"You have been added to the group %@", [groupProfile  getName]];
    [SampleAppNotifyInstance notify:SAMPLEAPP_NOTIFYTYPE_OTHER subject:@"New group" message:msg];
}

-(BOOL) Mesibo_onGetProfile:(MesiboProfile *)profile {
    return YES;
}

- (void)MesiboUI_onShowProfile:(id)parent profile:(MesiboProfile *)profile {
    [AppUIManager launchProfile:parent profile:profile];
}

-(BOOL) Mesibo_onMessageFilter:(MesiboMessage *)msg {
        return YES;
}

-(void) Mesibo_onForeground:(id)parent screenId:(int)screenId foreground:(BOOL)foreground {
    //userlist is in foreground
    if(foreground && 0 == screenId) {
        //notify count clear
        [SampleAppNotifyInstance clear];
    }
    
}

-(BOOL) MesiboCall_onNotifyIncoming:(int)type profile:(MesiboProfile *)profile video:(BOOL)video {
    NSString *n = nil;
    NSString *subj = nil;
    if(MESIBOCALL_NOTIFY_INCOMING == type) {
        subj = @"Mesibo Incoming Call";
        n = [NSString stringWithFormat:@"Mesibo %scall from %@", video?"Video ":"", [profile getName]];
    } else if(MESIBOCALL_NOTIFY_MISSED == type) {
        subj = @"Mesibo Missed Call";
        n = [NSString stringWithFormat:@"You missed a Mesibo %scall from %@", video?"Video ":"", [profile getName]];
    }
    
    if(n) {
        [MesiboInstance runInThread:YES handler:^{
            [SampleAppNotifyInstance notify:2 subject:subj message:n];
        }];
    }
    
    return YES;
}

- (void)MesiboCall_OnError:(MesiboCallProperties * _Nonnull)cp error:(int)error {
    
}

- (MesiboCallProperties * _Nullable)MesiboCall_OnIncoming:(MesiboProfile * _Nonnull)profile video:(BOOL)video waiting:(BOOL)waiting {
    MesiboCallProperties *cp = [MesiboCallInstance createCallProperties:video];
    
    //cp.parent = self.window.rootViewController;
    
    // any customizations goes here
    return cp;
    
}

- (BOOL)MesiboCall_OnNotify:(int)type profile:(MesiboProfile * _Nonnull)profile video:(BOOL)video ts:(MesiboDateTime * _Nonnull) ts {
    return NO;
}

- (BOOL)MesiboCall_OnShowUserInterface:(id)call properties:(MesiboCallProperties *)cp {
    
    // Show your own UI or return NO to show the default user interface
    
    return NO;

}

@end
 
