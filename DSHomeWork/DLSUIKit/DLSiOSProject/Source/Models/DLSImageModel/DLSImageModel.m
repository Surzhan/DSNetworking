//
//  DLSImageModel.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSImageModel.h"

#import "DLSFileImageModel.h"
#import "DLSURLImageModel.h"
#import "DLSCache.h"

#import "DLSDispatch.h"

#import "DLSMacros.h"

static const NSUInteger kDLSDefaultSleepTimeInterval = 3;

@interface DLSImageModel ()
@property (nonatomic, strong)   UIImage *image;
@property (nonatomic, strong)   NSURL   *url;

@end

@implementation DLSImageModel

#pragma mark -
#pragma mark Class Method

+ (instancetype)imageWithURL:(NSURL *)url {
    BOOL isFileClass = url.fileURL;
    if (isFileClass) {
        [DLSFileImageModel class];
    } else {
        [DLSURLImageModel class];
    }
    
    return [[self alloc] initWithURL:url];
}

+ (DLSCache *)sharedCache {
    return [DLSCache cache];
}

#pragma mark -
#pragma mark Initalization and Deallocations

- (void)dealloc {
    self.url = nil;
}

- (instancetype)initWithURL:(NSURL *)url {
    if (!url) {
        return nil;
    }
    
    DLSCache *imageCache = [DLSImageModel sharedCache];
    
    @synchronized(imageCache) {
        id userImageModel = [imageCache objectForKey:url];
        if (userImageModel) {
            return userImageModel;
            
        }
        self = [super init];
        
        if (self) {
            self.url = url;
            [imageCache addObject:self forKey:url];
        }
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (void)performLoadingWithCompletion:(void(^)(UIImage *image, id error))completion {
    
}

- (void)notifyOfLoadingStateWithImage:(UIImage *)image error:(id)error {
    DLSWeakify(self);
    DLSDispatchAsyncOnMainThread(^{
        DLSStrongifyAndReturnIfNil(self);
        self.state = self.image ? DLSModelDidLoad : DLSModelDidFailLoading;
    });
}

- (void)finalizeLoadingWithImage:(UIImage *)image error:(id)error {
    self.image = image;
}

- (void)save {
    
}

- (void)cancel {
    
}

#pragma mark -
#pragma mark DLSModel

- (void)performLoading {
    DLSWeakify(self);
    [self performLoadingWithCompletion:^(UIImage *image, id error) {
        DLSSleep(kDLSDefaultSleepTimeInterval);
        
        DLSStrongifyAndReturnIfNil(self);
        [self finalizeLoadingWithImage:image error:error];
        [self notifyOfLoadingStateWithImage:image error:error];
    }];
}

@end
