//
//  DLSObservableObject.h
//  Task1_Square
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLSObservableObject : NSObject
@property (nonatomic, readonly) NSSet   *observersSet;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (BOOL)isObservedByObject:(id)observer;

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object;

@end
