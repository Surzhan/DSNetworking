//
//  DLSViewSquare.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 09.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM (NSUInteger, DLSSquarePosition) {
    DLSTopLeftCorner,
    DLSTopRightCorner,
    DLSBottomLeftCorner,
    DLSBottomRightCorner
};

@interface DLSViewSquare : UIView
@property (nonatomic, strong)   IBOutlet    UIView      *squareView;
@property (nonatomic, unsafe_unretained)    DLSSquarePosition   squarePosition;

@end
