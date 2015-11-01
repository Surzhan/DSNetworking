//
//  DLSDispatch.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 01.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

void DLSDispatchSyncOnMainThread(void(^block)(void));

void DLSDispatchAsyncOnMainThread(void(^block)(void));

void DLSDispatchAsyncOnBackgroundThread(void(^block)(void));
