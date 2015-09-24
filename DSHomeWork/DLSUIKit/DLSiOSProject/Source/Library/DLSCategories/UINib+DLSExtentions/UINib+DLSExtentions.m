//
//  UINib+DLSExtentions.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 24.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "UINib+DLSExtentions.h"

@implementation UINib (DLSExtentions)

#pragma mark -
#pragma mark Class Methods

+ (id)objectWithClass:(Class)cls {
    return [self objectWithClass:cls inBundle:nil];
}

+ (id)objectWithClass:(Class)cls withOwner:(id)owner {
    return [self objectWithClass:cls withOwner:nil];
}

+ (id)objectWithClass:(Class)cls inBundle:(NSBundle *)bundle {
    return [self objectWithClass:cls withOwner:nil inBundle:bundle];
}

+ (id)objectWithClass:(Class)cls withOwner:(id)owner inBundle:(NSBundle *)bundle {
    UINib *nib = [self nibWithClass:cls bundle:bundle];
    
    return [nib objectWithClass:cls withOwner:owner];
}

+ (UINib *)nibWithClass:(Class)cls {
    return [UINib nibWithClass:cls bundle:nil];
}

+ (UINib *)nibWithClass:(Class)cls bundle:(NSBundle *)bundle {
    return [UINib nibWithNibName:NSStringFromClass(cls)
                          bundle:bundle];
}

#pragma mark -
#pragma mark Public

- (id)objectWithClass:(Class)cls {
    return [self objectWithClass:cls withOwner:nil];
}

- (id)objectWithClass:(Class)cls withOwner:(id)owner {
    NSArray *array = [self instantiateWithOwner:owner options:nil];
    for (id object in array) {
        if ([object isMemberOfClass:cls]) {
            return object;
        }
    }
    
    return nil;
}
@end
