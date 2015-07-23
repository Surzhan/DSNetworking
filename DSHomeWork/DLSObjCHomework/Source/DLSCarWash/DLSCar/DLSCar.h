//
//  DLSCar.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 14.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DLSTransactionsWithMoney.h"

@interface DLSCar : NSObject <DLSTransactionsWithMoney>
@property (nonatomic, assign)   BOOL            dirty;
@property (nonatomic, assign)   NSDecimalNumber *wallet;

@end
