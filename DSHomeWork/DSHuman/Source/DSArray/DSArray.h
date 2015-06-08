//
//  DSArray.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 26.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSArray__
#define __DSHomeWork__DSArray__

#include <stdio.h>
#include <stdbool.h>

#include "DSObject.h"

extern const uint64_t kDSNotFound;

typedef struct DSArray DSArray;

struct DSArray {
    DSObject _super;
    
    void **_database;
    uint64_t _capacity;
    uint64_t _count;
};

extern
void *DSArrayCreateWithCapacity(uint64_t capasity);

extern
void __DSArrayDeallocate(DSArray *array);

extern
void DSArrayAddObject(DSArray *array, void *object);

extern
void DSArrayRemoveObjectAtIndex(DSArray *array, uint64_t index);

extern
void DSArrayRemoveAllObjects(DSArray *array);

extern
uint64_t DSArrayGetCount(DSArray *array);

extern
uint64_t DSArrayGetIndexOfObject(DSArray *array, void *object);

extern
void *DSArrayGetObjectAtIndex(DSArray *array, uint64_t index);

extern
bool DSArrayContainsObject(DSArray *array, void *object);

#endif /* defined(__DSHomeWork__DSArray__) */
