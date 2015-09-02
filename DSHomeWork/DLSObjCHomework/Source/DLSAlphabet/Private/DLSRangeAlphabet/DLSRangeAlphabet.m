//
//  DLSRangeAlphabet.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 12.08.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSRangeAlphabet.h"

@interface DLSRangeAlphabet ()
@property (nonatomic, assign) NSRange range;

@end

@implementation DLSRangeAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (id)initWithRange:(NSRange)range {
    self = [super init];
    
    if (self) {
        self.range = range;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)count {
    return self.range.length;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    NSRange range = self.range;
    NSAssert(range.length > index, NSRangeException);
    
    return [NSString stringWithFormat:@"%C", (unichar)(range.location + index)];
}

@end
