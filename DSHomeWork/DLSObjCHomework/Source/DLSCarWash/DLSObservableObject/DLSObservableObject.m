//
//  DLSObservableObject.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 22.08.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSObservableObject.h"

@interface DLSObservableObject ()
@property (nonatomic, retain) NSHashTable   *observers;

@end

@implementation DLSObservableObject

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.observers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.observers = [NSHashTable weakObjectsHashTable];
    }
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)observerSet {
    @synchronized(self.observers) {
        return [[self.observers copy] autorelease];
    }
}

#pragma mark -
#pragma mark Public

- (void)addObserver:(id)observer {
    @synchronized(self.observers) {
        [self.observers addObject:observer];
    }
}

- (void)removeObserver:(id)observer {
    @synchronized(self.observers) {
        [self.observers removeObject:observer];
    }
}

- (BOOL)isObserved:(id)observer {
    @synchronized(self.observers) {
        return [self.observers containsObject:observer];
    }
}

- (void)notifyObserversWithSelector:(SEL)selector {
    [self notifyObserversWithSelector:selector];
}
@end
