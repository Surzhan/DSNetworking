//
//  DLSAlphabetWithAlphabets.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 28.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAlphabetWithAlphabets.h"

@interface DLSAlphabetWithAlphabets ()
@property (nonatomic, strong) NSMutableArray *strings;

@end

@implementation DLSAlphabetWithAlphabets

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.strings = nil;
}

- (instancetype)initWithStrings:(NSArray *)strings {
    self = [super init];
    
    if (self) {
        self.strings = [NSMutableArray arrayWithArray:strings];
    }
    
    return self;
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    self = [super init];
    
    if (self) {
        self.strings = [NSMutableArray array];
        
        for (DLSAlphabet *alphabet in alphabets) {
            for (NSUInteger i = 0; i < [alphabet count]; i++) {
                [self.strings addObject:[alphabet stringAtIndex:i]];
            }
        }
    }
    
    return self;
}

#pragma mark -
#pragma mark Overriden parent method

- (NSArray *)symbols {
    return [self.strings copy];
}

- (NSUInteger)count {
    return [self.strings count];
}

- (NSString *)symbolAtIndex:(NSUInteger)index {
    return [self.strings objectAtIndex:index];
}

@end
