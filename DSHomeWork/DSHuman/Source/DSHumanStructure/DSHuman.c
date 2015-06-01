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


const uint kDSMinAgeForMarriage = 16;

#pragma mark -
#pragma mark Public Implementations


void __DSHumanDeallocate(void *human) {
    DSHumanSetName(human, NULL);
    DSHumanMarried(human, NULL);
    DSHumanSetMother(human, NULL);
    DSHumanSetFather(human, NULL);
    
    __DSObjectDeallocate(human);
}



DSHuman *DSHumanCreateWithParameters(DSHumanGender gender) {
    DSHuman *human = DSObjectCreateOfType(DSHuman);
    
    DSHumanSetGender(human, gender);
    
    return human;
}

void DSHumanAddChild(DSHuman *mother, DSHuman *father) {
    
}

void DSHumanRemoveChild(DSHuman *human, DSHuman *parter) {
    
    
}
        
        
//size_t DSHumanGetChildrenCount(DSHuman *human) {
//    
//    return;
//}


void DSHumanSetName(DSHuman *human, char *name) {
    if (NULL != human && human->_name != name) {
        DSObjectRetain(name);
        DSObjectRelease(human->_name);
        human->_name = name;
        assert(NULL != human->_name);
    }
}

char *DSHumanGetName(DSHuman *human) {
    
    return NULL != human ? human->_name : 0;
}

void DSHumanSetAge(DSHuman *human, uint8_t age) {
    if (NULL != human) {
        human->_age = age;
    }
}

uint8_t DSHumanGetAge(DSHuman *human) {
    
    return NULL != human ? human->_age : 0;
}

void DSHumanSetGender(DSHuman *human, DSHumanGender gender) {
    if (NULL != human) {
        human->_gender = gender;
    }
}

DSHumanGender DSHumanGetGender(DSHuman *human) {
    
    return NULL != human ? human->_gender : 0;
}

void DSHumanSetPartner(DSHuman *human, DSHuman *partner) {
    if (NULL != human) {
        human->_partner = partner;
    }
}

DSHuman *DSHumanGetPartner(DSHuman *human){
    
    return NULL != human ? human->_partner : 0;
}

void DSHumanSetMother(DSHuman *human, DSHuman *mother) {
    if (NULL != human && NULL != mother && human != mother && kDSHumanFemale == DSHumanGetGender(mother)) {
        human->_mother = mother;
    }
}

DSHuman *DSHumanGetMother(DSHuman *human) {
    
    return NULL !=human ? human->_mother : 0;
}

void DSHumanSetFather(DSHuman *human, DSHuman *father) {
    if (NULL != human && NULL != father && human != father && kDSHumanMale == DSHumanGetGender(father)) {
        human->_father = father;
    }
}

DSHuman *DSHumanGetFather(DSHuman *human) {
    
    return NULL != human ? human->_father : 0;
}

void DSHumanMarried (DSHuman *human, DSHuman *partner) {
    int genderHuman = DSHumanGetGender(human);
    int genderPartner = DSHumanGetGender(partner);
    if (NULL == human ||
        NULL == partner ||
        human == partner ||
        genderHuman == kDSHumanUndefined ||
        genderPartner == kDSHumanUndefined ||
        genderHuman == genderPartner ||
        (DSHumanGetAge(human) < kDSMinAgeForMarriage) ||
        (DSHumanGetAge(partner) < kDSMinAgeForMarriage)) {
        printf("\nMission impossible\n\n");
        return;
    }
    if (kDSHumanMale == genderHuman) {
            DSObjectRetain(partner);
            } else
                DSObjectRetain(human);


    DSHumanDivorce(human);
    DSHumanDivorce(partner);
    DSHumanSetPartner (human, partner);
    DSHumanSetPartner (partner, human);
}

void DSHumanDivorce(DSHuman *human) {
    if (false == DSHumanIsMarried(human)) {
        return;
    }
        DSHuman *partnerHuman = DSHumanGetPartner(human);
        DSHumanSetPartner (human, NULL);
        DSHumanSetPartner (partnerHuman, NULL);
    
    if (kDSHumanMale == DSHumanGetGender(human)) {
        DSObjectRelease(partnerHuman);
    } else
        DSObjectRelease(human);
    
}

bool DSHumanIsMarried(DSHuman *human) {
    
    return NULL != human && NULL != DSHumanGetPartner(human) ? true : false;
}
