//
//  DLSUser.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSModel.h"

@class DLSImageModel;

@interface DLSUser : DLSModel <NSCoding>
@property (nonatomic, readonly) NSString        *name;
@property (nonatomic, readonly) DLSImageModel   *imageModel;

@end
