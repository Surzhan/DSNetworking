//
//  DLSViewSquare.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 09.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSHolderViewSquare.h"

@interface DLSHolderViewSquare ()

- (CGRect)pointForSquarePosition:(DLSSquarePosition)squarePosition;

@end

@implementation DLSHolderViewSquare

#pragma mark -
#pragma mark Public

- (void)setSquarePosition:(DLSSquarePosition)squarePosition {
    [self setSquarePosition:squarePosition animated:NO];
}

- (void)setSquarePosition:(DLSSquarePosition)squarePosition
                 animated:(BOOL)animation
{
  [self setSquarePosition:squarePosition animated:NO completionHandler:nil];
}

- (void)setSquarePosition:(DLSSquarePosition)squarePosition
                 animated:(BOOL)animation
        completionHandler:(void(^)(void))animationCompletion
{
    
}

#pragma mark -
#pragma mark Private

//- (CGRect)pointForSquarePosition:(DLSSquarePosition)squarePosition {
//    
//    
//    return result;
//}

@end
