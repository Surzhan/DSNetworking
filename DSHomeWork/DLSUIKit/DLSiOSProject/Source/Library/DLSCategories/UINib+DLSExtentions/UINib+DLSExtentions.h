//
//  UINib+DLSExtentions.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 24.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINib (DLSExtentions)

+ (id)objectWithClass:(Class)cls;
+ (id)objectWithClass:(Class)cls withOwner:(id)owner;

+ (id)objectWithClass:(Class)cls inBundle:(NSBundle *)bundle;
+ (id)objectWithClass:(Class)cls withOwner:(id)owner inBundle:(NSBundle *)bundle;

+ (UINib *)nibWithClass:(Class)cls;
+ (UINib *)nibWithClass:(Class)cls bundle:(NSBundle *)bundle;

- (id)objectWithClass:(Class)cls;
- (id)objectWithClass:(Class)cls withOwner:(id)owner;

@end
