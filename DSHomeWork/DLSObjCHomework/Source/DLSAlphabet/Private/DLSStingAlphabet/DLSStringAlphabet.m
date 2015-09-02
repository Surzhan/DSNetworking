//
//  DLSStingAlphabet.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 12.08.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSStringAlphabet.h"

@interface DLSStringAlphabet ()
@property (nonatomic, retain) NSArray   *strings;

@end


@implementation DLSStringAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
     self.strings = nil;
    
    [super dealloc];
}

- (id)initWithStrings:(NSArray *)strings {
    self = [super init];
    
    if (self) {
        self.strings = strings;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)count {
    return [self.strings count];
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    NSArray *strings = self.strings;
    
    NSAssert([strings count] > index, NSRangeException);
    
    return [strings objectAtIndex:index];
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id *)buffer
                                    count:(NSUInteger)count
{
    return [self.strings countByEnumeratingWithState:state objects:buffer count:count];
}

@end
