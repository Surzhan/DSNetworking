//
//  DSHumanBDDTest.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 20.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//
#include <assert.h>


#include "DSHumanBDDTest.h"
#include "DSHuman.h"

void DSHumanBDDTest(void) {
    //  after create new human
    DSHuman *newHuman = DSHumanCreateWithParameters(kDSHumanMale);
    
    //      retain count must be equal to 1
    assert(1 == DSObjectGetReferenceCount(newHuman));
    
    //      new human must not be NULL
    assert(NULL != newHuman);
    
    //      gender must be kDSHumanMale
    assert(kDSHumanMale == DSHumanGetGender(newHuman));
    
    //      age must by 0
    assert(0 == DSHumanGetAge(newHuman));
    
    //      new human not by married
    assert(false == DSHumanIsMarried(newHuman));
    
    //  after add age and name newHuman
    DSHumanSetAge(newHuman, 23);
    DSHumanSetName(newHuman, "Oleg");
    
    //      age mast be 23
    assert(23 == DSHumanGetAge(newHuman));
    
    //      name mast be Oleg
    assert("Oleg" != DSHumanGetName(newHuman));
    
    // after create two new human
    DSHuman *newHuman2 = DSHumanCreateWithParameters(kDSHumanFemale);
    DSHuman *newHuman3 = DSHumanCreateWithParameters(kDSHumanMale);
    
    //   add added age newHuman2 and newHuman3
    DSHumanSetAge(newHuman2, 3);
    DSHumanSetAge(newHuman3, 35);
    
    //      married newHuman and newHuman2
    DSHumanMarried(newHuman, newHuman2);
    
    //      married newHuman and newHuman3
    DSHumanMarried(newHuman, newHuman3);
    
    //      human, human2 and human3 must by not married
    assert(false == DSHumanIsMarried(newHuman));
    assert(false == DSHumanIsMarried(newHuman2));
    assert(false == DSHumanIsMarried(newHuman3));
    
    //      after set newHuman2 with gender female age 18
    DSHumanSetAge(newHuman2, 18);
    
    //      married newHuman and newHuman2
    DSHumanMarried(newHuman, newHuman2);
    
    //      human, human2 must by married
    assert(true == DSHumanIsMarried(newHuman));
    
    
    // divorce newHuman
    DSHumanDivorce (newHuman);
    
    DSObjectRelease(newHuman3);
    DSObjectRelease(newHuman2);
    DSObjectRelease(newHuman);
}
