//
//  AppDelegate.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 08.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAppDelegate.h"
#import "DLSSquareViewController.h"

#import "UIWindow+DLSExtensions.h"
#import "NSObject+DLSExtensions.h"
#import "UIViewController+DLSExtentions.h"

@interface DLSAppDelegate ()

@end

@implementation DLSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UIWindow *window = [UIWindow window];
    self.window = window;
    
    window.rootViewController = [DLSSquareViewController  controller];
    window.backgroundColor = [UIColor whiteColor];
    
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
