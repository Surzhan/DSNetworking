//
//  DSParentsSelect.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 06.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include "DSParentsSelect.h"

#pragma mark -
#pragma Public Declaration

#define DSTypeOutput(type) \
    printf(#type" size = %lu\n",sizeof(type));

#pragma mark -
#pragma Public Implementations

void DSSyzeOfTypeOutput(void) {
    DSTypeOutput(int);
    DSTypeOutput(float);
    DSTypeOutput(short);
    DSTypeOutput(long);
    DSTypeOutput(long long);
    DSTypeOutput(char);
    DSTypeOutput(double);
    DSTypeOutput(long double);
    
    return;
}
