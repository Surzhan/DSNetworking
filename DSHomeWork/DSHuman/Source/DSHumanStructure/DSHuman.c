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

const uint kDSMinAgeForMarriage = 16;

static
void DSHumanSetPartner(DSHuman *human, DSHuman *partner);

static
void DSHumanSetMother(DSHuman *human, DSHuman *mother);

static
void DSHumanSetFather(DSHuman *human, DSHuman *father);

static
DSArray *DSHumanGetChildrenArray(DSHuman *human);

static
void DSHumanRemoveAllChildren(DSHuman *human);

#pragma mark -
#pragma mark Public Implementations


void __DSHumanDeallocate(void *human) {
    DSHumanSetName(human, NULL);
    DSHumanMarried(human, NULL);
    DSHumanSetMother(human, NULL);
    DSHumanSetFather(human, NULL);
    DSHumanRemoveAllChildren (human);
    
    __DSObjectDeallocate(human);
}

DSHuman *DSHumanCreateWithParameters(DSHumanGender gender) {
    DSHuman *human = DSObjectCreateOfType(DSHuman);
    DSHumanSetGender(human, gender);
    
    return human;
}

void DSHumanAddChild(DSHuman *human, DSHuman *partner, DSHuman *child) {
    if (NULL != human && NULL != partner) {
        int genderHuman = DSHumanGetGender(human);
        int genderPartner = DSHumanGetGender(partner);
        if (kDSHumanUndefined == genderHuman
            && kDSHumanUndefined == genderPartner
            && genderHuman == genderPartner) {
            
            return;
        }
        
        if (NULL == child) {
            DSHuman *child = DSHumanCreateWithParameters(kDSHumanUndefined);
        }
        if (kDSHumanMale == genderHuman) {
            DSHumanSetFather(child, human);
            DSHumanSetMother(child, partner);
        } else {
            DSHumanSetFather(child, partner);
            DSHumanSetMother(child, human);
        }
    }
}

void DSHumanRemoveChild(DSHuman *human, DSHuman *parter) {
    
    
}

uint64_t DSHumanGetChildrenCount(DSHuman *human) {
    if (NULL != human) {
        return DSArrayGetCount(DSHumanGetChildrenArray(human));
    }
    
    return 0;
}

void DSHumanSetName(DSHuman *human, char *name) {
    if (NULL != human) {
        char *previousName = human->_name;
        
        if (NULL != previousName) {
            DSObjectRelease(previousName);
            human->_name = NULL;
        }
        if (NULL != name) {
            void *newName = DSStringCreateWithString(name);
            human->_name = newName;
        }
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

DSHuman *DSHumanGetPartner(DSHuman *human){
    return NULL != human ? human->_partner : NULL;
}

DSHuman *DSHumanGetMother(DSHuman *human) {
    return NULL !=human ? human->_mother : 0;
}

DSHuman *DSHumanGetFather(DSHuman *human) {
    return NULL != human ? human->_father : 0;
}

void DSHumanMarried (DSHuman *human, DSHuman *partner) {
    int genderHuman = DSHumanGetGender(human);
    int genderPartner = DSHumanGetGender(partner);
    if (NULL == human
        || NULL == partner
        || human == partner
        || genderHuman == kDSHumanUndefined
        || genderPartner == kDSHumanUndefined
        || genderHuman == genderPartner
        || (DSHumanGetAge(human) < kDSMinAgeForMarriage)
        || (DSHumanGetAge(partner) < kDSMinAgeForMarriage)) {
        
        return;
    }
    if (kDSHumanMale == genderHuman) {
        DSObjectRetain(partner);
    } else {
        DSObjectRetain(human);
    }

    DSHumanDivorce(human);
    DSHumanDivorce(partner);
    DSHumanSetPartner(human, partner);
    DSHumanSetPartner(partner, human);
}

void DSHumanDivorce(DSHuman *human) {
    if (false == DSHumanIsMarried(human)) {
        
        return;
    }
        DSHuman *partnerHuman = DSHumanGetPartner(human);
    
    if (kDSHumanMale == DSHumanGetGender(human)) {
        DSObjectRelease(partnerHuman);
    } else {
        DSObjectRelease(human);
    }

        DSHumanSetPartner (human, NULL);
        DSHumanSetPartner (partnerHuman, NULL);
}

bool DSHumanIsMarried(DSHuman *human) {
    return NULL != DSHumanGetPartner(human);
}

#pragma mark -
#pragma mark Private Implementations

void DSHumanSetPartner(DSHuman *human, DSHuman *partner) {
    if (NULL != human) {
        human->_partner = partner;
    }
}

void DSHumanSetMother(DSHuman *human, DSHuman *mother) {
    if (NULL != human && NULL != mother && human != mother && kDSHumanFemale == DSHumanGetGender(mother)) {
        human->_mother = mother;
    }
}

void DSHumanSetFather(DSHuman *human, DSHuman *father) {
    if (NULL != human && NULL != father && human != father && kDSHumanMale == DSHumanGetGender(father)) {
        human->_father = father;
    }
}

DSArray *DSHumanGetChildrenArray(DSHuman *human) {
    return  NULL != human ? human->_children : NULL;
}

void DSHumanRemoveAllChildren(DSHuman *human) {
    
}
