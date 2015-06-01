//
//  DSObject.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 20.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <assert.h>

#include "DSObject.h"

void *__DSObjectCreate(size_t objectSize, DSObjectDeallocatorCallback deallocateCallback) {
    assert(0 != objectSize);
    
    DSObject *object = calloc(1, objectSize);
    
    assert(NULL != object);
    
    object->_referenceCount = 1;
    object->_deallocator = deallocateCallback;
    
    return object;
}

void *DSObjectRetain(void *object) {
    if (NULL != object) {
        ((DSObject *)object)->_referenceCount++;
    }
    
    return object;
}

void DSObjectRelease(void *object) {
    if (NULL != object) {
        uint64_t count = ((DSObject *)object)->_referenceCount - 1;
        ((DSObject *)object)->_referenceCount = count;
        
        if (0 == count) {
            ((DSObject *)object)->_deallocator(object);
        }
    }
}

uint64_t DSObjectGetReferenceCount(void *object) {
    return object ? ((DSObject*)object)->_referenceCount : 0;
}

void __DSObjectDeallocate(void *object) {
    free(object);
}
