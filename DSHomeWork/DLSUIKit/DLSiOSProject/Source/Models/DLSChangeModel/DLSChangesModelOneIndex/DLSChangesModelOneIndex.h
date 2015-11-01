//
//  DLSChangesModelOneIndex.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSChangeModel.h"

@interface DLSChangesModelOneIndex : DLSChangeModel
@property (nonatomic, readonly) NSUInteger  index;

+ (instancetype)modelWithIndex:(NSUInteger)index state:(DLSChangeModelState)state;

@end

@interface DLSChangesModelOneIndex (DLSIndexPath)
@property (nonatomic, readonly) NSIndexPath *indexPath;

+ (instancetype)modelWithIndexPath:(NSIndexPath *)indexPath state:(DLSChangeModelState)state;

@end
