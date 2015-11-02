//
//  DLSChangeModel.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DLSChangesModelOneIndex;
@class DLSChangesModelTwoIndexes;

typedef NS_ENUM(NSUInteger, DLSChangeModelState) {
    DLSChangeModelChangeAdded,
    DLSChangeModelChangeRemoved,
    DLSChangeModelChangeMoved
};

@interface DLSChangesModel : NSObject
@property (nonatomic, readonly) DLSChangeModelState state;

+ (instancetype)modelWithState:(DLSChangeModelState)state;

@end

@interface DLSChangesModel (DLSInitializers)

+ (DLSChangesModelOneIndex *)addModelWithIndex:(NSUInteger)index;
+ (DLSChangesModelOneIndex *)deleteModelWithIndex:(NSUInteger)index;
+ (DLSChangesModelTwoIndexes *)moveModelFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;

@end
