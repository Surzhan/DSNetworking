//
//  UITableView+DLSExtensions.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DLSChangesModel;

@interface UITableView (DLSExtensions)

- (id)dequeueReusableCellWithClass:(Class)cls;
- (void)updateWithChanges:(DLSChangesModel *)changes;
- (void)updateWithChanges:(DLSChangesModel *)changes rowAnimation:(UITableViewRowAnimation)rowAnimation;

@end
