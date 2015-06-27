//
//  main.c
//  DSHuman
//
//  Created by Denis Surzhan on 18.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <stdio.h>

#include "DSHuman.h"
#include "DSMacros.h"
#include "DSHumanBDDTest.h"
#include "DSArrayTests.h"
#include "DSStringTests.h"
#include "DSLinkedNodeTests.h"
#include "DSLinkedListTests.h"
#include "DSLinkedListEnumeratorTests.h"
#include "DSAutoReleasingStackTests.h"
#include "DSAutoreleasePoolTests.h"

int main(int argc, const char * argv[]) {
    performTest(DSHumanBDDTest);
    performTest(DSArrayBehaviorTest);
    performTest(DSStringTests);
//    performTest(DSLinkedListNodeTests);
//    performTest(DSLinkedListTests);
//    performTest(DSLinkedListEnumeratorTests);
//    performTest(DSAutoReleasingStackTests);
//    performTest(DSAutoreleasePoolTests);
    
    return 0;
}
