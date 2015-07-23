//
//  DLSEmployee.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 20.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSEmployee.h"

#import "DLSTransactionsWithMoney.h"

@implementation DLSEmployee

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.wallet = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

#pragma mark -
#pragma mark Public

- (id)performSpecificOperation {

    return nil;
}

#pragma mark -
#pragma mark Private

#pragma mark -
#pragma mark Protocol

@end
