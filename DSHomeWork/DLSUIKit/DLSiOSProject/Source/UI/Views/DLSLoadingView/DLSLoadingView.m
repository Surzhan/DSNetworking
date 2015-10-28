//
//  DLSLoadingView.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSLoadingView.h"

#import "UINib+DLSExtentions.h"

static const NSTimeInterval kDLSAnimationDuration   = 2;
static const CGFloat        kDLSVisibleAlpha        = 1;

@interface DLSLoadingView ()

@end

@implementation DLSLoadingView

#pragma mark -
#pragma mark Class Methods

+ (instancetype)loadingViewWithSuperview:(UIView *)superview {
    DLSLoadingView *loadingView = [UINib objectWithClass:self];
    
    [superview addSubview:loadingView];
    loadingView.frame = superview.bounds;
    
    return loadingView;
}

#pragma mark -
#pragma mark Public

- (void)setVisible:(BOOL)visible animated:(BOOL)animated {
    [self setVisible:visible animated:animated completion:nil];
}

- (void)setVisible:(BOOL)visible animated:(BOOL)animated completion:(void(^)(void))handler {
    NSTimeInterval duration = animated ? kDLSAnimationDuration : 0;
    [UIView animateWithDuration:duration
                     animations:^{
                         self.alpha = visible ? kDLSVisibleAlpha : 0;
                     } completion:^(BOOL finished) {
                         _visible = visible;
                         
                         if (handler) {
                             handler();
                         }
                     }];
}

@end
