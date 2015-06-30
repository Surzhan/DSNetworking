//
//  DSAutoreleaseStack.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSAutoreleaseStack__
#define __DSHomeWork__DSAutoreleaseStack__

#include <stdbool.h>

#include "DSObject.h"

typedef enum {
    kDSAutoreleasingStackPoppedNULL,
    kDSAutoreleasingStackPoppedObject
} DSAutoreleasingStackPopType;

typedef struct DSAutoReleasingStack DSAutoreleasingStack;

struct DSAutoreleasingStack {
    DSObject _super;
    
    void **_data;
    size_t _size;
    size_t _count;
};

extern
DSAutoreleasingStack *DSAutoreleasingStackCreateWithSize(size_t size);

extern
void __DSAutoReleasingStackDeallocate(void *object);

extern
bool DSAutoreleasingStackIsEmpty(DSAutoreleasingStack *stack);

extern
bool DSAutoreleasingStackIsFull(DSAutoreleasingStack *stack);

extern
void DSAutoreleasingStackPushObject(DSAutoreleasingStack *stack, void *object);

extern
DSAutoreleasingStackPopType DSAutoreleasingStackPopObject(DSAutoreleasingStack *stack);

extern
DSAutoreleasingStackPopType DSAutoreleasingStackPopObjectsUntilNULL(DSAutoreleasingStack *stack);

#endif /* defined(__DSHomeWork__DSAutoreleaseStack__) */
