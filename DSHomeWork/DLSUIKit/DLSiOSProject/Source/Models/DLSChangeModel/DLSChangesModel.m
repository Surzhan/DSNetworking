//
//  DLSChangeModel.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSChangesModel.h"

#import "DLSChangesModelOneIndex.h"
#import "DLSChangesModelTwoIndexes.h"

@interface DLSChangesModel ()
@property (nonatomic, assign)   DLSChangeModelState  state;

@end

@implementation DLSChangesModel

#pragma mark -
#pragma mark Class Methods

+ (instancetype)modelWithState:(DLSChangeModelState)state {
    DLSChangesModel *result = [self new];
    result.state = state;
    
    return result;
}

@end

@implementation DLSChangesModel (DLSInitializers)

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
