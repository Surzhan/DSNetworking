//
//  DLSUserArrayModel.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSArrayModel.h"

@interface DLSUserArrayModel : DLSArrayModel
@property (nonatomic, readonly) NSArray     *notificationNames;
@property (nonatomic, readonly) NSString    *filePath;
@property (nonatomic, readonly) NSString    *fileName;
@property (nonatomic, readonly) NSString    *fileFolder;

@property (nonatomic, readonly, getter=isCached)    BOOL    cached;

- (void)save;

@end
