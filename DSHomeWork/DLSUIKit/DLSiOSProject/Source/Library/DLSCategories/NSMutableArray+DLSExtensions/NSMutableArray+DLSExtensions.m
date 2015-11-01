//
//  NSMutableArray+DLSExtensions.m
//  DLSiOSProject
//
//  Created by Denis Surzhan on 01.11.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "NSMutableArray+DLSExtensions.h"

@implementation NSMutableArray (DLSExtensions)

- (void)moveObjectAtIndex:(NSUInteger)indexOne toIndex:(NSUInteger)indexTwo {
    id object = [self objectAtIndex:indexOne];
    
    [self removeObjectAtIndex:indexOne];
    [self insertObject:object atIndex:indexTwo];
}

@end
