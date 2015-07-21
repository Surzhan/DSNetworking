//
//  DLSBuilding.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 14.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DLSRoom.h"

@interface DLSBuilding : NSObject
@property (nonatomic, copy)     NSString    *name;
@property (nonatomic, readonly) NSArray     *rooms;
@property (nonatomic, assign)   NSInteger   roomsCapacity;

- (instancetype)initWithRoom:(NSArray *)rooms;

- (void)addRoom:(DLSRoom *)room;
- (void)removeRoom:(DLSRoom *)room;

@end
