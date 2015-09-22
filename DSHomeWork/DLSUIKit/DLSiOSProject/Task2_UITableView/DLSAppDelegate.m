//
//  AppDelegate.m
//  Task2_UITableView
//
//  Created by Denis Surzhan on 21.09.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAppDelegate.h"

#import "DLSArrayModel.h"
#import "DLSTableViewController.h"

#import "UIWindow+DLSExtensions.h"
#import "UIViewController+DLSExtentions.h"

@interface DLSAppDelegate ()

@end

@implementation DLSAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UIWindow *window = [UIWindow window];
    self.window = window;
    
    DLSTableViewController *controller = [DLSTableViewController controller];
    
    DLSArrayModel *users = [DLSArrayModel new];
    controller.arrayModel = arrayModel;
    
    window.rootViewController = controller;
    [window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
}

- (void)applicationWillTerminate:(UIApplication *)application {
}

@end
