//
//  DLSAlphabetWithString.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 28.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAlphabetWithString.h"

@interface DLSAlphabetWithString ()
@property (nonatomic, retain) NSMutableString *mutableStringWithSymbols;

@end

@implementation DLSAlphabetWithString

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableStringWithSymbols = nil;
}

- (instancetype)initWithString:(NSString *)string {
    self = [super init];
    
    if (self) {
        self.mutableStringWithSymbols = [NSMutableString stringWithString:string];
    }
    
    return self;
}

#pragma mark -
#pragma mark Overriden parent method

- (NSArray *)symbols {
    NSMutableArray *array = [NSMutableArray array];
    NSString *string = [self.mutableStringWithSymbols copy];
    NSUInteger length = [string length];
    
    for (NSUInteger iterator = 0; iterator < length; iterator++) {
        NSString* character = [NSString stringWithFormat:@"%C", [string characterAtIndex:iterator]];
        [array addObject:character];
    }
    
    return [array copy];
}

- (NSUInteger)count {
    return [self.mutableStringWithSymbols length];
}

- (NSString *)symbolAtIndex:(NSUInteger)index {
    return [NSString stringWithFormat:@"%C", [self.mutableStringWithSymbols characterAtIndex:index]];
}

@end
