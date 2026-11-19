//
//  AboutViewController.m
//  MesiboApplication
//

#import "AboutViewController.h"

@implementation AboutViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"About";
    self.view.backgroundColor = UIColor.systemGroupedBackgroundColor;

    UIImageView *icon = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"appicon"]];
    icon.contentMode = UIViewContentModeScaleAspectFit;
    icon.layer.cornerRadius = 22;
    icon.clipsToBounds = YES;
    [icon.widthAnchor constraintEqualToConstant:96].active = YES;
    [icon.heightAnchor constraintEqualToConstant:96].active = YES;

    NSDictionary *info = NSBundle.mainBundle.infoDictionary;
    UILabel *name = [UILabel new];
    name.text = info[@"CFBundleDisplayName"] ?: info[@"CFBundleName"] ?: @"Mesibo";
    name.font = [UIFont systemFontOfSize:24 weight:UIFontWeightBold];

    UILabel *version = [UILabel new];
    version.text = [NSString stringWithFormat:@"Version %@ (%@)", info[@"CFBundleShortVersionString"] ?: @"", info[@"CFBundleVersion"] ?: @""];
    version.font = [UIFont systemFontOfSize:15];
    version.textColor = UIColor.secondaryLabelColor;

    UILabel *about = [UILabel new];
    about.text = @"Messaging, voice and video calls, and conferencing, built with mesibo. The source code of this app is on GitHub.";
    about.font = [UIFont systemFontOfSize:15];
    about.textColor = UIColor.secondaryLabelColor;
    about.numberOfLines = 0;
    about.textAlignment = NSTextAlignmentCenter;

    UIButton *website = [self link:@"mesibo.com" url:@"https://mesibo.com"];
    UIButton *github = [self link:@"Source code on GitHub" url:@"https://github.com/mesibo"];

    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[icon, name, version, about, website, github]];
    stack.axis = UILayoutConstraintAxisVertical;
    stack.alignment = UIStackViewAlignmentCenter;
    stack.spacing = 8;
    [stack setCustomSpacing:16 afterView:icon];
    [stack setCustomSpacing:24 afterView:version];
    [stack setCustomSpacing:24 afterView:about];
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:stack];
    UILayoutGuide *safe = self.view.safeAreaLayoutGuide;
    [NSLayoutConstraint activateConstraints:@[
        [stack.topAnchor constraintEqualToAnchor:safe.topAnchor constant:40],
        [stack.leadingAnchor constraintEqualToAnchor:safe.leadingAnchor constant:32],
        [stack.trailingAnchor constraintEqualToAnchor:safe.trailingAnchor constant:-32],
    ]];
}

- (UIButton *)link:(NSString *)title url:(NSString *)url {
    UIButton *b = [UIButton buttonWithType:UIButtonTypeSystem];
    [b setTitle:title forState:UIControlStateNormal];
    b.titleLabel.font = [UIFont systemFontOfSize:16 weight:UIFontWeightMedium];
    b.accessibilityHint = url;
    [b addTarget:self action:@selector(openLink:) forControlEvents:UIControlEventTouchUpInside];
    return b;
}

- (void)openLink:(UIButton *)b {
    NSURL *url = [NSURL URLWithString:b.accessibilityHint];
    if (url)
        [UIApplication.sharedApplication openURL:url options:@{} completionHandler:nil];
}

@end
