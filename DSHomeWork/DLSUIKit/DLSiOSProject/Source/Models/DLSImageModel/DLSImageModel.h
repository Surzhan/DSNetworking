//
//  DLSImageModel.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//
#import <UIKit/UIKit.h>

#import "DLSModel.h"

@interface DLSImageModel : DLSModel
@property (nonatomic, readonly) UIImage *image;
@property (nonatomic, readonly) NSURL   *url;

+ (instancetype)imageModelWithURL:(NSURL *)url;
+ (instancetype)imageWithURL:(NSURL *)url;

- (void)save;
- (void)cansel;

- (void)performLoadingWithCompletion:(void(^)(UIImage *image, id error))completion;
- (void)finalizeLoadingWithImage:(UIImage *)image error:(id)error;
- (void)notifyOfLoadingStateWithImage:(UIImage *)image error:(id)error;



@end
