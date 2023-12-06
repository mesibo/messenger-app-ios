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


#ifndef logs_h
#define logs_h

#define __FILE_NAME__ [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String]

#ifdef DEBUG

#define Log( s, ... ) NSLog( @"MesiboLog:%s:%d %@", \
__FILE_NAME__, \
__LINE__, \
 [NSString stringWithFormat:(s), ##__VA_ARGS__] )

#else

#define Log( s, ... )

#endif

#endif /* logs_h */
