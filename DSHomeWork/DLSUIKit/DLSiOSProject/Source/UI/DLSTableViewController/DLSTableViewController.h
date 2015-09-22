//
//  DLSTableViewController.h
//  Task1_Square
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <UIKit/UIKit.h>

@ class DLSArrayModel;

@interface DLSTableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong)   DLSArrayModel   *arrayModel;

@end
