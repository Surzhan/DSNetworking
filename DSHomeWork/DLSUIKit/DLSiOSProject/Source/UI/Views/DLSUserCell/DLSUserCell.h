//
//  DLSUserCell.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSTableViewCell.h"

@class DLSImageView;
@class DLSUser;

@interface DLSUserCell : DLSTableViewCell
@property (nonatomic, strong) IBOutlet DLSImageView             *userImageView;
@property (nonatomic, strong) IBOutlet UILabel                  *nameLabel;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView  *spinnerView;

@property (nonatomic, strong) DLSUser *user;

- (void)fillWithUser:(DLSUser *)user;

@end
