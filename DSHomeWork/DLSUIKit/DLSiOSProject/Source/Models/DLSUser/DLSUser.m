//
//  DLSUser.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSUser.h"

#import "DLSImageModel.h"

#import "NSString+DLSExtensions.h"

static NSString * const kDLSNameOfKey   = @"name";
static NSString * const kDLSImageURL    = @"http://img4.wikia.nocookie.net/__cb20130920142351/simpsons/images/e/e9/Pic_1187696292_8.jpg";

@interface DLSUser ()
@property (nonatomic, strong)   NSString        *name;
@property (nonatomic, strong)   DLSImageModel   *imageModel;

@end

@implementation DLSUser

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.name = [NSString randomName];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (DLSImageModel *)imageModel {
    return [DLSImageModel imageWithURL:[NSURL URLWithString:kDLSImageURL]];
}

#pragma mark -
#pragma mark NSCoding

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeObject:self.name forKey:kDLSNameOfKey];
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [super init];
    if (self) {
        self.name = [aDecoder decodeObjectForKey:kDLSNameOfKey];
    }
    
    return self;
}

@end
