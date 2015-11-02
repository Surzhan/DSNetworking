//
//  DLSView.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DLSLoadingView;

@interface DLSView : UIView
@property (nonatomic, readonly, getter=isHiddenLoadingView) BOOL hiddenLoadingView;

- (DLSLoadingView *)newLoadingView;

- (void)hideLoadingView;
- (void)showLoadingView;

@end


