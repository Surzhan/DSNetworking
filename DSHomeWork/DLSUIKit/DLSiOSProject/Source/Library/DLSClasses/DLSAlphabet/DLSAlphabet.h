//
//  DLSAlphabet.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 28.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLSAlphabet : NSObject  <NSFastEnumeration>

+ (instancetype)alphabetWithString:(NSString *)string;
+ (instancetype)alphabetWithRange:(NSRange)range;
+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets;

+ (instancetype)alphabetWithNumbers;
+ (instancetype)alphabetWithLowercaseLetters;
+ (instancetype)alphabetWithUppercaseLetters;

- (NSString*)getRandomLetter;

@end
