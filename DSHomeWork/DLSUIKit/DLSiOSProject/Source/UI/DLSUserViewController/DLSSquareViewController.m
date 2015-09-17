//
//  DLSUserViewController.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 09.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSSquareViewController.h"

#import "DLSSquareHolderView.h"
#import "DLSMacros.h"

DLSViewControllerBaseViewProperty(DLSSquareViewController, squareView, DLSSquareHolderView);

@implementation DLSSquareViewController

#pragma mark -
#pragma mark Public

- (IBAction)onAnimateButton:(id)sender {
    [self.squareView squareAnimate];
}

#pragma mark -
#pragma mark View Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
