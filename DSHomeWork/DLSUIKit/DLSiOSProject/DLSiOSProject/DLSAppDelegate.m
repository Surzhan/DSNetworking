//
//  AppDelegate.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 08.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAppDelegate.h"
#import "DLSUserViewController.h"

@interface DLSAppDelegate ()

@end

@implementation DLSAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UIWindow *window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window = window;
    
    window.rootViewController = [DLSUserViewController new];
    window.backgroundColor = [UIColor whiteColor];
    
    [window makeKeyAndVisible];
    
    window.rootViewController.view.frame = CGRectMake(0, 0, 100, 100);
    
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
