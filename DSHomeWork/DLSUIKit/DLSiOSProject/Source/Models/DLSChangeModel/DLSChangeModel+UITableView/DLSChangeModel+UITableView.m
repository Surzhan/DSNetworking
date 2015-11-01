//
//  DLSChangeModel+UITableView.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSChangeModel+UITableView.h"

@implementation DLSChangeModel (UITableView)

- (void)applyToTableView:(UITableView *)tableView {
    [self applyToTableView:tableView rowAnimation:UITableViewRowAnimationAutomatic];
}

- (void)applyToTableView:(UITableView *)tableView rowAnimation:(UITableViewRowAnimation)rowAnimation {
    
}

@end

@implementation DLSChangesModelOneIndex (UITableView)

- (void)applyToTableView:(UITableView *)tableView rowAnimation:(UITableViewRowAnimation)rowAnimation {
    switch (self.state) {
        case DLSModelChangeAdded:
            [tableView insertRowsAtIndexPaths:@[self.indexPath] withRowAnimation:rowAnimation];
            break;
            
        case DLSModelChangeRemoved:
            [tableView deleteRowsAtIndexPaths:@[self.indexPath] withRowAnimation:rowAnimation];
            break;
            
        default:
            break;
    }
}

@end

@implementation DLSChangesModelTwoIndexes (UITableView)

- (void)applyToTableView:(UITableView *)tableView rowAnimation:(UITableViewRowAnimation)rowAnimation {
    [tableView moveRowAtIndexPath:self.fromIndexPath toIndexPath:self.toIndexPath];
}

@end
