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

#import "UIManager.h"
#import "UIColors.h"

@interface UIManager() {
    UIActivityIndicatorView *mIndicator;
    int mSystemVersion;
}

@end

@implementation UIManager

+(UIManager *)getInstance {
    static UIManager *myInstance = nil;
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
    CGFloat width = [UIScreen mainScreen].bounds.size.width ;
    
    CGFloat height= [UIScreen mainScreen].bounds.size.height ;
    
    mIndicator = [[UIActivityIndicatorView alloc]initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
    mIndicator.frame = CGRectMake(0.0, 0.0, width, height);
    mIndicator.layer.cornerRadius = 0;
    mIndicator.layer.masksToBounds = YES;
    mIndicator.opaque = NO;
    mIndicator.hidesWhenStopped = YES;
    mIndicator.tag = 10000;
    mIndicator.backgroundColor = [UIColor getColor:INDI_BACKGROUND];
    NSString *systemVersion = [[UIDevice currentDevice] systemVersion];
    mSystemVersion = [[systemVersion substringToIndex:1] intValue];
}


-(void) addProgress:(UIView *)view {
    [view addSubview:mIndicator];
    [mIndicator bringSubviewToFront:view];
    //mIndicator.center = view.center;
}

-(void) showProgress {
    [mIndicator startAnimating];
}

-(void) hideProgress {
    if(mIndicator.isAnimating)
        [mIndicator stopAnimating];
}

-(BOOL) runningVersionAndAbove:(int)version {
    if(mSystemVersion >= version)
        return YES;
    return NO;
}
@end
