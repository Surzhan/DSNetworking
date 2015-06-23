//
//  DSString.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 26.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "DSString.h"
#include "DSMacros.h"

#pragma mark -
#pragma mark Private Declaration

static
void DSStringSetLength(DSString *object, uint64_t length);

#pragma mark -
#pragma Pablic Implementation

DSString *DSStringCreateWithString(char *string) {
    DSString *newObject = DSObjectCreateOfType(DSString);
    DSStringSetString(newObject, string);
    
    return newObject;
}

char *DSStringGetString(DSString *object) {
    DSObjectGetter(object, _string);
}

void DSStringSetString(DSString *object, char *newString) {
    char *originalString = DSStringGetString(object);
    if (NULL == object || newString == originalString) {
   
        return;
    }
    size_t length = 0;
    if (NULL != newString) {
        length = strlen(newString) + 1;
        object->_string = malloc(length);
        assert(NULL != object->_string);
        memcpy(object->_string, newString, length);
    }
    
    DSStringSetLength(object, length);
    
}

size_t DSStringGetLength(DSString *object) {
    return (NULL != object) ? object->_length : 0;
}

void __DSStringDeallocate(void *object) {
      DSStringSetString(object, NULL);
    __DSObjectDeallocate(object);
}

#pragma mark -
#pragma mark Private Implementations

void DSStringSetLength(DSString *object, uint64_t length) {
    if (NULL != object) {
            object->_length = length;
        }
}
