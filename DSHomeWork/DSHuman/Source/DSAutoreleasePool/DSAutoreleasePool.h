//
//  DSAutoreleasePool.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSAutoreleasePool__
#define __DSHomeWork__DSAutoreleasePool__

#include "DSObject.h"
#include "DSLinkedList.h"
#include "DSAutoreleasingStack.h"


typedef struct {
    DSObject _super;
    
    DSLinkedList *_list;
    DSAutoreleasingStack *_currentStack;
    uint64_t _emptyStacksCount;
} DSAutoreleasePool;

extern
DSAutoreleasePool *DSAutoreleasePoolCreate(void);

extern
void DSAutoreleasePoolAddObject(DSAutoreleasePool *pool, void *object);

extern
void DSAutoreleasePoolDrain(DSAutoreleasePool *pool);

#endif /* defined(__DSHomeWork__DSAutoreleasePool__) */
