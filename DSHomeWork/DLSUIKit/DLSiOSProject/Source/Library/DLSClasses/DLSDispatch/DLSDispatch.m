//
//  DLSDispatch.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 01.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSDispatch.h"

void DLSDispatchSyncOnMainThread(void(^block)(void)) {
    if (!block) {
        return;
    }
    
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
}

void DLSDispatchAsyncOnMainThread(void(^block)(void)) {
    if (!block) {
        return;
    }
    
    dispatch_async(dispatch_get_main_queue(), block);
}

void DLSDispatchAsyncOnBackgroundThread(void(^block)(void)) {
    if (!block) {
        return;
    }
    
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0), block);
}
