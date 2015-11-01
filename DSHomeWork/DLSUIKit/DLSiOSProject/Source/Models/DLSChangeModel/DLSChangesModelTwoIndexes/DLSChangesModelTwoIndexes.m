//
//  DLSChangesModelTwoIndexes.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSChangesModelTwoIndexes.h"

@interface DLSChangesModelTwoIndexes ()
@property (nonatomic, assign) NSUInteger    sourceIndex;
@property (nonatomic, assign) NSUInteger    destinationIndex;

@end

@implementation DLSChangesModelTwoIndexes

#pragma mark -
#pragma mark Class Methods

+ (instancetype)modelWithSourceIndex:(NSUInteger)sourceIndex
                    destinationIndex:(NSUInteger)destinationIndex
                               state:(DLSChangeModelState)state
{
    DLSChangesModelTwoIndexes *result = [self modelWithState:state];
    result.sourceIndex = sourceIndex;
    result.destinationIndex = destinationIndex;
    
    return result;
}

@end

@implementation DLSChangesModelTwoIndexes (DLSIndexPath)

@dynamic sourceIndexPath;
@dynamic destinationIndexPath;

+ (instancetype)modelWithSourceIndexPath:(NSIndexPath *)sourceIndexPath
                    destinationIndexPath:(NSIndexPath *)destinationIndexPath
                                   state:(DLSChangeModelState)state
{
    return [self modelWithSourceIndex:sourceIndexPath.row
                     destinationIndex:destinationIndexPath.row
                                state:state];
}

#pragma mark -
#pragma mark Accessors

- (NSIndexPath *)sourceIndexPath {
    return [NSIndexPath indexPathForRow:self.sourceIndex];
}

- (NSIndexPath *)destinationIndexPath {
    return [NSIndexPath indexPathForRow:self.destinationIndex];
}


@end
