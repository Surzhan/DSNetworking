//
//  DLSArrayModel.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSModel.h"

@interface DLSArrayModel : DLSModel <NSFastEnumeration, NSCoding>
@property (nonatomic, readonly) NSArray     *models;
@property (nonatomic, readonly) NSUInteger  count;

- (void)addObject:(id)object;
- (void)removeObject:(id)object;

- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)moveObjectFromIndex:(NSUInteger)indexOne
                  toAtIndex:(NSUInteger)indexTwo;

- (NSUInteger)indexOfObject:(id)object;
- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)index;
- (void)setObject:(id)object atIndexedSubscript:(NSUInteger)index;

@end
