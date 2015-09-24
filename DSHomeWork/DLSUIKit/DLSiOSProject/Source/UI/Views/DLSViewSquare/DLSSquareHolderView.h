//
//  DLSViewSquare.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 09.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM (NSUInteger, DLSSquarePosition) {
    DLSTopLeftCornerSquarePosition,
    DLSTopRightCornerSquarePosition,
    DLSBottomLeftCornerSquarePosition,
    DLSBottomRightCornerSquarePosition,
    DLSSquarePositionCount
};

@interface DLSSquareHolderView : UIView
@property (nonatomic, strong)   IBOutlet                UIView      *squareView;
@property (nonatomic, strong)   IBOutlet                UIButton    *animatingSquareButton;
@property (nonatomic, assign, getter=isSquareAnimating) BOOL        squareAnimating;

@property (nonatomic, assign)   DLSSquarePosition               squarePosition;

- (void)setSquarePosition:(DLSSquarePosition)squarePosition
                 animated:(BOOL)animation;
- (void)setSquarePosition:(DLSSquarePosition)squarePosition
                 animated:(BOOL)animation
        completionHandler:(void(^)(BOOL finished))handler;

@end
