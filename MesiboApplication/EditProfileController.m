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

#import "EditProfileController.h"

#import "Includes.h"
#import "AppAlert.h"
#import <MesiboUI/MesiboUI.h>
#import "CommonAppUtils.h"
#import "UIManager.h"
#import <mesibo/mesibo.h>
#import "AppUIManager.h"
#import "UIColors.h"


#define TEXTVIEW_PLACEHOLDER @"Type status"
@interface EditProfileController ()<UITextFieldDelegate, UITextViewDelegate, MesiboDelegate>
@property (weak, nonatomic) IBOutlet UILabel *mPhoneNumber;
@property (weak, nonatomic) IBOutlet UIImageView *mProfilePicture;
@property (weak, nonatomic) IBOutlet UIButton *mPictureEditBtn;
@property (weak, nonatomic) IBOutlet UILabel *mNameCharCounter;
@property (weak, nonatomic) IBOutlet UITextField *mNameTextField;
@property (weak, nonatomic) IBOutlet UITextView *mStatusTextView;
@property (weak, nonatomic) IBOutlet UIButton *mStatusCharCounter;
@property (weak, nonatomic) IBOutlet UIScrollView *mProfileScroller;
@property (weak, nonatomic) IBOutlet UIButton *mSaveBtn;

@end

#define MAX_NAME_CHAR_LIMIT     30
#define MIN_NAME_CHAR_LIMIT     3
#define MAX_STATUS_CHAR_LIMIT   150
#define MIN_STATUS_CHAR_LIMIT   3


@implementation EditProfileController {
    MesiboSelfProfile *mProfile;
    UIImage *mImage;
}

- (void) setProfile:(MesiboSelfProfile *) profile {
    mProfile = profile;
}


- (void)viewDidLoad {
    
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.view layoutIfNeeded];
    
    mImage = nil;
    
    if(!mProfile) mProfile = (MesiboSelfProfile *) [MesiboInstance getSelfProfile];
    
    _mPictureEditBtn.layer.cornerRadius = _mPictureEditBtn.layer.frame.size.width/2;
    _mPictureEditBtn.layer.masksToBounds = YES;
    
    _mNameCharCounter.layer.cornerRadius = _mNameCharCounter.layer.frame.size.width/2;
    _mNameCharCounter.layer.masksToBounds = YES;
    
    _mNameTextField.delegate = self;
    _mStatusTextView.delegate = self;
    _mNameCharCounter.text = [NSString stringWithFormat:@"%d", MAX_NAME_CHAR_LIMIT];
    [_mStatusCharCounter setTitle:[NSString stringWithFormat:@"%d", MAX_STATUS_CHAR_LIMIT] forState:UIControlStateNormal];
    _mStatusTextView.text = TEXTVIEW_PLACEHOLDER;
    _mStatusTextView.textColor = [UIColor grayColor];
    
    _mStatusTextView.layer.borderColor = [UIColor grayColor].CGColor;
    _mStatusTextView.layer.borderWidth = 0.5;
    
    UIButton *button =  [UIButton buttonWithType:UIButtonTypeCustom];
    [button setImage:[CommonAppUtils imageNamed:@"ic_arrow_back_white.png"] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(backButtonPressed)forControlEvents:UIControlEventTouchUpInside];
    [button setFrame:CGRectMake(0, 0, 24, 24)];
    UIBarButtonItem *barButton = [[UIBarButtonItem alloc] initWithCustomView:button];
    self.navigationItem.leftBarButtonItem = barButton;

    self.title = @"Edit Profile";
    
    UITapGestureRecognizer *singleTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(onPictureClicked)];
    singleTap.numberOfTapsRequired = 1;
    [_mProfilePicture setUserInteractionEnabled:YES];
    [_mProfilePicture addGestureRecognizer:singleTap];
    
    [self setProfilePicture];

    _mNameTextField.text = [mProfile getName];
    _mStatusTextView.text = [mProfile getString:@"status" defval:@""];
    _mPhoneNumber.text = [mProfile getAddress];
    
    _mSaveBtn.backgroundColor = [UIColor getColor:PRIMARY_COLOR];
    
    
}


