//
//  DLSArrayModel.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSArrayModel.h"

#import "DLSChangesModel.h"

#import "NSMutableArray+DLSExtensions.h"

static NSString * const kDLSMutableArray = @"mutableArray";

@interface DLSArrayModel ()
@property (nonatomic, retain)   NSMutableArray  *mutableObjects;

@end

@implementation DLSArrayModel

@dynamic models;

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObjects = [NSMutableArray new];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)models {
    return [self.mutableObjects copy];
}

- (NSUInteger)count {
    return self.mutableObjects.count;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)indexOfObject:(id)object {
    return [self.mutableObjects indexOfObject:object];
}

- (void)addObject:(id)object {
    [self insertObject:object atIndex:self.count];
}

- (void)removeObject:(id)object {
    NSUInteger index = [self.mutableObjects indexOfObject:object];
    [self removeObjectAtIndex:index];
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    [self.mutableObjects removeObjectAtIndex:index];
    
    [self setState:DLSModelDidChange withObject:[DLSChangesModel deleteModelWithIndex:index]];
}

- (void)insertObject:(id)anObject atIndex:(NSUInteger)index {
    NSMutableArray *mutableObject = self.mutableObjects;
    
    if (index == self.count) {
        [mutableObject addObject:anObject];
    } else {
        [mutableObject insertObject:anObject atIndex:index];
    }
    
    [self setState:DLSModelDidChange withObject:[DLSChangesModel addModelWithIndex:index]];
}

- (void)moveObjectFromIndex:(NSUInteger)fromIndex toAtIndex:(NSUInteger)toIndex {
    [self.mutableObjects moveObjectAtIndex:fromIndex toIndex:toIndex];
    [self setState:DLSModelDidChange withObject:[DLSChangesModel moveModelFromIndex:fromIndex
                                                                              toIndex:toIndex]];
}

- (id)objectAtIndex:(NSUInteger)index {
    return self.mutableObjects[index];
}

- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return [self objectAtIndex:index];
}

- (void)setObject:(id)object atIndexedSubscript:(NSUInteger)index {
    [self.mutableObjects setObject:object atIndexedSubscript:index];
}

#pragma mark -
#pragma mark NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(__unsafe_unretained id  [])buffer
                                    count:(NSUInteger)len
{
    return [self.mutableObjects countByEnumeratingWithState:state objects:buffer count:len];
}

#pragma mark -
#pragma mark NSCoding

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeObject:self.mutableObjects forKey:kDLSMutableArray];
}

- (id)initWithCoder:(NSCoder *)aDecoder {
    if (self) {
        self.mutableObjects = [[aDecoder decodeObjectForKey:kDLSMutableArray] mutableCopy];
    }
    
    return self;
}

@end
