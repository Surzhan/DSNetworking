//
//  DLSUserViewController.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 09.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSUserViewController.h"

@interface DLSUserViewController ()

@end

@implementation DLSUserViewController

@dynamic squareView;

#pragma mark -
#pragma mark Accessors

- (DLSHolderViewSquare *)squareView {
    if ([self isViewLoaded] && [self.view isKindOfClass:[DLSHolderViewSquare class]]) {
        return (DLSHolderViewSquare *)self.view;
    }
    
    return nil;
}

#pragma mark -
#pragma mark

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
