//
//  UITableView+DLSExtensions.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "UITableView+DLSExtensions.h"

#import "DLSChangesModel.h"
#import "DLSChangesModelOneIndex.h"
#import "DLSChangesModelTwoIndexes.h"

#import "UINib+DLSExtensions.h"
#import "DLSChangeModel+UITableView.h"

@implementation UITableView (DLSExtensions)

- (id)dequeueReusableCellWithClass:(Class)class {
    id cell = [self dequeueReusableCellWithIdentifier:NSStringFromClass(class)];
    
    if (!cell) {
        cell = [UINib objectWithClass:class];
    }
    
    return cell;
}

- (void)updateWithChanges:(DLSChangesModel *)changes {
    [self updateWithChanges:changes rowAnimation:UITableViewRowAnimationAutomatic];
}

- (void)updateWithChanges:(id)changes rowAnimation:(UITableViewRowAnimation)rowAnimation {
    UITableView *tableView = self;
    [tableView beginUpdates];
    
    [changes applyToTableView:tableView rowAnimation:rowAnimation];
    
    [tableView endUpdates];
}

@end
