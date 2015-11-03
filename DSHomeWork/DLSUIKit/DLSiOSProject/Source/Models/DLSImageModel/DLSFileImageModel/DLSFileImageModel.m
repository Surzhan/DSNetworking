//
//  DLSFileImageModel.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSFileImageModel.h"

#import "DLSDispatch.h"

#import "NSFileManager+DLSExtensions.h"

@interface DLSFileImageModel ()

- (void)deleteFromCache;

@end

@implementation DLSFileImageModel

@dynamic filePath;
@dynamic cached;

#pragma mark -
#pragma mark Accessors

- (NSString *)filePath {
    return [self.fileFolder stringByAppendingPathComponent:self.fileName];
}

- (BOOL)isCached {
    return [[NSFileManager defaultManager] fileExistsAtPath:self.filePath];
}

#pragma mark -
#pragma mark Private

- (void)deleteFromCache {
    if (self.cached) {
        NSFileManager *maneger = [NSFileManager defaultManager];
        [maneger removeItemAtPath:self.filePath error:nil];
    }
}

#pragma mark -
#pragma mark DLSImageModel

- (void)performLoadingWithCompletion:(void(^)(UIImage *image, id error))completion {
    UIImage *image = [UIImage imageWithContentsOfFile:self.filePath];
    if (!image) {
        [self deleteFromCache];
    }
    
    completion(image, nil);
}

@end
