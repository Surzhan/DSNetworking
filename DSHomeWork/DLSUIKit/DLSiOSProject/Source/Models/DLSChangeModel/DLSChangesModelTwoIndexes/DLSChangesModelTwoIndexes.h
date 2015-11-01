//
//  DLSChangesModelTwoIndexes.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSChangeModel.h"

@interface DLSChangesModelTwoIndexes : DLSChangeModel
@property (nonatomic, readonly) NSUInteger  sourceIndex;
@property (nonatomic, readonly) NSUInteger  destinationIndex;

+ (instancetype)modelWithSourceIndex:(NSUInteger)sourceIndex
                    destinationIndex:(NSUInteger)destinationIndex
                               state:(DLSChangeModelState)state;

@end

@interface DLSChangesModelTwoIndexes (DLSIndexPath)
@property (nonatomic, readonly) NSIndexPath *sourceIndexPath;
@property (nonatomic, readonly) NSIndexPath *destinationIndexPath;

+ (instancetype)modelWithSourceIndexPath:(NSIndexPath *)sourceIndexPath
                    destinationIndexPath:(NSIndexPath *)destinationIndexPath
                                   state:(DLSChangeModelState)state;

@end
