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
    // create newhuman man
    DSHuman *newHuman = DSHumanCreateWithParameters(kDSHumanMale);
    
    //   new human != NULL ?
    assert(NULL != newHuman);
    
    //   add age newHuman man
    DSHumanSetAge(newHuman, 23);
    printf("%d age\n",DSHumanGetAge(newHuman));
    
    // named newHuman
//    DSHumanSetName(newHuman, "Oleg");
//    printf("%s name\n",DSHumanGetName(newHuman));
    
    // they are married?
    printf("%d status newHumenBefore\n",DSHumanIsMarried(newHuman));
    
    
    // create new human women
    DSHuman *newHuman2 = DSHumanCreateWithParameters(kDSHumanFemale);
    
    //   add age new human women
    DSHumanSetAge(newHuman2, 3);
    printf("%d age newHuman2\n",DSHumanGetAge(newHuman2));
    
    // create new human second man
    DSHuman *newHuman3 = DSHumanCreateWithParameters(kDSHumanMale);
    
    // married newHuman and newHuman2
    DSHumanMarried(newHuman, newHuman2);
    
     // married newHuman and newHuman3
    DSHumanMarried(newHuman, newHuman3);
    
    
    // divorce newHuman
    DSHumanDivorce (newHuman);
    
    // they are married?
    printf("%d status newHumen\n",DSHumanIsMarried(newHuman));
    printf("%d status newHumen2\n",DSHumanIsMarried(newHuman2));
    printf("%d status newHumen3\n",DSHumanIsMarried(newHuman3));
    
    // what sex they are?
    printf("%d sex newHumen\n",DSHumanGetGender(newHuman));
    printf("%d sex newHumen2\n",DSHumanGetGender(newHuman2));
    printf("%d sex newHumen3\n",DSHumanGetGender(newHuman3));
    
    
    
}