//
//  DSObject.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 20.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSObject__
#define __DSHomeWork__DSObject__

#include <stdio.h>
#include <stdlib.h>

#define DSObjectCreateOfType(type) \
__DSObjectCreate(sizeof(type), (DSObjectDeallocatorCallback)__##type##Deallocate)

typedef void (*DSObjectDeallocatorCallback)(void *);

typedef struct {
    uint64_t _referenceCount;
    DSObjectDeallocatorCallback _deallocator;
} DSObject;

extern
void *__DSObjectCreate(size_t objectSize, DSObjectDeallocatorCallback deallocateCallback);

extern
void *DSObjectRetain(void *object);

extern
void DSObjectRelease(void *object);

extern
uint64_t DSObjectGetReferenceCount(void *object);

extern
void __DSObjectDeallocate(void *object);



#endif /* defined(__DSHomeWork__DSObject__) */
