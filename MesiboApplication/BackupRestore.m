//
//  BackupRestore.m
//  MesiboApplication
//

#import "BackupRestore.h"

#define PREFIX @"mesibo-backup-"
#define SUFFIX @".db"

@implementation BackupRestore

+ (void)show:(UIViewController *)parent {
    MesiboDialogOptions *o = [MesiboDialogOptions new];
    o.title = @"Backup & Restore";
    o.items = @[@"Back up now", @"Restore"];
    o.sheet = YES;
    __weak UIViewController *p = parent;
    o.onSelect = ^(NSInteger which) {
        if (!p) return;
        if (0 == which) [self backup:p];
        else [self chooseRestore:p];
    };
    [MesiboDialogs show:parent options:o];
}

/** Application Support/Backups (not visible in Files; the database is in Documents) */
+ (NSURL *)backupDir {
    NSURL *base = [NSFileManager.defaultManager URLsForDirectory:NSApplicationSupportDirectory inDomains:NSUserDomainMask].firstObject;
    NSURL *dir = [base URLByAppendingPathComponent:@"Backups" isDirectory:YES];
    [NSFileManager.defaultManager createDirectoryAtURL:dir withIntermediateDirectories:YES attributes:nil error:nil];
    return dir;
}

+ (void)backup:(UIViewController *)parent {
    NSDateFormatter *f = [NSDateFormatter new];
    f.locale = [NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"];
    f.dateFormat = @"yyyyMMdd-HHmmss";
    NSString *name = [NSString stringWithFormat:@"%@%@%@", PREFIX, [f stringFromDate:[NSDate date]], SUFFIX];
    NSURL *url = [[self backupDir] URLByAppendingPathComponent:name];
    __weak UIViewController *p = parent;
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        [MesiboInstance backupDatabase:url.path];
        BOOL ok = [NSFileManager.defaultManager fileExistsAtPath:url.path];
        dispatch_async(dispatch_get_main_queue(), ^{
            if (!p) return;
            if (!ok) {
                [MesiboDialogs alert:p title:@"Backup failed" message:nil];
                return;
            }
            // a copy outside the app survives deleting the app
            MesiboDialogOptions *o = [MesiboDialogOptions new];
            o.title = @"Messages backed up";
            o.message = @"Save a copy to Files to keep it if the app is deleted or to move it to another phone.";
            o.positiveLabel = @"Save to Files";
            o.negativeLabel = @"Done";
            o.onPositive = ^{ [self exportFile:url parent:p]; };
            [MesiboDialogs show:p options:o];
        });
    });
}

+ (void)exportFile:(NSURL *)url parent:(UIViewController *)parent {
    if (!parent) return;
    UIDocumentPickerViewController *picker = [[UIDocumentPickerViewController alloc] initForExportingURLs:@[url] asCopy:YES];
    [parent presentViewController:picker animated:YES completion:nil];
}

/** backups in the app, newest first */
+ (NSArray<NSURL *> *)backups {
    NSArray<NSURL *> *files = [NSFileManager.defaultManager contentsOfDirectoryAtURL:[self backupDir]
                                                          includingPropertiesForKeys:@[NSURLContentModificationDateKey, NSURLFileSizeKey]
                                                                             options:NSDirectoryEnumerationSkipsHiddenFiles error:nil];
    NSMutableArray<NSURL *> *list = [NSMutableArray array];
    for (NSURL *u in files)
        if ([u.lastPathComponent hasPrefix:PREFIX] && [u.lastPathComponent hasSuffix:SUFFIX])
            [list addObject:u];
    [list sortUsingComparator:^NSComparisonResult(NSURL *a, NSURL *b) {
        NSDate *da = nil, *db = nil;
        [a getResourceValue:&da forKey:NSURLContentModificationDateKey error:nil];
        [b getResourceValue:&db forKey:NSURLContentModificationDateKey error:nil];
        return [db compare:da];
    }];
    return list;
}

+ (NSString *)describe:(NSURL *)u {
    NSDate *d = nil;
    NSNumber *size = nil;
    [u getResourceValue:&d forKey:NSURLContentModificationDateKey error:nil];
    [u getResourceValue:&size forKey:NSURLFileSizeKey error:nil];
    NSString *when = d ? [NSDateFormatter localizedStringFromDate:d dateStyle:NSDateFormatterMediumStyle timeStyle:NSDateFormatterShortStyle] : u.lastPathComponent;
    return [NSString stringWithFormat:@"%@  ·  %@", when, [NSByteCountFormatter stringFromByteCount:size.longLongValue countStyle:NSByteCountFormatterCountStyleFile]];
}

/** backups in the app, and Choose file... */
+ (void)chooseRestore:(UIViewController *)parent {
    NSArray<NSURL *> *backups = [self backups];
    NSMutableArray<NSString *> *items = [NSMutableArray array];
    for (NSURL *u in backups)
        [items addObject:[self describe:u]];
    [items addObject:@"Choose file..."];

    MesiboDialogOptions *o = [MesiboDialogOptions new];
    o.title = 0 == backups.count ? @"No backups found on this phone" : @"Restore from";
    o.items = items;
    o.sheet = YES;
    __weak UIViewController *p = parent;
    o.onSelect = ^(NSInteger which) {
        if (!p) return;
        if (which < (NSInteger)backups.count)
            [self confirmRestore:backups[(NSUInteger)which].path parent:p];
        else
            [self pickFile:p];
    };
    [MesiboDialogs show:parent options:o];
}

+ (void)pickFile:(UIViewController *)parent {
    __weak UIViewController *p = parent;
    // callbacks run on the main thread
    [MesiboUI pickFile:parent extensions:@[@"db"] picked:^(NSString *path) {
        if (path && p)   // nil: cancelled
            [self confirmRestore:path parent:p];
    } rejected:^(NSString *name) {
        if (p) [MesiboDialogs alert:p title:@"Not a backup" message:[NSString stringWithFormat:@"%@ is not a mesibo backup (.db) file", name]];
    }];
}

+ (void)confirmRestore:(NSString *)path parent:(UIViewController *)parent {
    MesiboDialogOptions *o = [MesiboDialogOptions new];
    o.title = @"Restore messages?";
    o.message = @"Your current messages will be replaced by the backup. mesibo will close after restoring; open it again to see them.";
    o.positiveLabel = @"Restore";
    o.negativeLabel = [MesiboUI getUiDefaults].cancel;
    o.destructive = YES;
    __weak UIViewController *p = parent;
    o.onPositive = ^{ [self restore:path parent:p]; };
    [MesiboDialogs show:parent options:o];
}

+ (void)restore:(NSString *)path parent:(UIViewController *)parent {
    if (!parent) return;
    int rv = [MesiboInstance restoreDatabase:path];
    if (0 != rv) {
        [MesiboDialogs alert:parent title:@"Restore failed" message:[NSString stringWithFormat:@"The file is not a valid mesibo backup (%d)", rv]];
        return;
    }
    // messages and profiles are loaded in memory: the app starts again with the restored database
    MesiboDialogOptions *o = [MesiboDialogOptions new];
    o.title = @"Messages restored";
    o.message = @"mesibo will close now. Open it again to see the restored messages.";
    o.onPositive = ^{ exit(0); };
    [MesiboDialogs show:parent options:o];
}

@end
