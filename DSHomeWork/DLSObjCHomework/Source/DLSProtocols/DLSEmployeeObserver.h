//
//  DLSEmployeeObserver.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 03.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DLSEmployee;

@protocol DLSEmployeeObserver <NSObject>

@optional
- (void)employeeIsReady:(DLSEmployee *)employee;
- (void)employeeDidStartWork:(DLSEmployee *)employee;
- (void)employeeDidFinishWork:(DLSEmployee *)employee;

@end
