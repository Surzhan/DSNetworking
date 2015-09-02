//
//  NSString+DLSStringExtensions.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 01.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (DLSStringExtensions)

+ (instancetype)alphanumericAlphabet;
+ (instancetype)numericAlphabet;
+ (instancetype)lowercaseLetterAlphabet;
+ (instancetype)uppercaseLetterAlphabet;
+ (instancetype)letterAlphabet;

+ (instancetype)alphabetWithRange:(NSRange)range;

+ (instancetype)randomString;
+ (instancetype)randomStringWithLength:(NSUInteger)length;
+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet;

- (NSArray *)symbols;

@end
