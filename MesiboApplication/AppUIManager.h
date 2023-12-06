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

#import <Foundation/Foundation.h>
#import <mesibo/mesibo.h>
#import <UIKit/UIKit.h>
#import <mesibouihelper/mesibouihelper.h>
#import "Includes.h"

@interface AppUIManager : NSObject

+(void)launchProfile:(id)parent profile:(MesiboProfile *)profile ;
+(void) launchSettings:(id)parent;
+(void) showImageFile:(ImagePicker*) im withParentController:(id)Parent withImage:(UIImage*) image withTitle:(NSString *) title;
+(void)  showImagesInViewer:(ImagePicker*) im withParentController:(id)Parent withImages:(NSArray*) imagepathArray withStartIndex:(int) index withTitle:(NSString *) title;
+(void)  showEntireAlbum:(ImagePicker*) im withParentController:(id)Parent withAlbum:(NSMutableArray*) imagepathArray withTitle:(NSString *) title;
+(void) pickImageData:(ImagePicker*)im withParent:(id)Parent withMediaType:(int)type withBlockHandler:(void(^)(ImagePickerFile *file))handler;
+(void) launchImageEditor:(ImagePicker*)im withParent:(id)Parent withImage:(UIImage *)image hideEditControls:(BOOL)hideControls withBlock: (MesiboImageEditorBlock)handler;
+(UIImage *) getDefaultImage:(BOOL) group;
+(void) setDefaultParent:(UIViewController *)controller;

@end
