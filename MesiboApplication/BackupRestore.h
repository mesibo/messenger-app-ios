//
//  BackupRestore.h
//  MesiboApplication
//
//  Message backups: kept in the app (Application Support/Backups) with an option to save a copy
//  to Files; restore from those or from a file picked in Files. Same as BackupRestore on Android.
//

#import <Foundation/Foundation.h>
#import "Includes.h"

NS_ASSUME_NONNULL_BEGIN

@interface BackupRestore : NSObject
/** Back up now / Restore */
+ (void)show:(UIViewController *)parent;
+ (void)backup:(UIViewController *)parent;
@end

NS_ASSUME_NONNULL_END
