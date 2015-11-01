//
//  DLSModel.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 29.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSObservableObject.h"

typedef NS_ENUM(NSUInteger, DLSModelState) {
    DLSModelNotLoaded,
    DLSModelDidFailLoading,
    DLSModelWillLoad,
    DLSModelDidLoad,
    DLSModelDidChange
};

@interface DLSModel : DLSObservableObject

- (void)load;
- (void)setupLoading;
- (void)performLoading;

@end
