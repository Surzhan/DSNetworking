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

#define DSPrintStructuresOffsetof(structName, val) \
printf("Offsetof "#structName " position of " #val " is: %lu\n", offsetof(structName, val))


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
    DSStructureOptimize structureOptimized;
    DSStructureOptimizedWithUnion structureOptimizedWithUnion;
    
    printf("stuctureRandom %lu\n", sizeof(stuctureRandom));
    printf("stuctureOptimized %lu\n", sizeof(structureOptimized));
    printf("structureOptimizedWithUnion %lu\n", sizeof(structureOptimizedWithUnion));
    
};

void DSStructuresOffsetofTest(void) {
    printf("\nPrint Offsetof Structure\n\n");
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _double1);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _longlong1);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _char1);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _int1);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _float1);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _short1);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _short2);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _short3);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _bool1);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _bool2);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _bool3);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _bool4);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _bool5);
    DSPrintStructuresOffsetof(struct DSStructureOptimize, _bool6);
    
};
