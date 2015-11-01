//
//  DLSChangeModel.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSChangeModel.h"

#import "DLSChangesModelOneIndex.h"
#import "DLSChangesModelTwoIndexes.h"

@interface DLSChangeModel ()
@property (nonatomic, assign)   DLSChangeModelState  state;

@end

@implementation DLSChangeModel

#pragma mark -
#pragma mark Class Methods

+ (instancetype)modelWithState:(DLSChangeModelState)state {
    DLSChangeModel *result = [self new];
    result.state = state;
    
    return result;
}

@end

@implementation DLSChangeModel (DLSInitializers)

#pragma mark -
#pragma mark Class Methods

+ (DLSChangesModelOneIndex *)addModelWithIndex:(NSUInteger)index {
    return [DLSChangesModelOneIndex modelWithIndex:index state:DLSChangeModelChangeAdded];
}

+ (DLSChangesModelOneIndex *)deleteModelWithIndex:(NSUInteger)index{
    return [DLSChangesModelOneIndex modelWithIndex:index state:DLSChangeModelChangeRemoved];
}

+ (DLSChangesModelTwoIndexes *)moveModelFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex {
    return [DLSChangesModelTwoIndexes modelWithSourceIndex:fromIndex
                                          destinationIndex:toIndex
                                                     state:DLSChangeModelChangeMoved];
}

@end
