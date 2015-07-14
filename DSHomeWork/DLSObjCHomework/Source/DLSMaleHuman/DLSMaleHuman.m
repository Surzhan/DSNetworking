//
//  DLSMaleHuman.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 14.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSMaleHuman.h"

@implementation DLSMaleHuman

static const NSString *const kFight = @"I fight";

#pragma mark -
#pragma mark Public

- (id)performGenderSpecificOperation {
    [super performGenderSpecificOperation];
    [self fight];
    
    return nil;
}

#pragma mark -
#pragma mark Private

- (void)fight {
    NSLog(kFight);
}


@end
