//
//  DLSCache.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 03.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSCache.h"

@interface DLSCache ()
@property (nonatomic, strong) NSMapTable *mapTable;

@end

@implementation DLSCache

#pragma mark -
#pragma mark Class Method

+ (DLSCache *)cache {
    static DLSCache *__cache = nil;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        __cache = [[self alloc] init];
    });
    
    return __cache;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mapTable = [NSMapTable strongToWeakObjectsMapTable];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (id)objectForKey:(id)aKey {
    @synchronized(self) {
        return [self.mapTable objectForKey:aKey];
    }
}

- (void)addObject:(id)anObject forKey:(id)aKey {
    @synchronized(self) {
        [self.mapTable setObject:anObject forKey:aKey];
    }
}

- (void)removeObjectForKey:(id)aKey {
    @synchronized(self) {
        [self.mapTable removeObjectForKey:aKey];
    }
}

- (void)removeAllObject {
    @synchronized(self) {
        [self.mapTable removeAllObjects];
    }
}

@end
