//
//  DLSUserCell.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSUserCell.h"

#import "DLSUser.h"
#import "DLSImageModel.h"

@implementation DLSUserCell

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.user = nil;
}

#pragma mark -
#pragma mark Accessors

- (void)setUser:(DLSUser *)user {
    if (_user != user) {
        _user = user;
    }
    
    [self fillWithUser:user];
}

#pragma mark -
#pragma mark Public

- (void)fillWithUser:(DLSUser *)user {
    self.nameLabel.text = user.name;
    self.userImageView.userImageModel = user.imageModel;
}

@end
