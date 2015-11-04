//
//  DLSTableViewController.h
//  Task1_Square
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "DLSUserArrayModel.h"
#import "DLSModelObserver.h"

@interface DLSTableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, DLSModelObserver>
@property (nonatomic, strong)   DLSArrayModel   *arrayModel;

- (IBAction)onEditButton:(id)sender;
- (IBAction)onAddButton:(id)sender;

@end
