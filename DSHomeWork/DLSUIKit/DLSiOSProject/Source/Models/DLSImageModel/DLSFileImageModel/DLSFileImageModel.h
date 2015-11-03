//
//  DLSFileImageModel.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSImageModel.h"

@interface DLSFileImageModel : DLSImageModel
@property (nonatomic, readonly) NSString    *filePath;
@property (nonatomic, readonly) NSString    *fileName;
@property (nonatomic, readonly) NSString    *fileFolder;

@property (nonatomic, readonly, getter=isCached)    BOOL    cached;

@end
