//
//  DLSObservableObject.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 22.08.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLSObservableObject : NSObject
@property (nonatomic, readonly) NSSet   *observerSet;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (BOOL)isObserved:(id)observer;

- (void)notifyObserversWithSelector:(SEL)selector;

@end
