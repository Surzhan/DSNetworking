//
//  DLSChangeModel+UITableView.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "DLSChangesModel.h"

#import "DLSChangesModelOneIndex.h"
#import "DLSChangesModelTwoIndexes.h"

@interface DLSChangesModel (UITableView)

- (void)applyToTableView:(UITableView *)tableView;
- (void)applyToTableView:(UITableView *)tableView rowAnimation:(UITableViewRowAnimation)rowAnimation;

@end