- (void) backButtonPressed {
    [self.navigationController popViewControllerAnimated:YES ];
    
}

-(void)onPictureClicked{
     
    NSString *picturePath = [[mProfile getImage] getImageOrThumbnailPath];
    
    if(picturePath) {
        UIImage *image = [UIImage imageWithContentsOfFile:picturePath];
        ImagePicker *im = [ImagePicker sharedInstance];
        im.mParent = self;
        [AppUIManager showImageFile:im withParentController:self withImage:image withTitle:[mProfile getName]];
    }
}

- (IBAction)saveSelfProfile:(id)sender {
    
    NSString *name = _mNameTextField.text;
    NSString *status = _mStatusTextView.text;
    
   
    if([name length] < MIN_NAME_CHAR_LIMIT) {
        [AppAlert showDialogue:@"Name should not be less than 3 charecters" withTitle:@"Change Name"];
        return;
    }
    
    [mProfile setName:name];
    if(mImage) {
        
    }
    [mProfile setString:@"status" value:status];
    [mProfile setSearchable:YES];
    [mProfile save];
    
    if(_mLaunchMesibo) {
        _mLaunchMesibo();
    } else {
        [self.navigationController popViewControllerAnimated:YES];
    }
    
}

-(void) setProfilePicture {
   
    NSString *path = [[mProfile getImage] getImageOrThumbnailPath];
    if(path)
        _mProfilePicture.image = [UIImage imageWithContentsOfFile:path];
    else
        _mProfilePicture.image = [AppUIManager getDefaultImage:NO];
    
    
    [_mProfilePicture layoutIfNeeded];
    //[_mProfilePicture setContentMode:UIViewContentModeScaleAspectFit];
    
    _mProfilePicture.layer.cornerRadius = _mProfilePicture.layer.frame.size.width/2;
    _mProfilePicture.layer.masksToBounds = YES;
    [_mProfilePicture layoutIfNeeded];
}

- (IBAction)changeProfilePicture:(id)sender {
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Profile picture" message:@"Change your profile picture" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *cameraAction = [UIAlertAction actionWithTitle:@"Camera" style:UIAlertActionStyleDefault handler:^(UIAlertAction * action) {
        [self pickMediaWithFiletype:PICK_CAMERA_IMAGE];
    }];
    
    UIAlertAction *galleryAction = [UIAlertAction actionWithTitle:@"Photo Albums" style:UIAlertActionStyleDefault handler:^(UIAlertAction * action) {
        [self pickMediaWithFiletype:PICK_IMAGE_GALLERY];
        
    }];
    
    UIAlertAction *removeAction = [UIAlertAction actionWithTitle:@"Remove" style:UIAlertActionStyleDefault handler:^(UIAlertAction * action) {
        [mProfile setImage:nil];
        [mProfile save];
        [self setProfilePicture];
        
    }];
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * action) {
        NSLog(@"You pressed button cancel");
        [alert removeFromParentViewController];
        
    }];
    
    [alert addAction:cameraAction];
    [alert addAction:galleryAction];
    [alert addAction:removeAction];
    [alert addAction:cancelAction];
    [self presentViewController:alert animated:YES completion:nil];
    
    
    
}
- (void) pickMediaWithFiletype :(int)filetype{
    ImagePicker *im = [ImagePicker sharedInstance];
    im.mParent = self;
    
    [AppUIManager pickImageData:im withParent:self withMediaType:filetype withBlockHandler:^(ImagePickerFile *picker) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSLog(@"Returned data %@", [picker description]);
            [AppUIManager launchImageEditor:im withParent:self withImage:picker.image hideEditControls:NO withBlock:^BOOL(UIImage *image, NSString *caption) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [mProfile setImage:image];
                    [mProfile save];
                    [self setProfilePicture];
                });
                return YES;
                
            }];
        });
        
    }];
    
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    
    NSString *newText = [textField.text stringByReplacingCharactersInRange:range withString:string];
    if(newText.length>MAX_NAME_CHAR_LIMIT) {
        return NO;
    }
    [_mNameCharCounter setText:[NSString stringWithFormat:@"%u", (uint32_t)(MAX_NAME_CHAR_LIMIT-newText.length)]];
    return YES;
}

- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text{
    
    NSString *newText = [textView.text stringByReplacingCharactersInRange:range withString:text];
    if(newText.length>MAX_STATUS_CHAR_LIMIT) {
        return NO;
    }
    [_mStatusCharCounter setTitle:[NSString stringWithFormat:@"%u", (uint32_t) (MAX_STATUS_CHAR_LIMIT-newText.length)] forState:UIControlStateNormal];
    return YES;
}


- (void)viewWillAppear:(BOOL)animated {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillHide:) name:UIKeyboardWillHideNotification object:nil];
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc]
                                   initWithTarget:self
                                   action:@selector(dismissKeyboard)];
    [self.view addGestureRecognizer:tap];
}

- (void)viewWillDisappear:(BOOL)animated {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillHideNotification object:nil];
    
}

- (void)keyboardWillShow:(NSNotification *)notification {
    CGRect keyboardFrame = [[[notification userInfo] objectForKey:UIKeyboardFrameEndUserInfoKey] CGRectValue];
    UIWindow *window = [[[UIApplication sharedApplication] windows]objectAtIndex:0];
    UIView *mainSubviewOfWindow = window.rootViewController.view;
    CGRect keyboardFrameConverted = [mainSubviewOfWindow convertRect:keyboardFrame fromView:window];
    
    
    CGFloat mKBHeight =keyboardFrameConverted.size.height;
    UIEdgeInsets contentInsets = UIEdgeInsetsMake(0.0, 0.0, mKBHeight, 0.0);
    _mProfileScroller.contentInset = contentInsets;
    _mProfileScroller.scrollIndicatorInsets = contentInsets;

    if(_mStatusTextView.isFirstResponder) {
        CGRect aRect = self.view.frame;
        aRect.size.height -= mKBHeight;
        if (!CGRectContainsPoint(aRect, CGPointMake(0, CGRectGetMaxY(_mStatusTextView.frame)))) {
            [_mProfileScroller scrollRectToVisible:_mStatusTextView.frame animated:NO];
        }
    }
    if(_mNameTextField.isFirstResponder) {
                CGRect aRect = self.view.frame;
        aRect.size.height -= mKBHeight;
        if (!CGRectContainsPoint(aRect, CGPointMake(0, CGRectGetMaxY(_mNameTextField.frame)))) {
            [_mProfileScroller scrollRectToVisible:_mNameTextField.frame animated:NO];
        }
    }
}

- (void)textViewDidBeginEditing:(UITextView *)textView
{
    if ([textView.text isEqualToString:TEXTVIEW_PLACEHOLDER]) {
        textView.text = @"";
        textView.textColor = [UIColor darkGrayColor]; //optional
    }
    [textView becomeFirstResponder];
}

- (void)textViewDidEndEditing:(UITextView *)textView
{
    if ([textView.text isEqualToString:@""]) {
        textView.text = TEXTVIEW_PLACEHOLDER;
        textView.textColor = [UIColor grayColor]; //optional
    }
    [textView resignFirstResponder];
}

-(void)keyboardWillHide:(NSNotification *)notificatio {
    UIEdgeInsets contentInsets = UIEdgeInsetsZero;
    _mProfileScroller.contentInset = contentInsets;
    _mProfileScroller.scrollIndicatorInsets = contentInsets;
}

- (BOOL)dismissKeyboard {
    
    if([_mStatusTextView isFirstResponder])
        [_mStatusTextView resignFirstResponder];
    if([_mNameTextField isFirstResponder])
        [_mNameTextField resignFirstResponder];
    
    return YES;
}


-(void) setLaunchMesiboCallback:(LaunchMesiboBlock)handler {
    _mLaunchMesibo = handler;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) Mesibo_onProfileUpdated:(MesiboProfile *)profile  {
    
    
}


@end
