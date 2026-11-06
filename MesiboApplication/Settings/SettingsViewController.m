//
//  SettingsViewController.m
//  MesiboApplication
//

#import "SettingsViewController.h"
#import "AboutViewController.h"
#import "UIManager.h"
#import "SampleAPI.h"

#define PRIVACY_URL @"https://mesibo.com/terms-of-use/"

typedef NS_ENUM(NSInteger, SettingsSection) { SectionProfile, SectionNotifications, SectionDisplay, SectionInfo, SectionLogout, SectionCount };

@implementation SettingsViewController

- (instancetype)init {
    return [super initWithStyle:UITableViewStyleInsetGrouped];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Settings";
    if (self.navigationController.viewControllers.firstObject == self)
        self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemClose
                                                                                             target:self action:@selector(close)];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self.tableView reloadData];   // the profile may have been edited
}

- (void)close {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return SectionCount;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    switch (section) {
        case SectionNotifications: return 2;
        case SectionInfo: return 2;
        default: return 1;
    }
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    switch (section) {
        case SectionNotifications: return @"Notifications";
        case SectionDisplay: return @"Display";
        default: return nil;
    }
}

/** a cell with a list content configuration: value: text and a value on the right (UITableViewCellStyleValue1) */
- (UITableViewCell *)cell:(UITableViewCellStyle)style text:(NSString *)text icon:(NSString *)icon {
    UITableViewCell *c = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    UIListContentConfiguration *cc = UITableViewCellStyleValue1 == style ? [UIListContentConfiguration valueCellConfiguration]
                                                                         : [UIListContentConfiguration cellConfiguration];
    cc.text = text;
    if (icon) {
        cc.image = [UIImage systemImageNamed:icon];
        cc.imageProperties.tintColor = UIColor.secondaryLabelColor;
    }
    c.contentConfiguration = cc;
    return c;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    switch (indexPath.section) {
        case SectionProfile: {
            MesiboProfile *me = [MesiboInstance getSelfProfile];
            UITableViewCell *c = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
            UIListContentConfiguration *cc = [UIListContentConfiguration subtitleCellConfiguration];
            cc.text = [me getName];
            cc.textProperties.font = [UIFont systemFontOfSize:20 weight:UIFontWeightSemibold];
            cc.secondaryText = [me getString:@"status" defval:@""];
            cc.secondaryTextProperties.color = UIColor.secondaryLabelColor;
            UIImage *img = [[me getImage] getImageOrThumbnail];
            cc.image = [self round:img ?: [UIImage systemImageNamed:@"person.crop.circle.fill"] size:60];
            cc.imageProperties.tintColor = UIColor.systemGrayColor;
            c.contentConfiguration = cc;
            c.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
            return c;
        }
        case SectionNotifications: {
            BOOL groups = 1 == indexPath.row;
            UITableViewCell *c = [self cell:UITableViewCellStyleDefault text:groups ? @"Group message notifications" : @"Message notifications"
                                       icon:groups ? @"person.2" : @"bell"];
            UISwitch *sw = [UISwitch new];
            sw.on = groups ? [SampleAPIInstance getGroupMessageNotification] : [SampleAPIInstance getMessageNotification];
            sw.tag = indexPath.row;
            [sw addTarget:self action:@selector(notificationChanged:) forControlEvents:UIControlEventValueChanged];
            c.accessoryView = sw;
            c.selectionStyle = UITableViewCellSelectionStyleNone;
            return c;
        }
        case SectionDisplay: {
            UITableViewCell *c = [self cell:UITableViewCellStyleValue1 text:@"Theme" icon:@"circle.lefthalf.fill"];
            UIListContentConfiguration *cc = (UIListContentConfiguration *)c.contentConfiguration;
            cc.secondaryText = [UIManager themeName];
            c.contentConfiguration = cc;
            c.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
            return c;
        }
        case SectionInfo: {
            BOOL about = 1 == indexPath.row;
            UITableViewCell *c = [self cell:UITableViewCellStyleDefault text:about ? @"About" : @"Privacy Policy and User Data"
                                       icon:about ? @"info.circle" : @"doc.text"];
            c.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
            return c;
        }
        default: {
            UITableViewCell *c = [self cell:UITableViewCellStyleDefault text:@"Log out" icon:nil];
            UIListContentConfiguration *cc = (UIListContentConfiguration *)c.contentConfiguration;
            cc.textProperties.color = UIColor.systemRedColor;
            cc.textProperties.alignment = UIListContentTextAlignmentCenter;
            c.contentConfiguration = cc;
            return c;
        }
    }
}

- (UIImage *)round:(UIImage *)image size:(CGFloat)size {
    UIGraphicsImageRenderer *r = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(size, size)];
    return [r imageWithActions:^(UIGraphicsImageRendererContext *ctx) {
        [[UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, size, size)] addClip];
        [image drawInRect:CGRectMake(0, 0, size, size)];
    }];
}

- (void)notificationChanged:(UISwitch *)sw {
    if (1 == sw.tag)
        [SampleAPIInstance setGroupMessageNotification:sw.on];
    else
        [SampleAPIInstance setMessageNotification:sw.on];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    switch (indexPath.section) {
        case SectionProfile:
            [[UIManager getInstance] launchEditProfile:self newUser:NO];
            break;
        case SectionDisplay: {
            __weak typeof(self) weakSelf = self;
            [UIManager chooseTheme:self changed:^{ [weakSelf.tableView reloadData]; }];
            break;
        }
        case SectionInfo:
            if (1 == indexPath.row)
                [self.navigationController pushViewController:[AboutViewController new] animated:YES];
            else
                [UIApplication.sharedApplication openURL:[NSURL URLWithString:PRIVACY_URL] options:@{} completionHandler:nil];
            break;
        case SectionLogout:
            [self confirmLogout];
            break;
    }
}

- (void)confirmLogout {
    MesiboDialogOptions *o = [MesiboDialogOptions new];
    o.title = @"Log out?";
    o.positiveLabel = @"Log out";
    o.negativeLabel = [MesiboUI getUiDefaults].cancel;
    o.destructive = YES;
    __weak typeof(self) weakSelf = self;
    o.onPositive = ^{ [SampleAPIInstance logout:NO parent:weakSelf]; };
    [MesiboDialogs show:self options:o];
}

@end
