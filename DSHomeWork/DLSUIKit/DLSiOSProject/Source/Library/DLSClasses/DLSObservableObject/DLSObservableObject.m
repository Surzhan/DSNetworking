//
//  DLSObservableObject.m
//  Task1_Square
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSObservableObject.h"

@interface DLSObservableObject ()
@property (nonatomic, retain) NSHashTable *observers;

@end

@implementation DLSObservableObject

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.observers = nil;
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

- (NSSet *)observersSet {
    return self.observers.setRepresentation;
}

#pragma mark -
#pragma mark Public Methods

- (void)addObserver:(id)observer {
    [self.observers addObject:observer];
}

- (void)removeObserver:(id)observer {
    [self.observers removeObject:observer];
}

- (BOOL)isObservedByObject:(id)observer {
    return [self.observers containsObject:observer];
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
 
}

@end
