//
//  DLSAlphabet.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 12.08.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAlphabet.h"
#import "DLSClusterAlphabet.h"
#import "DLSStringAlphabet.h"
#import "DLSRangeAlphabet.h"

#import "NSString+DLSStringExtensions.h"

@implementation DLSAlphabet

#pragma mark -
#pragma mark Class Methods

+ (instancetype)alphabetWithSymbols:(NSString *)symbols {
    return [self alphabetWithStrings:[symbols symbols]];
}

+ (instancetype)alphabetWithStrings:(NSArray *)strings {
    return [[[self alloc] initWithStrings:strings] autorelease];
}

+ (instancetype)alphabetWithRange:(NSRange)range {
    return [[[self alloc] initWithRange:range] autorelease];
}

+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets {
    return [[[self alloc] initWithAlphabets:alphabets] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithSymbols:(NSString *)symbols {
    return [self initWithStrings:[symbols symbols]];
}

- (instancetype)initWithStrings:(NSArray *)strings {
    [self release];
    
    return [[DLSStringAlphabet alloc] initWithStrings:strings];
}

- (instancetype)initWithRange:(NSRange)range {
    [self release];
    
    return [[DLSRangeAlphabet alloc] initWithRange:range];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    [self release];
    
    return [[DLSClusterAlphabet alloc] initWithAlphabets:alphabets];
}

#pragma mark -
#pragma mark Public

- (NSString *)string {
    NSMutableString *string = [NSMutableString string];
    for (NSString *symbol in self) {
        [string appendString:symbol];
    }
    
    return [[string copy] autorelease];
}

- (NSUInteger)count {
    [super doesNotRecognizeSelector:_cmd];
    
    return 0;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

- (NSString *)objectAtIndexedSubscript:(NSUInteger)index {
    return [self stringAtIndex:index];
}

#pragma mark -
#pragma mark Private

#pragma mark -
#pragma mark NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id *)buffer
                                    count:(NSUInteger)count
{
    state->mutationsPtr = (unsigned long *)self;
    
    NSUInteger currentOffset = state->state;
    NSUInteger length = MIN(currentOffset + count, [self count]);
    length -= currentOffset;
    
    for (NSUInteger index = 0; index < length; index++) {
        buffer[index] = [self objectAtIndexedSubscript:(currentOffset + index)];
    }
    
    state->itemsPtr = buffer;
    state->state += length;
    
    return length;
}

@end

