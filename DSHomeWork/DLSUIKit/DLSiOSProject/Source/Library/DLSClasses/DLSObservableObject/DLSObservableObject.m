//
//  DLSObservableObject.m
//  Task1_Square
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSObservableObject.h"

@interface DLSObservableObject ()
@property (nonatomic, retain)   NSHashTable *mutableObservers;
@property (nonatomic, assign)   BOOL        shouldNotify;

- (void)performBlock:(void(^)(void))block shouldNotify:(BOOL)shouldNotify;

@end

@implementation DLSObservableObject

@synthesize state = _state;

@dynamic observersSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableObservers = nil;
}

- (instancetype)init {
    self = [super init];
    
    if (self) {
        self.mutableObservers = [NSHashTable weakObjectsHashTable];
        self.shouldNotify = YES;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)observersSet {
    @synchronized(self) {
        return self.mutableObservers.setRepresentation;
    }
}

- (void)setState:(NSUInteger)state {
    [self setState:state withObject:nil];
}

- (NSUInteger)state {
    @synchronized(self) {
        return _state;
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)setState:(NSUInteger)state withObject:(id)object {
    @synchronized(self) {
        if (_state != state) {
            _state = state;
        }
        
        if (self.shouldNotify) {
            [self notifyObserversWithObject:object];
        }
    }
}

- (void)addObserver:(id)observer {
    @synchronized(self) {
        [self.mutableObservers addObject:observer];
    }
}

- (void)removeObserver:(id)observer {
    @synchronized(self) {
        [self.mutableObservers removeObject:observer];
    }
}

- (BOOL)isObservedByObject:(id)observer {
    @synchronized(self) {
        return [self.mutableObservers containsObject:observer];
    }
}

- (void)notifyObservers;{
    [self notifyObserversWithObject:nil];
}

- (void)notifyObserversWithObject:(id)object {
    [self notifyObserversWithSelector:[self selectorForState:self.state] withObject:object];
}

#pragma clang dagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
    for (id observer in self.mutableObservers) {
        if ([observer respondsToSelector:selector]) {
            [observer performSelector:selector withObject:self withObject:object];
        }
    }
}

#pragma clang diagnostic pop

- (void)performBlockWithNotification:(void(^)(void))block {
    [self performBlock:block shouldNotify:YES];
}

- (void)performBlockWithoutNotification:(void(^)(void))block {
    [self performBlock:block shouldNotify:NO];
}

- (SEL)selectorForState:(NSUInteger)state {
    return nil;
}

#pragma mark -
#pragma mark Private

- (void)performBlock:(void(^)(void))block shouldNotify:(BOOL)shouldNotify {
    @synchronized(self) {
        BOOL state = self.shouldNotify;
        self.shouldNotify = shouldNotify;
        
        if (block) {
            block();
        }
        
        self.shouldNotify = state;
    }
}

@end
