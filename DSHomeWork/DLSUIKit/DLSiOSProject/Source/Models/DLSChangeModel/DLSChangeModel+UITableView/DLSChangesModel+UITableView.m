//
//  DLSChangeModel+UITableView.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSChangesModel+UITableView.h"

@implementation DLSChangesModel (UITableView)

- (void)applyToTableView:(UITableView *)tableView {
    [self applyToTableView:tableView rowAnimation:UITableViewRowAnimationAutomatic];
}

- (void)applyToTableView:(UITableView *)tableView rowAnimation:(UITableViewRowAnimation)rowAnimation {
    
}

@end

@implementation DLSChangesModelOneIndex (UITableView)

- (void)applyToTableView:(UITableView *)tableView rowAnimation:(UITableViewRowAnimation)rowAnimation {
    NSIndexPath *path = self.indexPath;
    switch (self.state) {
        case DLSChangeModelChangeAdded:
            [tableView insertRowsAtIndexPaths:@[path] withRowAnimation:rowAnimation];
            break;
            
        case DLSChangeModelChangeRemoved:
            [tableView deleteRowsAtIndexPaths:@[path] withRowAnimation:rowAnimation];
            break;
            
        default:
            break;
    }
}

@end

@implementation DLSChangesModelTwoIndexes (UITableView)

- (void)applyToTableView:(UITableView *)tableView rowAnimation:(UITableViewRowAnimation)rowAnimation {
    [tableView moveRowAtIndexPath:self.sourceIndexPath toIndexPath:self.destinationIndexPath];
}

@end
