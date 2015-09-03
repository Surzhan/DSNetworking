//
//  DLSTransactionsWithMoney.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 21.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DLSEmployee;

@protocol DLSTransactionsWithMoney <NSObject>

@optional
- (BOOL)youSolvent:(NSDecimalNumber *)amount;
- (void)giveMoney:(NSDecimalNumber *)amount receiver:(DLSEmployee *)employee;
- (void)getMoney:(NSDecimalNumber *)amount transmitter:(DLSEmployee *)employee;

@end
