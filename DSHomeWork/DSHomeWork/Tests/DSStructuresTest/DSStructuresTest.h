//
//  DSStructuresTest.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 11.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSStructuresTest__
#define __DSHomeWork__DSStructuresTest__

#include <stdio.h>

#define performTest(testName) \
printf(#testName " started...\n\n"); \
testName(); \
printf("\n..."#testName " finished\n");

extern
void DSStructureTests (void);

#endif /* defined(__DSHomeWork__DSStructuresTest__) */
