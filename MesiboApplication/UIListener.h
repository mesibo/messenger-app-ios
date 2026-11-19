//
//  UIListener.h
//  MesiboApplication
//
//  Customizes the messaging screens: the chat list menu (conference, backup & restore,
//  encryption, invite, settings) and the call buttons of a chat. Same as UIListener on Android.
//

#import <Foundation/Foundation.h>
#import "Includes.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIListener : NSObject <MesiboUIListener>
@end

NS_ASSUME_NONNULL_END
