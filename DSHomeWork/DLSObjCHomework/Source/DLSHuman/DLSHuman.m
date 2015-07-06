//
//  DLSHuman.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 06.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSHuman.h"

@implementation DLSHuman

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self->_name = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

#pragma mark -
#pragma mark Public

- (void)humanSayHello {
    NSLog(@"Hello!");
}

- (void)humanFight {
    NSLog(@"I fight");
}

- (void)humanBirthChild {
    NSLog(@"I gave birth to children");
}


#pragma mark -
#pragma mark Private

#pragma mark -
#pragma mark Protocol

@end
