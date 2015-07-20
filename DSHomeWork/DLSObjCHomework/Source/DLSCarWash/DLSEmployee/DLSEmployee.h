//
//  DLSEmployee.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 20.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLSEmployee : NSObject
@property (nonatomic, copy)     NSString    *name;
@property (nonatomic, assign)   BOOL        status; // YES == busy or NO == free

- (id)performSpecificOperation;

@end
