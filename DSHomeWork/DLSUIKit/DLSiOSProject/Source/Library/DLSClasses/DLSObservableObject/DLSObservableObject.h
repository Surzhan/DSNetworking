//
//  DLSObservableObject.h
//  Task1_Square
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLSObservableObject : NSObject
@property (nonatomic, assign)   NSUInteger  state;
@property (nonatomic, readonly) NSSet       *observersSet;

- (void)setState:(NSUInteger)state withObject:(id)object;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (BOOL)isObservedByObject:(id)observer;

- (void)notifyObservers;
- (void)notifyObserversWithObject:(id)object;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object;

- (void)performBlockWithNotification:(void(^)(void))block;
- (void)performBlockWithoutNotification:(void(^)(void))block;

- (SEL)selectorForState:(NSUInteger)state;

@end
