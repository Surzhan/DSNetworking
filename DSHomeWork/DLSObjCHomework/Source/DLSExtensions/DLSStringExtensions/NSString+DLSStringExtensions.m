//
//  NSString+DLSStringExtensions.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 01.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "NSString+DLSStringExtensions.h"

static const NSUInteger kDLSDefaultRandomStringLength = 20;

@implementation NSString (DLSStringExtensions)

#pragma mark -
#pragma mark Class Methods

+ (instancetype)alphanumericAlphabet {
    NSMutableString *string = [NSMutableString string];
    [string appendString:[self letterAlphabet]];
    [string appendString:[self numericAlphabet]];
    
    return [self stringWithString:string];
}

+ (instancetype)numericAlphabet {
    return [self alphabetWithRange:NSMakeRange('0', '9' - '0' + 1)];
}

+ (instancetype)lowercaseLetterAlphabet {
    return [self alphabetWithRange:NSMakeRange('a', 'z' - 'a' + 1)];
}

+ (instancetype)uppercaseLetterAlphabet {
    return [self alphabetWithRange:NSMakeRange('A', 'Z' - 'A' + 1)];
}

+ (instancetype)letterAlphabet {
    NSMutableString *string = [NSMutableString string];
    [string appendString:[self lowercaseLetterAlphabet]];
    [string appendString:[self uppercaseLetterAlphabet]];
    
    return [self stringWithString:string];
}

+ (instancetype)alphabetWithRange:(NSRange)range {
    NSMutableString *string = [NSMutableString string];
    for (unichar character = range.location; character < NSMaxRange(range); character++) {
        [string appendFormat:@"%C", character];
    }
    
    return [self stringWithString:string];
}

+ (instancetype)randomString {
    return [self randomStringWithLength:(arc4random() % (kDLSDefaultRandomStringLength + 1))];}

+ (instancetype)randomStringWithLength:(NSUInteger)length {
    return [self randomStringWithLength:length alphabet:[self alphanumericAlphabet]];
}

+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet {
    NSMutableString *string = [NSMutableString stringWithCapacity:length];
    NSUInteger alphabetLength = [alphabet length];
    for (NSUInteger index = 0; index < length; index++) {
        unichar randomSymbol = [alphabet characterAtIndex:(arc4random() % alphabetLength)];
        [string appendFormat:@"%C", randomSymbol];
    }
    
    return [self stringWithString:string];
}

#pragma mark -
#pragma mark Public

- (NSArray *)symbols {
    NSUInteger length = [self length];
    NSMutableArray *symbolsArray = [NSMutableArray arrayWithCapacity:length];
    for (NSUInteger index = 0; index < length; index++) {
        [symbolsArray addObject:[NSString stringWithFormat:@"%C", [self characterAtIndex:index]]];
    }
    
    return [[symbolsArray copy] autorelease];
}

@end
