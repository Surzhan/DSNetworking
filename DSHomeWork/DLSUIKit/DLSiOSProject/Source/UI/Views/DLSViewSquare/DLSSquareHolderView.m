//
//  DLSViewSquare.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 09.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSSquareHolderView.h"
#import "DLSConstants.h"

static const NSTimeInterval kDLSAnimationDuration   = 1;
static const NSTimeInterval kDLSAnimationDelay      = 0;

static NSString * kDLSAnimateButtonTitleStart   = @"START";
static NSString * kDLSAnimateButtonTitleStop    = @"STOP";

@interface DLSSquareHolderView ()
@property (nonatomic, assign, getter=isMoving)  BOOL  animate;

- (CGRect)pointForSquarePosition:(DLSSquarePosition)squarePosition;
- (NSString *)changeTitleAnimateButton;
- (void)animate;

@end

@implementation DLSSquareHolderView

#pragma mark -
#pragma mark Public

- (void)setSquarePosition:(DLSSquarePosition)squarePosition
                 animated:(BOOL)animation
{
  [self setSquarePosition:squarePosition animated:NO completionHandler:nil];
}

- (void)setSquarePosition:(DLSSquarePosition)squarePosition
                 animated:(BOOL)animation
        completionHandler:(void(^)(void))animationCompletion
{
    UIView *squareView = self.squareView;
    NSTimeInterval interval = animation ? kDLSAnimationDuration : 0;
    
    [UIView animateWithDuration:interval
                          delay:kDLSAnimationDelay
                        options:0
                     animations:^{
                         squareView.frame = [self pointForSquarePosition:squarePosition];;
                    }
                     completion:^(BOOL finished) {
                         _squarePosition = squarePosition;
                         
                         if (animationCompletion) {
                             animationCompletion();
                         }
                     }];
}

- (void)squareAnimate {
    self.animate = !self.animate;
    [self.animatingSquareButton setTitle:[self changeTitleAnimateButton] forState:UIControlStateNormal];
    [self animate];
    
}

#pragma mark -
#pragma mark Private

- (CGRect)pointForSquarePosition:(DLSSquarePosition)squarePosition {
    CGRect result = self.squareView.frame;
    CGRect superview = self.superview.bounds;
    CGPoint point = CGPointZero;
    
    CGPoint max = CGPointZero;
    max.x = CGRectGetWidth(superview) - CGRectGetWidth(result);
    max.y = CGRectGetHeight(superview) - CGRectGetHeight(result);
    
    switch (squarePosition) {
        case DLSTopRightCornerSquarePosition:
            point.x = max.x;
            break;
            
        case DLSTopLeftCornerSquarePosition:
            point.y = max.y;
            break;
            
        case DLSBottomRightCornerSquarePosition:
            point = max;
            break;
            
        default:
            break;
    }
    
    result.origin = point;
    
    return result;
}

- (NSString *)changeTitleAnimateButton {
    return self.animate ? kDLSAnimateButtonTitleStop : kDLSAnimateButtonTitleStart;
}

- (void)animate {
    if (self.animate) {
        __weak typeof(self) weakSelf = self;
        DLSSquarePosition position = (self.squarePosition + 1) % DLSSquarePositionCount;
        
        [weakSelf setSquarePosition:position
                           animated:YES
                  completionHandler:^{[self animate];}];
    }
}

@end
