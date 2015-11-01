//
//  DLSModel.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSModel.h"

#import "DLSDispatch.h"

#import "DLSModelObserver.h"

#include "DLSMacros.h"

@implementation DLSModel

#pragma mark -
#pragma mark Public

- (void)load {
    @synchronized(self) {
        NSUInteger state = self.state;
        
        if (DLSModelDidLoad == state || DLSModelWillLoad == state) {
            [self notifyObservers];
            
            return;
        }
        
        self.state = DLSModelWillLoad;
    }
    
    [self setupLoading];
    
    DLSWeakify(self);
    DLSDispatchAsyncOnBackgroundThread(^{
        DLSStrongifyAndReturnIfNil(self);
        [self performLoading];
    });
}

- (void)setupLoading {
    
}

- (void)performLoading {
    [self doesNotRecognizeSelector:_cmd];
}

#pragma mark -
#pragma mark DLSObservableObject

- (SEL)selectorForState:(NSUInteger)state {
    SEL selector = NULL;
    
    switch (state) {
        case DLSModelWillLoad:
            selector = @selector(modelWillLoad:);
            break;
            
        case DLSModelDidFailLoading:
            selector = @selector(modelDidFailLoading:);
            break;
            
        case DLSModelDidLoad:
            selector = @selector(modelDidLoad:);
            break;
            
        case DLSModelDidChange:
            selector = @selector(model:didChangeWithObject:);
            break;
            
        default:
            selector = [super selectorForState:state];
            break;
    }
    
    return selector;
}

@end
