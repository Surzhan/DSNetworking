//
//  DLSAlphabetWithRange.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 28.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAlphabetWithRange.h"

@interface DLSAlphabetWithRange ()
@property (nonatomic, assign) NSRange range;

@end

@implementation DLSAlphabetWithRange

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithUnicodeRange:(NSRange)range {
    self = [super init];
    
    if (self) {
        self.range = range;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)symbols {
    NSRange range = self.range;
    NSMutableArray *array = [NSMutableArray arrayWithCapacity:NSMaxRange(range)];
    
    for (unichar character = range.location; character < NSMaxRange(range); character++) {
        NSString *string = [NSString stringWithFormat:@"%C", character];
        [array addObject:string];
    }
    
    return [array copy];
}

- (NSUInteger)count {
    return self.range.length;
}

- (NSString *)symbolAtIndex:(NSUInteger)index {
    return [NSString stringWithFormat:@"%C", (unichar)(self.range.location + index)];
}

@end

