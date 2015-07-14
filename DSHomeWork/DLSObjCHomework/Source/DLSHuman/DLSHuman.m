//
//  DLSHuman.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 06.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSHuman.h"

static const NSString *const kSayHello = @"Hello!";

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

- (instancetype)initWithName:(NSString *)name
                         age:(NSUInteger)age
{
    self = [super init];
    if (self) {
        self.name = name;
        self.age = age;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

//- (NSArray *)children {
//    return [[self.mutableChildren copy] autorelease];

#pragma mark -
#pragma mark Public

- (void)sayHello {
    NSLog(kSayHello);
}

- (void)addChild:(DLSHuman *)child {
    [self.mutableChildren addObject:child];
}

- (void)removeChild:(DLSHuman *)child {
    [self.mutableChildren removeObject:child];
}

- (id)performGenderSpecificOperation {
    
    return nil;
}

#pragma mark -
#pragma mark Private

#pragma mark -
#pragma mark Protocol

@end
