//
//  AppDelegate.m
//  Task2_UITableView
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAppDelegate.h"

#import "DLSTableViewController.h"
#import "DLSArrayModel.h"

#import "UIWindow+DLSExtensions.h"
#import "UIViewController+DLSExtensions.h"

@interface DLSAppDelegate ()

@end

@implementation DLSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UIWindow *window = [UIWindow window];
    self.window = window;
    
    DLSTableViewController *controller = [DLSTableViewController controller];
    
    DLSArrayModel *arrayModel = [DLSArrayModel new];
    controller.arrayModel = arrayModel;
    
    window.rootViewController = controller;
    [window makeKeyAndVisible];
    
    return YES;
}

@end
