//
//  DLSUserArrayModel.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "DLSUserArrayModel.h"

#import "DLSUser.h"

#import "DLSDispatch.h"
#import "NSFileManager+DLSExtensions.h"

#import "DLSMacros.h"

static NSString * const kDLSFileName = @"temp.plist";
static const NSUInteger kDLSDefaultSleepTimeInterval = 3;

@interface DLSUserArrayModel ()

- (void)saveWithNotification:(id)notification;
- (void)fillWithModels:(NSUInteger)count;
- (void)subscribeNotifications:(NSArray *)notificationNames;
- (void)unsubcribeNotifications:(NSArray *)notificationNames;

@end

@implementation DLSUserArrayModel

@dynamic notificationNames;
@dynamic fileName;
@dynamic fileFolder;
@dynamic filePath;
@dynamic cached;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self unsubcribeNotifications:self.notificationNames];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self subscribeNotifications:self.notificationNames];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)notificationNames {
    return @[UIApplicationWillResignActiveNotification, UIApplicationWillTerminateNotification];
}

- (NSString *)filePath {
    return [self.fileFolder stringByAppendingPathComponent:self.fileName];
}

- (NSString *)fileName {
    return kDLSFileName;
}

- (NSString *)fileFolder {
    return [NSFileManager documentsPath];
}

- (BOOL)isCached {
    return [[NSFileManager defaultManager] fileExistsAtPath:self.filePath];
}

#pragma mark -
#pragma mark Public

- (void)save {
    [NSKeyedArchiver archiveRootObject:self.models toFile:self.filePath];
}

#pragma mark -
#pragma mark Private

- (void)saveWithNotification:(id)notification {
    [self save];
}

- (void)fillWithModels:(NSUInteger)count {
    for (NSUInteger index = 0; index < count; index++) {
        [self addObject:[DLSUser new]];
    }
}

- (void)subscribeNotifications:(NSArray *)notificationNames {
    for (id notification in notificationNames) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(saveWithNotification:)
                                                     name:notification
                                                   object:nil];
    }
}

- (void)unsubcribeNotifications:(NSArray *)notificationNames {
    for (id notice in notificationNames) {
        [[NSNotificationCenter defaultCenter] removeObserver:self name:notice object:nil];
    }
}

#pragma mark -
#pragma mark DLSModel

- (void)performLoading {
    id block = nil;
    if (self.cached) {
        id models = [NSKeyedUnarchiver unarchiveObjectWithFile:self.filePath];
        DLSSleep(kDLSDefaultSleepTimeInterval);
        
        block = ^{ for (id model in models) { [self addObject:model]; }};
    } else {
        block = ^{ [self fillWithModels:self.models.count]; };
    }
    
    [self performBlockWithoutNotification:block];
    
    DLSDispatchAsyncOnMainThread(^{
        self.state = DLSModelDidLoad;
    });
}

@end
