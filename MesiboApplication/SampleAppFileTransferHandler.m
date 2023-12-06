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

#import "SampleAppFileTransferHandler.h"
#import "SampleAPI.h"
#import <Photos/Photos.h>

@implementation SampleAppFileTransferHandler

- (void) initialize {
    [MesiboInstance addListener:self];
}

-(BOOL) Mesibo_onStartUpload:(MesiboFileTransfer *)file {
    NSMutableDictionary *post = [[NSMutableDictionary alloc] init];
    
    [post setObject:@"upload" forKey:@"op"];
    [post setValue:[MesiboInstance getUploadAuthToken] forKey:@"auth"];
    [post setValue:[@(file.mid) stringValue] forKey:@"mid"];
    [post setValue:[@([MesiboInstance getUid]) stringValue] forKey:@"uid"];
    [post setValue:[@(file.source) stringValue] forKey:@"source"];
    
    Mesibo_onHTTPProgress handler = ^BOOL(MesiboHttp *http, int state, int progress) {
        
        if(100 == progress && MESIBO_HTTPSTATE_DOWNLOAD == state) {
            NSError *jsonerror = nil;
            
            NSData *data = [[http getDataString] dataUsingEncoding:NSUTF8StringEncoding];
            id jsonObject = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:&jsonerror];
            NSDictionary *returnedDict = (NSMutableDictionary *)jsonObject;
            NSString *url =  [returnedDict valueForKey:@"url"];
            BOOL result =  [[returnedDict valueForKey:@"result"] boolValue];
            
            if(!url || !url.length || !result) {
                [file setResult:NO];
                return YES;
            }
            
            [file setResult:YES url:url];
            return YES;
        }
        
        if(progress < 0) {
            [file setResult:NO];
            return YES;
        }
        
        [file setProgress:progress];
        return YES;
        
    };
    
    MesiboHttp *http = [MesiboHttp new];
    http.url = [MesiboInstance getUploadUrl];
    http.uploadPhAsset = [file getPHAsset];
    http.uploadLocalIdentifier = [file getLocalIdentifier];
    http.uploadFile = [file getPath];
    http.postBundle = post;
    http.uploadFileField = @"photo";
    http.listener =  handler;
    
    [file setFileTransferContext:http];
 
    return [http execute];
}

-(BOOL) Mesibo_onStartDownload:(MesiboFileTransfer *)file {
    
    if(MESIBO_ORIGIN_REALTIME != file.origin && !file.priority)
        return NO;
    
    NSString *url = [file getUrl];
    
    if(!url || !url.length)
        return NO;
    
    if (![url hasPrefix:@"http://"] && ![url hasPrefix:@"https://"]) {
        return NO;
    }

    
    Mesibo_onHTTPProgress handler = ^BOOL(MesiboHttp *http, int state, int progress) {
        if(100 == progress && MESIBO_HTTPSTATE_DOWNLOAD == state) {
            [file setResult:YES url:nil];
            return YES;
        }
        
        if(progress < 0) {
            [file setResult:NO];
            return YES;
        }
        
        [file setProgress:progress];
        return YES;
    };
    
    MesiboHttp *http = [MesiboHttp new];
    http.url = url;
    http.downloadFile = [file getPath];
    http.resume = YES;
    http.listener =  handler;
    http.maxRetries = 10;
    
    [file setFileTransferContext:http];
    
    return [http execute];
    
}

-(BOOL) Mesibo_onStartFileTransfer:(MesiboFileTransfer *)ft {
    
    if(!ft.upload) {
        return [self Mesibo_onStartDownload:ft];
    }
    
    return [self Mesibo_onStartUpload:ft];
    
}

-(BOOL) Mesibo_onStopFileTransfer:(MesiboFileTransfer *)ft {
    MesiboHttp *http = [ft getFileTransferContext];
    if(http) {
        [http cancel];
    }
    return YES;
}

@end
