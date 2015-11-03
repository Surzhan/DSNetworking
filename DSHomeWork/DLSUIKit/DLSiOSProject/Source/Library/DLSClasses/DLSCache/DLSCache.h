//
//  DLSCache.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 03.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLSCache : NSObject

+ (DLSCache *)cache;

- (id)objectForKey:(id)aKey;

- (void)addObject:(id)anObject forKey:(id)aKey;
- (void)removeObjectForKey:(id)aKey;
- (void)removeAllObject;

@end
