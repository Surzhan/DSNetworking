//
//  DSArray.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 26.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <assert.h>
#include <string.h>

#include "DSArray.h"

const uint64_t kDSNotFound = UINT64_MAX;
static const uint64_t kDSArrayMaximumCapacity = kDSNotFound - 1;

#pragma mark -
#pragma mark Private Declaration

static
void DSArraySetCapacity(DSArray *array, uint64_t capacity);

static
uint64_t DSArrayGetCapacity(DSArray *array);

static
void DSArraySetCount(DSArray *array, uint64_t count);

static
void DSArraySetObjectAtIndex(DSArray *array, void *object, uint64_t index);

static
void DSArrayResizeIfNeeded(DSArray *array);

static
bool DSArrayShouldResize(DSArray *array);

static
uint64_t DSArrayPrefferedCapacity(DSArray *array);

#pragma mark -
#pragma Pablic Implementation

void *DSArrayCreateWithCapacity(uint64_t capasity) {
    DSArray *newArray = DSObjectCreateOfType(DSArray);
    DSArraySetCapacity(newArray, capasity);
    
    return newArray;
}

void __DSArrayDeallocate(DSArray *array){
    DSArrayRemoveAllObjects(array);
    __DSObjectDeallocate(array);
}

void DSArrayAddObject(DSArray *array, void *object) {
    if (NULL != array && NULL != object) {
        uint64_t count = DSArrayGetCount(array);
        DSArraySetCount(array, count + 1);
        DSArraySetObjectAtIndex(array, object, count);
    }
}

void DSArrayRemoveObjectAtIndex(DSArray *array, uint64_t index) {
    uint64_t count = DSArrayGetCount(array);
    if (NULL == array || index > count) {

        return;
    }
    
    void **database = array->_database;
    if (index < (count - 1)) {
        uint64_t elementsCount = count - (index + 1);
        
        memmove(&database[index], &database[index + 1], elementsCount * sizeof(*database));
    }
    
    DSArraySetObjectAtIndex(array, NULL, count - 1);
    DSArraySetCount(array, count - 1);
    
}

void DSArrayRemoveAllObjects(DSArray *array) {
    if (NULL != array) {
        uint64_t count = DSArrayGetCount(array);
        for (uint64_t index = 0; index < count; index++) {
            DSArraySetObjectAtIndex(array, NULL, index);
        }
        DSArraySetCount(array, 0);
        DSArraySetCapacity(array, 0);
    }
    
}

uint64_t DSArrayGetCount(DSArray *array) {
     return NULL != array ? array->_count : 0;
}

uint64_t DSArrayGetIndexOfObject(DSArray *array, void *object) {
    if (NULL == array) {
        return 0;
    }
    
    if (NULL == object) {
        return kDSNotFound;
    }
    
    uint64_t result = kDSNotFound;
    uint64_t count = DSArrayGetCount(array);
    for (uint64_t index = 0; index < count; index++) {
        if (DSArrayGetObjectAtIndex(array, index) == object) {
            result = index;
            break;
        }
    }
    
    return result;
}

void *DSArrayGetObjectAtIndex(DSArray *array, uint64_t index) {
    void *result = NULL;
    if (NULL != array) {
        assert(index < DSArrayGetCount(array));
        
        result = array->_database[index];
    }
    return result;
}

bool DSArrayContainsObject(DSArray *array, void *object) {
    return (NULL != array) && (kDSNotFound != DSArrayGetIndexOfObject(array, object));
}

void **DSArrayGetDatabase(DSArray *array) {
    return array != NULL ? array->_database : NULL;
}

#pragma mark -
#pragma mark Private Implementations

void DSArraySetCapacity(DSArray *array, uint64_t capacity) {
    if (NULL != array && array->_capacity != capacity) {
        assert(kDSArrayMaximumCapacity >= capacity);
        
        size_t size = capacity * sizeof(*array->_database);
        if (0 == size && NULL != array->_database) {
            free(array->_database);
            array->_database = NULL;
        } else {
            array->_database = realloc(array->_database, size);
            
            assert(NULL != array->_database);
        }
        
        if (capacity > array->_capacity) {
            void *startPointer = array->_database + array->_capacity;
            size_t numberOfBytes = (capacity - array->_capacity) * sizeof(*array->_database);
            
            memset(startPointer, 0, numberOfBytes);
        }
        
        array->_capacity = capacity;
    }
}

uint64_t DSArrayGetCapacity(DSArray *array) {
    return (NULL != array) ? array->_capacity : 0;
}

void DSArraySetCount(DSArray *array, uint64_t count) {
    if (NULL != array) {
        assert(kDSArrayMaximumCapacity >= count);
        array->_count = count;
        
        DSArrayResizeIfNeeded(array);
    }
}

void DSArraySetObjectAtIndex(DSArray *array, void *object, uint64_t index) {
    if (NULL == array) {
        return;
    }
    assert(index < DSArrayGetCount(array));
    
    DSObject *currentObject = array->_database[index];
    if (currentObject != object) {
        DSObjectRetain(object);
        DSObjectRelease(currentObject);
        
        array->_database[index] = object;
    }
}

void DSArrayResizeIfNeeded(DSArray *array) {
    if (DSArrayShouldResize(array)) {
        DSArraySetCapacity(array, DSArrayPrefferedCapacity(array));
    }
}

bool DSArrayShouldResize(DSArray *array) {
    return (NULL != array) && (array->_capacity != DSArrayPrefferedCapacity(array));
}

uint64_t DSArrayPrefferedCapacity(DSArray *array) {
    if (NULL != array) {
        uint64_t count = DSArrayGetCount(array);
        uint64_t capacity = DSArrayGetCapacity(array);
        if (count == capacity) {
            return capacity;
        }
        
        return count < capacity ? count : count + (count % 3);
    }
    
    return 0;
}
