//
//  DLSImageView.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSImageView.h"

#import "DLSMacros.h"

@implementation DLSImageView

#pragma mark -
#pragma mark Initialization and Dealocaton

- (void)dealloc {
    self.userImageModel = nil;
}

#pragma mark -
#pragma mark Accessors

- (void)setUserImageModel:(DLSImageModel *)userImageModel {
    DLSSynthesizeObservingSetter(userImageModel);
    
    [self fillWithModel:userImageModel];
    [userImageModel load];
}

#pragma mark -
#pragma mark Public

- (void)fillWithModel:(DLSImageModel *)model {
    self.imageView.image = model.image;
}

#pragma mark -
#pragma mark DLSModelObserver

- (void)modelWillLoad:(DLSImageModel *)model {
    [self.activityIndicatorImageView startAnimating];
}

- (void)modelDidLoad:(DLSImageModel *)model {
    [self fillWithModel:model];
    [self.activityIndicatorImageView stopAnimating];
}

- (void)modelDidFailLoading:(DLSImageModel *)model {
    [self.userImageModel load];
}

@end
