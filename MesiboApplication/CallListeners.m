//
//  CallListeners.m
//  MesiboApplication
//

#import "CallListeners.h"
#import "SampleAppNotify.h"

@implementation CallListeners

+ (CallListeners *)getInstance {
    static CallListeners *instance = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ instance = [CallListeners new]; });
    return instance;
}

+ (void)start {
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        [MesiboCall startWith:[self getInstance] name:@"mesibo" icon:nil callKit:YES];
        [MesiboCallInstance addCallMonitorListener:[self getInstance]];
    });
}

#pragma mark - MesiboCallIncomingListener

- (MesiboCallProperties *)MesiboCall_OnIncoming:(MesiboProfile *)profile video:(BOOL)video waiting:(BOOL)waiting {
    return [MesiboCallInstance createCallProperties:video];
}

- (BOOL)MesiboCall_OnShowUserInterface:(id)call properties:(MesiboCallProperties *)cp {
    return NO;
}

- (void)MesiboCall_OnError:(MesiboCallProperties *)cp error:(int)error {
}

- (BOOL)MesiboCall_OnNotify:(int)type profile:(MesiboProfile *)profile video:(BOOL)video ts:(MesiboDateTime *)ts {
    if (MESIBOCALL_NOTIFY_MISSED == type) {
        NSString *message = [NSString stringWithFormat:@"You missed a mesibo %@call from %@", video ? @"video " : @"", [profile getNameOrAddress]];
        [SampleAppNotifyInstance notify:SAMPLEAPP_NOTIFYTYPE_OTHER subject:@"Mesibo Missed Call" message:message];
    }
    return YES;
}

#pragma mark - MesiboCallMonitorListener

- (void)MesiboCall_onCallStarted:(MesiboProfile *)profile incoming:(BOOL)incoming video:(BOOL)video {
    [MesiboUI updateScreens];
}

- (void)MesiboCall_onCallEnded:(MesiboProfile *)profile incoming:(BOOL)incoming video:(BOOL)video {
    [MesiboUI updateScreens];
}

@end
