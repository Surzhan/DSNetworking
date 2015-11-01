//
//  UIViewController+DLSExtentions.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 17.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "UIViewController+DLSExtentions.h"

@implementation UIViewController (DLSExtensions)

#pragma mark -
#pragma mark Class Methods

+ (instancetype)controller {
    return [[self alloc] initWithNibName:[self nibName] bundle:nil];
}

+ (NSString *)nibName {
    return nil;
}

@end
