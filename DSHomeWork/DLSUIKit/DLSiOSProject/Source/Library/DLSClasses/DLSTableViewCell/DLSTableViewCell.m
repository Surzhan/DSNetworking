//
//  DLSTableViewCell.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSTableViewCell.h"

@implementation DLSTableViewCell

#pragma mark -
#pragma mark Accessors

- (NSString *)reuseIdentifier {
    return NSStringFromClass([self class]);
}

@end
