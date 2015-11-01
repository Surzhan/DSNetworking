//
//  NSFileManager+DLSExtensions.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 01.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "NSFileManager+DLSExtensions.h"

@implementation NSFileManager (DLSExtensions)

#pragma mark -
#pragma mark Class Methods

+ (NSString *)documentsPath {
    return [self userPathWithSearchPath:NSDocumentDirectory];
}

+ (NSString *)userPathWithSearchPath:(NSSearchPathDirectory)directory {
    return [NSSearchPathForDirectoriesInDomains(directory, NSUserDomainMask, YES) firstObject];
}

@end
