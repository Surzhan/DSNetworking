//
//  DLSClusterAlphabet.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 12.08.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSClusterAlphabet.h"

@interface DLSClusterAlphabet ()
@property (nonatomic, retain) NSMutableArray    *alphabets;
@property (nonatomic, assign) NSUInteger        count;

@end

@implementation DLSClusterAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.alphabets = nil;
    
    [super dealloc];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    self = [super init];
    
    if (self) {
        self.alphabets = [NSMutableArray arrayWithArray:alphabets];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)count {
    NSArray *alphabets = self.alphabets;
    NSUInteger count = 0;
    for (DLSAlphabet *alphabet in alphabets) {
        count += [alphabet count];
    }
    
    return count;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    NSAssert(self.count > index, NSRangeException);
    
    for (DLSAlphabet *alphabet in self.alphabets) {
        NSUInteger count = [alphabet count];
        if (count > index) {
            return [alphabet objectAtIndexedSubscript:index];
        }
        
        index -= count;
    }
    
    return nil;
}

- (NSString *)string {
    NSMutableString *string = [NSMutableString stringWithCapacity:self.count];
    for (DLSAlphabet *alphabet in self.alphabets) {
        [string appendString:[alphabet string]];
    }
    
    return [[string copy] autorelease];
}

@end
