//
//  DLSChangesModelOneIndex.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSChangesModelOneIndex.h"

#import "NSIndexPath+DLSExtensions.h"

@interface DLSChangesModelOneIndex ()
@property (nonatomic, assign) NSUInteger index;

@end

@implementation DLSChangesModelOneIndex

#pragma mark -
#pragma mark Class Methods

+ (instancetype)modelWithIndex:(NSUInteger)index state:(DLSChangeModelState)state {
    DLSChangesModelOneIndex *result = [self modelWithState:state];
    result.index = index;
    
    return result;
}

@end

@implementation DLSChangesModelOneIndex (DLSIndexPath)

@dynamic indexPath;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)modelWithIndexPath:(NSIndexPath *)indexPath state:(DLSChangeModelState)state {
    return [self modelWithIndex:indexPath.row state:state];
}

#pragma mark -
#pragma mark Accessors

- (NSIndexPath *)indexPath {
    return [NSIndexPath indexPathForRow:self.index];
}

@end
