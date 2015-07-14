//
//  NSObject+DLSObjectExtensions.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 14.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "NSObject+DLSObjectExtensions.h"

@implementation NSObject (DLSObjectExtensions)

#pragma mark -
#pragma mark Class Methods

+ (id)object {
    return [[[self alloc] init] autorelease];
}

@end
