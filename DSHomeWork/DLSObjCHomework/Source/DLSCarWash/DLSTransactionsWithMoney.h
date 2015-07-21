//
//  DLSTransactionsWithMoney.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 21.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef DSHomeWork_DLSTransactionsWithMoney_h
#define DSHomeWork_DLSTransactionsWithMoney_h

@protocol DLSTransactionsWithMoney

- (void)addIncome:(NSDecimalNumber *)amount;
- (void)addExpense:(NSDecimalNumber *)amount;

@end

#endif
