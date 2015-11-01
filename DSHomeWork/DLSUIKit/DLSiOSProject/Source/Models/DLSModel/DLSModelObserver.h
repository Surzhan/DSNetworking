//
//  DLSModelObserver.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 01.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DLSModel;

@protocol DLSModelObserver <NSObject>

@optional
- (void)modelDidLoad:(DLSModel *)model;
- (void)modelWillLoad:(DLSModel *)model;
- (void)modelDidFailLoading:(DLSModel *)model;
- (void)model:(DLSModel *)model didChangeWithObject:(id)object;

@end
