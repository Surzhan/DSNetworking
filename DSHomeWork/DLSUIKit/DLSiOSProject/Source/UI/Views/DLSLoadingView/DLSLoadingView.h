//
//  DLSLoadingView.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DLSLoadingView : UIView
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView  *activityIndicatorLoadingView;
@property (nonatomic, assign, getter=isVisible) BOOL            visible;

+ (instancetype)loadingViewWithSuperview:(UIView *)superview;

- (void)setVisible:(BOOL)visible animated:(BOOL)animated;
- (void)setVisible:(BOOL)visible animated:(BOOL)animated completion:(void(^)(void))handler;

@end
