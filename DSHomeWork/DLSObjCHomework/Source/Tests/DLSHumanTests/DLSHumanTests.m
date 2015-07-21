//
//  DLSHumanTests.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 07.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSHumanTests.h"
#import "DLSHuman.h"
#import "DLSMaleHuman.h"
#import "DLSFemaleHuman.h"

@implementation DLSHumanTests

+ (void)testDLSHuman {
    NSMutableArray *creatures = [NSMutableArray arrayWithCapacity:10];
    for (NSUInteger i = 0; i < 10; ++i) {
        DLSHumanGender gender = (arc4random() % 2) + 1;
        DLSHuman *newHuman = [[[DLSHuman alloc] initWithGender:gender] autorelease];
        DLSHuman *child = [newHuman performGenderSpecificOperation];
    
        if (child != nil) {
            [newHuman addChild:child];
        }
        
        [creatures addObject:newHuman];
    }

    assert(10 == creatures.count);
    
    for (DLSHuman *creature in creatures) {
        [creature performGenderSpecificOperation];
    }
}

@end
