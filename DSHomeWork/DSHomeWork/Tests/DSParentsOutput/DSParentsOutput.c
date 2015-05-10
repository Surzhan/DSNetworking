//
//  DSParentsOutput.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 10.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include "DSParentsOutput.h"

#include "DSParentsOutput.h"

static int kDSCountIteration = 1000;
int value;

void DSParentsOutputTest(void) {
    for (value = 0; value <= kDSCountIteration; value++) {
        DSChekMotherFother(value);
    }
    return;
}
