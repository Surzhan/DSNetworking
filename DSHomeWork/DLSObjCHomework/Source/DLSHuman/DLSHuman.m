//
//  DLSHuman.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 06.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSHuman.h"
#import "DLSMaleHuman.h"
#import "DLSFemaleHuman.h"

#import "NSObject+DLSObjectExtensions.h"

static const NSString *const kDLSSayHello = @"Hello!";

@interface DLSHuman ()
@property (nonatomic, retain) NSMutableArray *mutableChildren;

+ (Class)humanClassForGender:(DLSHumanGender)gender;

@end

@implementation DLSHuman

@dynamic children;

#pragma mark -
#pragma mark Class Methods

+ (Class)humanClassForGender:(DLSHumanGender)gender {
    return kDLSHumanMale == gender ? [DLSMaleHuman class] : [DLSFemaleHuman class];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableChildren = nil;
    
    [super dealloc];
}

- (instancetype)initWithGender:(DLSHumanGender)gender {
    self = [super init];
    
    Class humanClass = [[self class] humanClassForGender:gender];
    [self release];
    
    return [[humanClass alloc] init];
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)children {
    return [[self.mutableChildren copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)sayHello {
    NSLog(kDLSSayHello);
    
    for (DLSHuman *child in self.mutableCopy){
        [child sayHello];
    }
}

- (id)performGenderSpecificOperation {
    
    return nil;
}

- (void)addChild:(DLSHuman *)child {
    if (nil != child && (NO == [self.mutableChildren containsObject:child])) {
    [self.mutableChildren addObject:child];
    }
}

- (void)removeChild:(DLSHuman *)child {
    [self.mutableChildren removeObject:child];
}

@end
