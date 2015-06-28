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

static
bool DSHumanConditionsOfMarriage(DSHuman *human, DSHuman *partner);

static
void DSHumanSetChildrenArray(DSHuman *human, DSArray *childrenArray);

#pragma mark -
#pragma mark Public Implementations


void __DSHumanDeallocate(void *human) {
    DSHumanSetName(human, NULL);
    DSHumanMarried(human, NULL);
    DSHumanSetMother(human, NULL);
    DSHumanSetFather(human, NULL);
    DSHumanRemoveAllChildren(human);
    
    __DSObjectDeallocate(human);
}

DSHuman *DSHumanCreateWithParameters(DSHumanGender gender) {
    DSHuman *human = DSObjectCreateOfType(DSHuman);
    DSHumanSetGender(human, gender);
    
    return human;
}

void DSHumanAddChild(DSHuman *human, DSHuman *child) {
    if (NULL != human && NULL != child && human != child) {
        int genderHuman = DSHumanGetGender(human);
        if (kDSHumanUndefined == genderHuman) {
            
            return;
        }
        DSObjectRetain(child);
        if (kDSHumanMale == genderHuman) {
            DSHumanRemoveChild(DSHumanGetFather(child), child);
            DSHumanSetFather(child, human);
            } else {
            DSHumanRemoveChild(DSHumanGetMother(child), child);
            DSHumanSetMother(child, human);
        }
        DSArray *childrenArray = DSHumanGetChildrenArray(human);
        if (NULL == childrenArray) {
            childrenArray = DSArrayCreateWithCapacity(1);
            DSHumanSetChildrenArray(human, childrenArray);
            DSObjectRelease(childrenArray);
        }
        DSArrayAddObject(childrenArray, child);
        DSObjectRelease(child);
    }
}

void DSHumanRemoveChild(DSHuman *human, DSHuman *child) {
    if (NULL != human && NULL != child) {
        void *childrenArrayObject = DSHumanGetChildrenArray(human);
        void **children = DSArrayGetDatabase(childrenArrayObject);
        uint64_t count = DSArrayGetCount(childrenArrayObject);
        for (uint64_t index = 0; index < count; index++) {
            if (children[index] == child) {
                DSArrayRemoveObjectAtIndex(childrenArrayObject, index);
            }
        }
    }
}

uint64_t DSHumanGetChildrenCount(DSHuman *human) {
    if (NULL != human) {
        return DSArrayGetCount(DSHumanGetChildrenArray(human));
    }
    
    return 0;
}

void DSHumanSetName(DSHuman *human, char *name) {
    if (NULL != human) {
        DSString *previousName = human->_name;
        
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
    return DSStringGetString(human->_name);
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
    if (true == DSHumanConditionsOfMarriage(human, partner)) {
        
        return;
    }
    if (kDSHumanMale == DSHumanGetGender(human)) {
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
    if (NULL != human) {
        DSArrayRemoveAllObjects(DSHumanGetChildrenArray(human));
    }
}

bool DSHumanConditionsOfMarriage(DSHuman *human, DSHuman *partner) {
    int genderHuman = DSHumanGetGender(human);
    int genderPartner = DSHumanGetGender(partner);
    return (NULL == human
            || NULL == partner
            || human == partner
            || genderHuman == kDSHumanUndefined
            || genderPartner == kDSHumanUndefined
            || genderHuman == genderPartner
            || (DSHumanGetAge(human) < kDSMinAgeForMarriage)
            || (DSHumanGetAge(partner) < kDSMinAgeForMarriage));
}

void DSHumanSetChildrenArray(DSHuman *human, DSArray *childrenArray) {
    DSObjectRetainSetter(human, _children, childrenArray);
}
