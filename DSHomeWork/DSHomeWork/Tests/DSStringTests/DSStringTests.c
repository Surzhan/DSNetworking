//
//  DSStringTests.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 26.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//
#include <assert.h>
#include <string.h>

#include "DSStringTests.h"
#include "DSString.h"
#include "DSObject.h"

#pragma mark -
#pragma mark Private Declaration

void DSStringBDDTest(void);

#pragma mark -
#pragma Private Implementation

void DSStringTests(void){
    DSStringBDDTest();
}

#pragma mark -
#pragma Private Implementation

void DSStringBDDTest(void) {
    //  after the string is created
    DSString *string = DSStringCreateWithString("Cruz Castillo");
    
    //      it reference count is 1
    assert(1 == DSObjectGetReferenceCount(string));
    
    //      string is not NULL
    assert(NULL != string);
    
    //      recorded data transmitted in the string (Cruz Castillo)
    assert(0 == strcmp(DSStringGetString(string), "Cruz Castillo"));
    assert(DSStringGetString(string) != "Cruz Castillo");
    
    //      the length of the sring set 14
    assert(14 == DSStringGetLength(string));
    
    //  after change string
    DSStringSetString(string, "");
    
    //      string is not NULL
    assert(NULL != string);
    
    //      the length of the sring set 14
    assert(1 == DSStringGetLength(string));

    DSObjectRelease(string);
}
