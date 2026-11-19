//
//  SampleAppListeners.h
//  MesiboApplication
//
//  mesibo listeners of the app: messages (notifications), connection (sign out), groups,
//  profiles. Calls are in CallListeners. Same as MesiboListeners on Android.
//

#import <Foundation/Foundation.h>
#import "Includes.h"

NS_ASSUME_NONNULL_BEGIN

@interface SampleAppListeners : NSObject <MesiboDelegate, MesiboProfileCustomizationListener>
+ (SampleAppListeners *)getInstance;
@end

NS_ASSUME_NONNULL_END
