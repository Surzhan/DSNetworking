//
//  DLSFemaleHuman.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 14.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSFemaleHuman.h"

static const NSString *const kBirthChild = @"I gave birth to children";

@implementation DLSFemaleHuman

#pragma mark -
#pragma mark Public

- (id)performGenderSpecificOperation {
    [super performGenderSpecificOperation];
    [self birthChild];
    
    return nil;
}

#pragma mark -
#pragma mark Private

- (void)birthChild {
    NSLog(kBirthChild);
}

@end
