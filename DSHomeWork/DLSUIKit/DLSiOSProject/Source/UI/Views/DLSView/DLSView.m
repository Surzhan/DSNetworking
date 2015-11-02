//
//  DLSView.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSView.h"
#import "DLSLoadingView.h"

@interface DLSView ()
@property (nonatomic, strong) DLSLoadingView *loadingView;

@end

@implementation DLSView

@dynamic hiddenLoadingView;

#pragma mark -
#pragma mark Accessors

- (BOOL)isHiddenLoadingView {
    return self.loadingView.visible;
}

#pragma mark -
#pragma mark Public

- (DLSLoadingView *)newLoadingView {
    return [DLSLoadingView loadingViewWithSuperview:self];
}

- (void)hideLoadingView {
    self.loadingView.visible = NO;
}

- (void)showLoadingView {
    [self bindLoadingView];
    self.loadingView.visible = YES;
}

- (void)bindLoadingView {
    if (!self.loadingView) {
        self.loadingView = [self newLoadingView];
    }
}

@end
