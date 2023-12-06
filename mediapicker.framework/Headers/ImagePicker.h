/** Copyright (c) 2019 Mesibo
 * https://mesibo.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the terms and condition mentioned
 * on https://mesibo.com as well as following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions, the following disclaimer and links to documentation and
 * source code repository.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of Mesibo nor the names of its contributors may be used to
 * endorse or promote products derived from this software without specific prior
 * written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Documentation
 * https://mesibo.com/documentation/
 *
 * Source Code Repository
 * https://github.com/mesibo/ui-modules-ios
 *
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


#define PICK_CAMERA_IMAGE 0
#define PICK_IMAGE_GALLERY 1
#define PICK_VIDEO_GALLERY 2
#define PICK_VIDEO_RECORDING 3
#define PICK_AUDIO_FILES 4
#define PICK_LOCATION 5
#define PICK_DOCUMENTS 6
#define PICK_FACEBOOK_IMAGES 7


typedef BOOL (^MesiboImageEditorBlock)(UIImage *image, NSString *caption);
typedef void (^MesiboMediaFilesBlock)(UIImage *image);
typedef void (^MesiboImageViewerBlock)(UIImageView *image, UILabel *caption);

@interface ImagePickerFile : NSObject

@property (atomic) NSString *filePath;
@property (atomic) NSString *mp4Path;
@property (strong,nonatomic) UIImage *image;
@property (atomic) NSString *message;
@property (atomic) NSString *title;
@property (atomic) int fileType;
@property (atomic) int mp4state;
@property (nonatomic) double lat;
@property (nonatomic) double lon;
@property (nonatomic) int zoom;
@property (nonatomic) int size;
@property (nonatomic) NSString *url;
@property (nonatomic) id phasset;
@property (atomic) NSString *localIdentifier;
@property (nonatomic) void (^mp4TranscodingHandler)(ImagePickerFile * file);

-(void) setMp4TranscodingHandler:(void (^)(ImagePickerFile *))handler;
-(void) setMp4Ready:(BOOL)ready;
@end

@interface AlbumsData : NSObject

@property (strong , nonatomic) NSString* mAlbumID;
@property (strong , nonatomic) NSString* mAlbumProfilePicPath;
@property (strong , nonatomic) NSString* mAlbumName;
@property (assign , nonatomic) NSInteger mAlbumPhotoCount;
@property (strong , nonatomic) NSMutableArray* mPhotoGList; // Array of photoData

@end

@interface PhotoData : NSObject

@property NSString *mDateCreated;
@property NSString *mId;
@property NSString *mIconPath;
@property NSString *mSourcePath;

@end

@interface PickerUiOptions : NSObject
@property (assign, nonatomic) uint32_t mToolbarColor;

- (UIColor *) toolBarColor;
@end


@interface ImagePicker : NSObject <UIDocumentPickerDelegate>
{
    void (^_completionHandler)(ImagePickerFile * file);
    
}


@property (strong ,nonatomic) UIViewController * mParent;
//@property (strong, nonatomic) NSMutableArray  *mAlbumListed;



-(void)pickMedia:(int) PICK_MEDIA :(void(^)(ImagePickerFile *file))handler ;


-(void)getImageEditor:(UIImage *) image  title:(NSString*)title hideEditControl:(BOOL)hideControls showCaption:(BOOL)showCaption showCropOverlay:(BOOL)showCropOverlay squareCrop:(BOOL)squareCrop maxDimension:(int) maxDimension withBlock: (MesiboImageEditorBlock)handler;

+ (ImagePicker *)sharedInstance;

-(void) showPhotoInViewer:(UIViewController *)presentController withImage : (UIImage*) photoImage withTitle:(NSString*) title;
-(void) showPhotoInViewer:(UIViewController *)presentController withImage : (UIImage*) photoImage withTitle:(NSString*)title handler:(MesiboImageViewerBlock) handler;

-(void) showMediaFiles : (UIViewController *)presentController withMediaData :(NSArray *) data withTitle:(NSString*) title;

-(void) callBackFromFacebook:(UIImage*) imageFacebook;
-(void) showMediaFilesInViewer:(UIViewController *)presentController withInitialIndex:(int)index withData : (NSArray*) filesArray withTitle:(NSString*) title;

+(void) showFile:(UIViewController *)parent path:(NSString *)path title:(NSString *)title type:(int)type;
+(void) mapSnapShot:(double)lat lon:(double)lon handler:(void(^)(ImagePickerFile *file)) handler;
+ (UIImage *)getDefaultImageForExt:(NSString *)ext;

+(void) setUiOptions:(PickerUiOptions *)options;
+(PickerUiOptions *) getUiOptions;
@end
