//
//  DLSURLImageModel.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSURLImageModel.h"

#import "NSFileManager+DLSExtensions.h"

#import "DLSMacros.h"

@interface DLSURLImageModel ()
@property (nonatomic, strong)   NSURLSession              *session;
@property (nonatomic, strong)   NSURLSessionDownloadTask  *downloadTask;

- (void)downloadImageFromInternet:(void (^)(UIImage *image, id error))complation;

@end

@implementation DLSURLImageModel

#pragma mark -
#pragma mark Initialization and Dealocation

- (void)dealloc {
    [self cancel];
}

#pragma mark -
#pragma mark Accessors

- (NSURLSession *)session {
    static NSURLSession *__session = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^ {
        NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration ephemeralSessionConfiguration];
        __session = [NSURLSession sessionWithConfiguration:configuration];
    });
    
    return __session;
}

- (void)setDownloadTask:(NSURLSessionDownloadTask *)downloadTask {
    if (_downloadTask != downloadTask) {
        [_downloadTask cancel];
        
        _downloadTask = downloadTask;
        [_downloadTask resume];
    }
}

#pragma mark -
#pragma mark Private

- (void)downloadImageFromInternet:(void (^)(UIImage *image, id error))complation {
    DLSWeakify(self);
    id block = ^(NSURL *location, NSURLResponse *response, NSError *error) {
        
        DLSStrongifyAndReturnIfNil(self);
        if (!error) {
            [[NSFileManager defaultManager] copyItemAtURL:location
                                                    toURL:[NSURL fileURLWithPath:self.filePath]
                                                    error:nil];
        }
    };
    
    self.downloadTask = [self.session downloadTaskWithURL:self.url completionHandler:block];
}

- (void)imageLocation {
    
}

#pragma mark -
#pragma mark DLSImageModel

- (void)cancel {
    [super cansel];
    
    self.downloadTask = nil;
}

- (void)performLoadingWithCompletion:(void (^)(UIImage *image, id))completion {
    if (self.cached) {
        [super performLoadingWithCompletion:completion];
    } else {
        [self downloadImageFromInternet:completion];
    }
}

@end
