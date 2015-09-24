//
//  DLSViewSquare.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 09.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSSquareHolderView.h"

#import "DLSMacros.h"

static const NSTimeInterval kDLSAnimationDuration   = 1;
static const NSTimeInterval kDLSAnimationDelay      = 0;

static NSString * const kDLSAnimateButtonTitleStart   = @"START";
static NSString * const kDLSAnimateButtonTitleStop    = @"STOP";

@interface DLSSquareHolderView ()
@property (nonatomic, assign, getter=isAnimationProgress)  BOOL  animationProgress;

- (CGRect)pointForSquarePosition:(DLSSquarePosition)squarePosition;
- (void)changeButtonTitle;
- (DLSSquarePosition)nextPosition;
- (void)animateSquare;

@end

@implementation DLSSquareHolderView

#pragma mark -
#pragma mark Accessors

- (void)setSquareAnimating:(BOOL)squareAnimating {
    if (_squareAnimating != squareAnimating) {
        _squareAnimating = squareAnimating;
        
        [self animateSquare];
    }
}

- (void)setAnimationProgress:(BOOL)animationProgress {
    if (_animationProgress != animationProgress) {
        _animationProgress = animationProgress;
        
        [self changeButtonTitle];
    }
}

#pragma mark -
#pragma mark Public

- (void)setSquarePosition:(DLSSquarePosition)squarePosition
                 animated:(BOOL)animation
{
  [self setSquarePosition:squarePosition animated:animation completionHandler:nil];
}

- (void)setSquarePosition:(DLSSquarePosition)squarePosition
                 animated:(BOOL)animation
        completionHandler:(void(^)(BOOL finished))handler
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
                         
                         if (handler) {
                             handler(finished);
                         }
                     }];
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

- (void)changeButtonTitle {
    NSString *buttonTitle = self.animationProgress ? kDLSAnimateButtonTitleStop : kDLSAnimateButtonTitleStart;
    
    [self.animatingSquareButton setTitle:buttonTitle
                        forState:UIControlStateNormal];
}

- (DLSSquarePosition)nextPosition {
    return (self.squarePosition + 1) % DLSSquarePositionCount;
}

- (void)animateSquare {
    if (self.squareAnimating && !self.animationProgress) {
        DLSSquarePosition position = [self nextPosition];
        self.animationProgress = YES;
        DLSWeakify(self);
        [self setSquarePosition:position
                       animated:YES
              completionHandler:^(BOOL finished) {
                  DLSStrongifyAndReturnIfNil(self);
                  if (finished) {
                      self.animationProgress = NO;
                      [self animateSquare];
                  }
              }];
    }
}

@end
