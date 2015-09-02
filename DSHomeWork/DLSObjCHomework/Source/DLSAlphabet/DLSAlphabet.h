//
//  DLSAlphabet.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 12.08.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLSAlphabet : NSObject  <NSFastEnumeration>

+ (instancetype)alphabetWithSymbols:(NSString *)symbols;
+ (instancetype)alphabetWithStrings:(NSArray *)strings;
+ (instancetype)alphabetWithRange:(NSRange)range;
+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets;

- (instancetype)initWithSymbols:(NSString *)symbols;
- (instancetype)initWithStrings:(NSArray *)strings;
- (instancetype)initWithRange:(NSRange)range;
- (instancetype)initWithAlphabets:(NSArray *)alphabets;

- (NSString *)string;
- (NSUInteger)count;
- (NSString *)stringAtIndex:(NSUInteger)index;
- (NSString *)objectAtIndexedSubscript:(NSUInteger)index;

@end
