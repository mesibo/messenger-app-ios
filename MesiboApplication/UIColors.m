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

#import "UIColors.h"


@implementation UIColor (Extensions)


+ (UIColor *) titleColor0 {
    return hex2Rgb(TITLE_COLOR_0);
}
+ (UIColor *) titleColor1 {
    return hex2Rgb(TITLE_COLOR_1);
}
+ (UIColor *) titleColor2 {
    return hex2Rgb(TITLE_COLOR_2);
}
+ (UIColor *) titleColor3 {
    return hex2Rgb(TITLE_COLOR_3);
}
+ (UIColor *) titleColor4 {
    return hex2Rgb(TITLE_COLOR_4);
}
+ (UIColor *) titleColor5 {
    return hex2Rgb(TITLE_COLOR_5);
}
+ (UIColor *) titleColor6 {
    return hex2Rgb(TITLE_COLOR_6);
}
+ (UIColor *) titleColor7 {
    return hex2Rgb(TITLE_COLOR_7);
}

+(UIColor *) toastColor {
    return hex2Rgb(TOAST_COLOR);
}

+(UIColor *) pullRefreshColor {
    return hex2Rgb(PULLREFRESH_COLOR);
}


//+ (UIColor *)getColor:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness {
//    return [UIColor colorWithHue:(hue/360) saturation:saturation brightness:brightness alpha:1.0];
//}

+(UIColor *) getColorView:(UInt32) color {
    if(USE_ALL_DEFAULT_COLOR)
        return [ UIColor whiteColor];
    if(color == USE_DEFAULT_COLOR)
        return [ UIColor whiteColor];
    
    
    return hex2Rgb(color);
}

+(UIColor *) getColorNavTtl:(UInt32) color {
    if(USE_ALL_DEFAULT_COLOR)
        return [ UIColor blackColor];
    if(color == USE_DEFAULT_COLOR)
        return [ UIColor blackColor];
    
    
    return hex2Rgb(color);
}
+(UIColor *) getColor:(UInt32) color {
    
    if(USE_ALL_DEFAULT_COLOR)
        return nil;
    if(color == USE_DEFAULT_COLOR)
        return nil;
    
    
    return [UIColor colorWithRed:((float)((color>>16)&0xFF))/255.0 green:((float)((color>>8)&0xFF))/255.0 blue:((float)((color)&0xFF))/255.0 alpha:((float)((color>>24)&0xFF))/255.0];
}


+ (UIColor *) toolBarColor {
    return [UIColor getColor:TOOLBAR_COLOR];
}



@end
