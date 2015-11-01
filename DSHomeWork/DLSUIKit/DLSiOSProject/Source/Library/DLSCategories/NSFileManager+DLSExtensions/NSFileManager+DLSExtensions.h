//
//  NSFileManager+DLSExtensions.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 01.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (DLSExtensions)

+ (NSString *)documentsPath;
+ (NSString *)userPathWithSearchPath:(NSSearchPathDirectory)directory;

@end
