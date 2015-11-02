//
//  DLSTableViewController.m
//  Task1_Square
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSTableViewController.h"

#import "DLSUser.h"
#import "DLSUserCell.h"
#import "DLSUsersView.h"
#import "DLSTableViewCell.h"
#import "DLSChangesModel.h"

#import "NSIndexPath+DLSExtensions.h"
#import "UITableView+DLSExtensions.h"

#import "DLSMacros.h"

DLSViewControllerBaseViewProperty(DLSTableViewController, usersView, DLSUsersView)

@implementation DLSTableViewController

#pragma mark -
#pragma mark Initialization and Deallocations

- (void)dealloc {
    self.arrayModel = nil;
}

#pragma mark -
#pragma mark Accessors

- (void)setArrayModel:(DLSUserArrayModel *)arrayModel {
    DLSSynthesizeObservingSetterAndLoad(arrayModel);
}

#pragma mark -
#pragma mark View Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.arrayModel load];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

#pragma mark -
#pragma mark Public

- (void)onEditButton:(id)sender {
    DLSUsersView *usersView = self.usersView;
    usersView.editing = (self.arrayModel.count > 0) ? !usersView.editing : NO;
}

- (IBAction)onAddButton:(id)sender {
    [self.arrayModel addObject:[DLSUser new]];
}

#pragma mark -
#pragma mark UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.arrayModel.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    DLSUserCell *cell = [tableView dequeueReusableCellWithClass:[DLSUserCell class]];
    cell.user = self.arrayModel[indexPath.row];
    
    return cell;
}

- (void)     tableView:(UITableView *)tableView
    commitEditingStyle:(UITableViewCellEditingStyle)editingStyle
     forRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self.arrayModel removeObjectAtIndex:indexPath.row];
}

- (void)    tableView:(UITableView *)tableView
   moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath
          toIndexPath:(NSIndexPath *)destinationIndexPath
{
    [self.arrayModel moveObjectFromIndex:sourceIndexPath.row
                               toAtIndex:destinationIndexPath.row];
}

#pragma mark -
#pragma mark DLSModelObserver

- (void)modelWillLoad:(DLSArrayModel *)model {
    [self.usersView showLoadingView];
}

- (void)modelDidLoad:(DLSArrayModel *)model {
    DLSUsersView *usersView = self.usersView;
    [usersView.tableView reloadData];
    [usersView hideLoadingView];
}

- (void)model:(DLSArrayModel *)object didChangeWithModel:(DLSChangesModel *)model {
    [self.usersView.tableView updateWithChanges:model];
}

@end
