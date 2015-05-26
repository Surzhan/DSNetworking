//
//  DSHumanStructure.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 18.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>


#include "DSHuman.h"

#pragma mark -
#pragma mark Private Declaration

static
void DSHumanSetPartner(DSHuman *human, DSHuman *partner);

static
void DSHumanSetMother(DSHuman *human, DSHuman *mother);

static
void DSHumanSetFather(DSHuman *human, DSHuman *father);




#pragma mark -
#pragma mark Public Implementations

DSHuman *DSHumanCreateWithParametrs(char *name, DSHumanGender gender, uint8_t age, *mother, *father) {
    DSHuman *newHuman = calloc(1, sizeof(DSHuman));
    
    assert(NULL != newHuman);
    
    DSHumanSetNewName(newHuman, name);
    DSHumanSetAge(newHuman, age);
    DSHumanSetGender(newHuman, gender);
    DSHumanSetMother(newHuman, *mother);
    DSHumanSetMother(newHuman, *father);
    
    
    
    return newHuman;
}

void DSHumanSetAge(DSHuman *human, uint8_t age) {
    NULL != human ? human->_age = age; NULL
    
}

uint8_t DSHumanGetAge(DSHuman *human) {
    
    return NULL != human ? human->_age : 0;
}

void DSHumanSetGender(DSHuman *human, DSHumanGender gender) {
    NULL != human ? human->_gender = gender;
    
}

DSHumanGender DSHumanGetGender(DSHuman *human) {
    
    return NULL != human ? human->_gender : 0;
}

void DSHumanSetMother(DSHuman *human, DSHuman *mother) {
    (NULL != human && NULL != mother) ?  human->_mother = mother : NULL;
    
}

DSHuman *DSHumanGetMother(DSHuman *human) {
    
    return NULL !=human ? human->_mother : 0;
}

void DSHumanSetFather(DSHuman *human, DSHuman *father) {
    (NULL != human && NULL != father) ?  human->_father = father : NULL;
    
}

DSHuman *DSHumanGetFather(DSHuman *human) {
    
    return NULL != human ? human->_father : 0;
}

void DSHumanSetAddPartner (DSHuman *human, DSHuman *partner) {
    (NULL != human && NULL != partner) ?  human->_partner = partner : NULL;
    
}

DSHuman *DSHumanGetAddPartner (DSHuman *human) {
    
    return NULL != human ? human->_partner : 0;
}