//
//  DLSUsersView.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSUsersView.h"

#import "DLSLoadingView.h"

static NSString * const kDLSButtonTitleEdit = @"Edit";
static NSString * const kDLSButtonTitleDone = @"Done";

@interface DLSUsersView ()
@property (nonatomic, strong)   DLSLoadingView   *loadingView;

- (void)changeButtonTitleForEditing:(BOOL)editing;

@end

@implementation DLSUsersView

#pragma mark -
#pragma mark Accessors

- (void)setEditing:(BOOL)editing {
    [self.tableView setEditing:editing animated:YES];
    
    [self changeButtonTitleForEditing:editing];
}

- (BOOL)isEditing {
    return self.tableView.editing;
}

#pragma mark -
#pragma mark Private

- (void)changeButtonTitleForEditing:(BOOL)editing {
    NSString *buttonTitle = editing ? kDLSButtonTitleDone : kDLSButtonTitleEdit;
    
    [self.editButton setTitle:buttonTitle
                     forState:UIControlStateNormal];
}

@end
