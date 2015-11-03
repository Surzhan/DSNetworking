//
//  DLSImageView.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "DLSView.h"
#import "DLSImageModel.h"
#import "DLSModelObserver.h"

@interface DLSImageView : UIView <DLSModelObserver>
@property (nonatomic, strong) DLSImageModel                     *userImageModel;
@property (nonatomic, strong) IBOutlet UIImageView              *imageView;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView  *activityIndicatorImageView;

- (void)fillWithModel:(DLSImageModel *)model;

@end
