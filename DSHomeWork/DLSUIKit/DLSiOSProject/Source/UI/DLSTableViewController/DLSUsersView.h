//
//  DLSUsersView.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 02.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSView.h"

@interface DLSUsersView : DLSView
@property (nonatomic, strong)   IBOutlet    UITableView     *tableView;
@property (nonatomic, strong)   IBOutlet    UIButton        *addButton;
@property (nonatomic, strong)   IBOutlet    UIButton        *editButton;

@property (nonatomic, assign, getter=isEditing)   BOOL    editing;

@end
