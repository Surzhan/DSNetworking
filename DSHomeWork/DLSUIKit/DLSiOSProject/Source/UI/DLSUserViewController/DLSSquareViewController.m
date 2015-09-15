//
//  DLSUserViewController.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 09.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSSquareViewController.h"

@interface DLSSquareViewController ()
@property (nonatomic, readonly) DLSSquareHolderView   *squareView;

@end

@implementation DLSSquareViewController

@dynamic squareView;

#pragma mark -
#pragma mark Accessors

- (DLSSquareHolderView *)squareView {
    if ([self isViewLoaded] && [self.view isKindOfClass:[DLSSquareHolderView class]]) {
        return (DLSSquareHolderView *)self.view;
    }
    
    return nil;
}

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
