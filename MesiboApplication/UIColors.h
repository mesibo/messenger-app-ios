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

#import <UIKit/UIKit.h>

#define USE_ALL_DEFAULT_COLOR 0

#define USE_DEFAULT_COLOR 0x00ffffff

#define hex2Rgb(c) \
[UIColor colorWithRed:((float)((c>>16)&0xFF))/255.0 green:((float)((c>>8)&0xFF))/255.0 blue:((float)((c)&0xFF))/255.0 alpha:((float)((c>>24)&0xFF))/255.0]

#define PRIMARY_COLOR           0xff00868b
#define PRIMARY_DARK_COLOR      0xff1565c0
#define PRIMARY_LIGHT_COLOR     0xff42a5f5
#define PRIMARY_ACCENT_COLOR    0xffFF4081

#define PRIMARY_TEXT_COLOR      0xff212121
#define ERROR_COLOR             0xffff2222

#define WHITE_COLOR             0xffffffff
#define LIGHT_GRAY              0Xffeaeaea
#define BLACK_COLOR             0xff000000
#define GREEN_CALL_COLOR        0XFF00fb11
#define GRAY_COLOR              0xff808080

#define INDI_BACKGROUND                 0x4F000000

#define BUTTON_PRESSED_COLOR        PRIMARY_DARK_COLOR


#define DIALER_COLOR                PRIMARY_COLOR

#define TOAST_COLOR                 PRIMARY_COLOR
#define PULLREFRESH_COLOR           PRIMARY_COLOR

#define NOTIFIED_TICK_COLOR            0XFF23b1ef
#define NORMAL_TICK_COLOR              0XFFAAAAAA
#define ERROR_TICK_COLOR               0XFFCC0000



// set this navigationbar background color dafault is white //
#define TOOLBAR_COLOR               0XFF5856D6
#define TITLE_TXT_COLOR             WHITE_COLOR 
// set this for back ground color of each view controller  default is white//
#define BACKGROUND_COLOR            PRIMARY_LIGHT_COLOR

/* ----------------- Album table Controller ----------------------------*/
#define TABLE_FOOTER_LINE                0XFFDFDFDF
#define AT_MESSAGE_TXT_COLOR             LIGHT_GRAY 

/* ----------------- IMAGE view Controller(ImageViewer.m) --------------*/
#define PICTURE_BORDER_LINE              WHITE_COLOR
#define TOP_VIEW_COLOR                   BLACK_COLOR
#define BOTTOM_VIEW_COLOR                BLACK_COLOR
#define DONE_CANCEL_COLOR                WHITE_COLOR

/* ----------------- Left Menu controller (LeftMenuViewController.m) --*/
#define PC_PICTURE_BORDER_LINE              WHITE_COLOR
#define PC_BG_COLOR                      0XFF5856D6
#define PC_LABEL_COLOR                WHITE_COLOR

/* ----------------- chat view controller (MessageViewController.m) ------*/
#define MESSAGE_BUT_BG                   BLACK_COLOR
#define MESSAGE_BUT_TITLE_COLOR          WHITE_COLOR
#define PROFILE_BORDER_COLOR             LIGHT_GRAY

/* ----------------- Dash board controller (DashBoardController.m) ------*/
#define NEXT_VIEW_COLOR                   0XFF5856D6
#define NEXT_BUTTON_TITLE_COLOR           WHITE_COLOR
#define PROFILE_STATUS_COLOR              LIGHT_GRAY



/* -------- Fill more controller (FillMoreProfileController.m )--------*/
#define NEXT_VIEW_COLOR                   0XFF5856D6
#define NEXT_BUTTON_TITLE_COLOR           WHITE_COLOR

#define PROFILE_STATUS_COLOR              LIGHT_GRAY
#define VIEW_BG_COLOR                     WHITE_COLOR
#define SCROLL_BG                         WHITE_COLOR

#define LBL_BG                            0XFF5856D6
#define LBL_FONT_COLOR                    WHITE_COLOR

/* -------- Prifile Finder (ProfileFinderController.m )----------------*/
#define BECON_VIEW_BG                   0Xffb1d9f4


/* -------- Publish (PublishNewTopicController.m )——————————-*/
#define PUB_PROFILE_BRDR_CLR                   BLACK_COLOR
#define PUB_PLC_HLDR_CLR                   GRAY_COLOR

/* -------- TopicView (TopicViewController.m )——————————-*/
#define CARD_SHADOW_CLR                   BLACK_COLOR

/* -------- Ineractive controllers (FirstInteractiveController.m , secon and third )-----*/
#define INTERACTIVE_NXT_VU                0XFF5856D6
#define INTERACTIVE_NXT_BTN_TXT           WHITE_COLOR
#define INTERACTIVE_BG_VU                 WHITE_COLOR
#define INTERACTIVE_BG_TEXT               BLACK_COLOR
#define INTRCTV_TV_BRDR_CLR               GRAY_COLOR 

#define BTN_CLR                           0XFF5856D6
#define BTN_TXT_CLR                       WHITE_COLOR
#define TXT_BOX_BORDER_CLR                0XFF5856D6

/* -------- MessageViewController.m-----*/

#define CHAT_INPUTBAR_CLR                WHITE_COLOR
#define CHAT_BOX_BACKGROUND_CLR          WHITE_COLOR
#define  BACKGTOUND_DATE_BOX             0XFFCFDCFC





#define TITLE_COLOR_0   0Xfff16364
#define TITLE_COLOR_1   0Xfff58559
#define TITLE_COLOR_2   0Xfff9a43e
#define TITLE_COLOR_3   0Xffe4c62e
#define TITLE_COLOR_4   0Xff67bf74
#define TITLE_COLOR_5   0Xff59a2be
#define TITLE_COLOR_6   0Xff2093cd
#define TITLE_COLOR_7   0Xffad62a7

#define titleColors @[@("0Xfff16364"), @("0Xfff58559"), @("0Xfff9a43e"), @("0Xffe4c62e"),@("0Xff67bf74"), @("0Xff59a2be"), @("0Xff2093cd"), @("0Xffad62a7")]

@interface UIColor (Extension)

//+ (UIColor *) getColor:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness ;
+ (UIColor *) toolBarColor ;
+ (UIColor *) getButtonColor;
+ (UIColor *) toastColor;
+ (UIColor *) pullRefreshColor;
+ (UIColor *) getColor:(UInt32) color;
+ (UIColor *) getColorView:(UInt32) color;
+ (UIColor *) getColorNavTtl:(UInt32) color;
@end
