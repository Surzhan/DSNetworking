//
//  DLSBuilding.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 14.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSBuilding.h"

@interface DLSBuilding ()

@property (nonatomic, retain) NSMutableArray *mutableRooms;

@end

@implementation DLSBuilding

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableRooms = nil;
    
    [super dealloc];
}

- (instancetype)initWithRoom:(NSArray *)rooms {
    self = [super init];
    if (self) {
        self.mutableRooms = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)rooms {
    return [[self.mutableRooms copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)addRoom:(DLSRoom *)room {
    if (Nil != room) {
        [self.mutableRooms addObject:room];
    }
}

- (void)removeRoom:(DLSRoom *)room {
    
}

#pragma mark -
#pragma mark Private

#pragma mark -
#pragma mark Protocol

@end
