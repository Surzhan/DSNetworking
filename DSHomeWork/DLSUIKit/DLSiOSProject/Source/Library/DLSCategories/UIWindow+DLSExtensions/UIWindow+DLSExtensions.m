//
//  UIWindow+DLSExtensions.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 15.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "UIWindow+DLSExtensions.h"

@implementation UIWindow (DLSExtensions)

+ (instancetype)window {
    return [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
}

@end
