//
//  DSStructuresTest.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 11.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <stddef.h>

#include "DSStructuresTest.h"
#include "DSCreateStructure.h"


#pragma mark -
#pragma Public Declaration

static
void DSStructuresSizeofTest(void);

static
void DSStructuresOffsetofTest(void);

#pragma mark -
#pragma Public Implementations

void DSStructureTests (void) {
    DSStructuresSizeofTest();
    DSStructuresOffsetofTest();

};

#pragma mark -
#pragma Private Implementations

void DSStructuresSizeofTest(void) {
    DSStructureRandom stuctureRandom;
    DSStructureOptimized structuresOptimized;
    
    printf("stuctureRandom %lu\n", sizeof(stuctureRandom));
    printf("stuctureRandom._random15 %lu\n", sizeof(stuctureRandom._random15));
    printf("structuresOptimized %lu\n", sizeof(structuresOptimized));
    
    
};

void DSStructuresOffsetofTest(void) {
    
};
