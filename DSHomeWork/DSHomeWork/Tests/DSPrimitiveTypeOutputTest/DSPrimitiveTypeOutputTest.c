//
//  DSPrimitiveTypeOutputTest.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 10.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include "DSPrimitiveTypeOutput.h"
#include "DSPrimitiveTypeOutputTest.h"

DSValueOutput(int, %d)
DSValueOutput(short, %d)
DSValueOutput(char, %c)
DSValueOutput(long, %lu)
DSValueOutput(float, %f)

#pragma mark -
#pragma Private Declarations

static
void DSPrimitiveTypeOutputMethodTest(void);

#pragma mark -
#pragma Public Declaration

void DSPrimitiveTypeOutputTest(void) {
    DSPrimitiveTypeOutputMethodTest();
    
}

#pragma mark -
#pragma Private Implementation

void DSPrimitiveTypeOutputMethodTest(void) {
    DSOutput_int(65);
    DSOutput_char('C');
    DSOutput_short(8);
    DSOutput_long(14);
    DSOutput_float(12.45);
   
}
