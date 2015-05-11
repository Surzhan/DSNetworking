//
//  main.c
//  DSHomeWork3
//
//  Created by Denis Surzhan on 10.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <stdio.h>

#include "DSCreateStructure.h"
#include "DSStructuresTest.h"

#define performTest(testName) \
    printf(#testName " started...\n\n"); \
    testName(); \
    printf("\n..."#testName " finished\n");


int main(int argc, const char * argv[]) {
    performTest (DSStructureTests);
    
    return 0;
}
