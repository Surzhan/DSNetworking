//
//  DLSHuman.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 06.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSHuman.h"

@interface DLSHuman ()

@property (nonatomic, retain) NSMutableArray *mutableChildren;

@end

@implementation DLSHuman

@dynamic children;

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableChildren = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

#pragma mark -
#pragma mark Public

- (void)sayHello {
    NSLog(@"Hello!");
}

- (void)fight {
    NSLog(@"I fight");
}

- (void)birthChild {
    NSLog(@"I gave birth to children");
}

- (void)addChild:(DLSHuman *)child {
    [self.mutableChildren addObject:child];
}

- (void)removeChild:(DLSHuman *)child {
    [self.mutableChildren removeObject:child];
}

#pragma mark -
#pragma mark Private

#pragma mark -
#pragma mark Protocol

@end
