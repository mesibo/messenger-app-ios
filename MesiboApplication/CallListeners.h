//
//  CallListeners.h
//  MesiboApplication
//
//  All call listeners of the app, same as CallListeners on Android:
//
//  MesiboCallIncomingListener: incoming calls (call properties), missed call notifications.
//  MesiboCallMonitorListener: calls starting and ending - updates the chat list and chats, which
//  show the call in progress button during a call (UIListener).
//

#import <Foundation/Foundation.h>
#import "Includes.h"

NS_ASSUME_NONNULL_BEGIN

@interface CallListeners : NSObject <MesiboCallIncomingListener, MesiboCallMonitorListener>
+ (CallListeners *)getInstance;
/** starts the call library (once) with these listeners */
+ (void)start;
@end

NS_ASSUME_NONNULL_END
