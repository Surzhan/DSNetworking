//
//  main.c
//  DSHuman
//
//  Created by Denis Surzhan on 18.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <stdio.h>

#include "DSHuman.h"
#include "DSHumanBDDTest.h"
#include "DSArrayTests.h"
#include "DSStringTests.h"


int main(int argc, const char * argv[]) {
   
    DSHumanBDDTest();
    DSArrayBehaviorTest();
    DSStringTests();
    
    return 0;
}
