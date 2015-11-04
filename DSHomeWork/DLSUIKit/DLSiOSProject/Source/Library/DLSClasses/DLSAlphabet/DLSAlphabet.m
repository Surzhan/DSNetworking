//
//  DLSAlphabet.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 28.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAlphabet.h"

#import "DLSAlphabetWithString.h"
#import "DLSAlphabetWithRange.h"
#import "DLSAlphabetWithAlphabets.h"

@implementation DLSAlphabet

#pragma mark -
#pragma mark Class methods

+ (instancetype)alphabetWithString:(NSString *)string {
    return [[self alloc] initWithString:string];
}

+ (instancetype)alphabetWithStrings:(NSArray *)strings {
    return [[self alloc] initWithStrings:strings];
}

+ (instancetype)alphabetWithRange:(NSRange)range {
    return [[self alloc] alphabetWithRange:range];
}

+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets {
    return [[self alloc] initWithAlphabets:alphabets];
}

+ (instancetype)alphabetWithNumbers {
    NSRange range = NSMakeRange('0', 10);
    return [self alphabetWithRange:range];
}

+ (instancetype)alphabetWithLowercaseLetters {
    NSRange range = NSMakeRange('a', ('z' - 'a' + 1));
    return [self alphabetWithRange:range];
}

+ (instancetype)alphabetWithUppercaseLetters {
    NSRange range = NSMakeRange('A', ('Z' - 'A' + 1));
    return [self alphabetWithRange:range];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithString:(NSString *)string {
    return [[DLSAlphabetWithString alloc] initWithString:string];
}

- (instancetype)initWithStrings:(NSArray *)strings {
    return [[DLSAlphabetWithAlphabets alloc] initWithStrings:strings];
}

- (instancetype)initWithUnicodeRange:(NSRange)range {
    return [[DLSAlphabetWithRange alloc] initWithUnicodeRange:range];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    return [[DLSAlphabetWithAlphabets alloc] initWithAlphabets:alphabets];
}

#pragma mark -
#pragma mark Public Methods

- (NSArray *)string {
    NSMutableString *string = [NSMutableString stringWithCapacity:[self count]];
    for (NSString *symbol in self) {
        [string appendString:symbol];
    }
    
    return [string copy];
}

- (NSUInteger)count {
    [self doesNotRecognizeSelector:_cmd];
    
    return 0;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return [self stringAtIndex:index];
}

#pragma mark -
#pragma mark NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len
{
    state->mutationsPtr = 0;
    
    if (state->state >= self.count) {
        return 0;
    }
    
    NSUInteger itemsToGive = MIN(len, ([self count] - state->state));
    
    for (NSUInteger index = 0;  index < itemsToGive; ++index) {
        buffer[index] = self[index + state->state];
    }
    
    state->itemsPtr = buffer;
    state->state += itemsToGive;
    
    return itemsToGive;
}
    
@end
