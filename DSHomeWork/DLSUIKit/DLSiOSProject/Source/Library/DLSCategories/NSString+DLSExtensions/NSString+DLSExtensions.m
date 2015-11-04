//
//  NSString+DLSExtensions.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "NSString+DLSExtensions.h"

static const NSUInteger kDLSrandomStringLength = 30;

@implementation NSString (DLSExtensions)

#pragma mark -
#pragma mark Class Methods

+ (id)randomString {
    return [self randomStringWithLength:arc4random_uniform(kDLSrandomStringLength)
                               alphabet:[DLSAlphabet alphabetWithNumbers]];
}

+ (id)randomStringWithLength:(NSUInteger)length {
    return [self randomStringWithLength:length alphabet:[DLSAlphabet alphabetWithNumbers]];
}

+ (id)randomStringWithLength:(NSUInteger)length alphabet:(DLSAlphabet *)alphabet {
    NSMutableString *result = [NSMutableString stringWithCapacity:length];
    u_int32_t alphabethLength = (u_int32_t)alphabet.count;
    for (NSUInteger index = 0; index < length; ++index) {
        [result appendFormat:@"%@", [alphabet stringAtIndex:arc4random_uniform(alphabethLength)]];
    }
    
    return [self stringWithString:result];
}

#pragma mark -
#pragma mark Public

- (NSArray *)symbols {
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:[self length]];
    NSUInteger length = [self length];
    
    for (NSUInteger index = 0; index < length; index++) {
        [result addObject:[NSString stringWithFormat:@"%C", [self characterAtIndex:index]]];
    }
    
    return [result copy];
}

@end
