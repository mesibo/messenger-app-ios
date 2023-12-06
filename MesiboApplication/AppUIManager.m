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

#import "AppUIManager.h"
#import "CommonAppUtils.h"
#import "SettingsViewController.h"
#import "EditProfileController.h"
#import <MesiboUI/MesiboUI.h>
#import "Includes.h"

@implementation AppUIManager

+ (void) launchSettings:(id)parent {
    UIStoryboard *storyboard = [CommonAppUtils getMeSettingsStoryBoard];
    SettingsViewController  *mtvc = [storyboard instantiateViewControllerWithIdentifier:@"SettingsViewController"];
    UINavigationController *unc = [[UINavigationController alloc] initWithRootViewController:mtvc];
    unc.modalPresentationStyle = UIModalPresentationFullScreen;
    mtvc.mParent = parent;

    [parent presentViewController:unc animated:YES completion:nil];
}


//UINavigationController *_mNavigationController = nil;
UIViewController *_mAppParent = nil;
+(void) setDefaultParent:(UIViewController *)controller {
    _mAppParent = controller;
}


+(void) showImageFile:(ImagePicker*) im withParentController:(id)Parent withImage:(UIImage*) image withTitle:(NSString *) title{
    [im showPhotoInViewer:Parent withImage:image withTitle:title];
}

+ (void) showImagesInViewer:(ImagePicker*) im withParentController:(id)Parent withImages:(NSArray*) imagepathArray withStartIndex:(int) index withTitle:(NSString *) title{
    [im showMediaFilesInViewer:Parent withInitialIndex:index withData:imagepathArray withTitle:title];

}

+ (void)  showEntireAlbum:(ImagePicker*) im withParentController:(id)Parent withAlbum:(NSMutableArray*) album withTitle:(NSString *) title{
    [im showMediaFiles:Parent withMediaData:album withTitle:title];

}

+ (void) pickImageData:(ImagePicker*)im withParent:(id)Parent withMediaType:(int)type withBlockHandler:(void(^)(ImagePickerFile *file))handler {
    if(nil == im){
        im = [ImagePicker sharedInstance];
    }
    
    im.mParent = Parent;
    [im pickMedia:type :handler];
    
}

+ (void) launchImageEditor:(ImagePicker*)im withParent:(id)Parent withImage:(UIImage *)image hideEditControls:(BOOL)hideControls withBlock: (MesiboImageEditorBlock)handler {
    if(nil == im){
        im = [ImagePicker sharedInstance];
    }
    
    im.mParent = Parent;
    [im getImageEditor:image title:@"Edit Picture" hideEditControl:hideControls showCaption:NO showCropOverlay:YES squareCrop:YES maxDimension:600 withBlock:handler];
    
}

+(UIImage *) getDefaultImage:(BOOL) group {
    return [MesiboUI getDefaultImage:group];
}

@end
