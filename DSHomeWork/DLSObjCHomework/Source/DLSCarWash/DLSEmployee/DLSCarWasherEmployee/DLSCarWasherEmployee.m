//
//  DLSCarWasherEmployee.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 20.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSCarWasherEmployee.h"

@interface DLSCarWasherEmployee ();

- (void)toWashCar;

@end

@implementation DLSCarWasherEmployee

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Accessors

#pragma mark -
#pragma mark Public

- (id)performSpecificOperation {
    [super performSpecificOperation];
    [self toWashCar];
    
    return nil;
}

#pragma mark -
#pragma mark Private

- (void)toWashCar {
    self.status = YES;
    
}

#pragma mark -
#pragma mark Protocol

@end
