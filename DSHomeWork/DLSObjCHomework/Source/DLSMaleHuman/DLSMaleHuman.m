//
//  DLSMaleHuman.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 14.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSMaleHuman.h"

static const NSString *const kDLSFight = @"I fight";

@interface DLSMaleHuman ()

- (void)fight;

@end

@implementation DLSMaleHuman

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
    NSLog(kDLSFight);
}

@end
