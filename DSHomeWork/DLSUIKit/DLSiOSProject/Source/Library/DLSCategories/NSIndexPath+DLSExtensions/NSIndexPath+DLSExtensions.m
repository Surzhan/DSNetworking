//
//  NSIndexPath+DLSExtensions.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "NSIndexPath+DLSExtensions.h"

static const NSUInteger kDLSSectionNumber = 0;

@implementation NSIndexPath (DLSExtensions)

+ (instancetype)indexPathForRow:(NSUInteger)row {
    return [self indexPathForRow:row inSection:kDLSSectionNumber];
}

@end
