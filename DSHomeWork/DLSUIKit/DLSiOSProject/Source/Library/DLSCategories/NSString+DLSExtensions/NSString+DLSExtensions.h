//
//  NSString+DLSExtensions.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DLSAlphabet.h"

@interface NSString (DLSExtensions)

+ (id)randomString;

+ (id)randomStringWithLength:(NSUInteger)length;

+ (id)randomStringWithLength:(NSUInteger)length alphabet:(DLSAlphabet *)alphabet;

- (NSArray *)symbols;

@end
