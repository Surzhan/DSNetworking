//
//  DSAutoreleaseStack.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <assert.h>

#include "DSAutoreleasingStack.h"
#include "DSMacros.h"

#pragma mark -
#pragma mark Private Declaration

static
void DSAutoreleasingStackSetCount(DSAutoreleasingStack *stack, uint32_t count);

static
uint32_t DSAutoreleasingStackGetCount(DSAutoreleasingStack *stack);

static
void DSAutoreleaseStackSetData(DSAutoreleasingStack *stack, void **data);

static
void **DSAutoreleasingStackGetData(DSAutoreleasingStack *stack);

static
void *DSAutoreleasingStackGetHead(DSAutoreleasingStack *stack);

static
void DSAutoreleasingStackSetSize(DSAutoreleasingStack *stack, uint32_t size);

static
uint32_t DSAutoreleasingStackGetSize(DSAutoreleasingStack *stack);

#pragma mark -
#pragma mark Pablic Implementation

DSAutoreleasingStack *DSAutoreleasingStackCreateWithSize(uint32_t size) {
    assert(0 != size);
    
    DSAutoreleasingStack *stack = DSObjectCreateOfType(DSAutoreleasingStack);
    DSAutoreleasingStackSetSize(stack, size);
    
    return stack;
}

void __DSAutoreleasingStackDeallocate(void *object) {
    DSAutoreleasingStackSetSize(object, 0);
    
    __DSObjectDeallocate(object);
}

bool DSAutoreleasingStackIsEmpty(DSAutoreleasingStack *stack) {
    return (NULL != stack) && (0 == DSAutoreleasingStackGetCount(stack));
}

bool DSAutoreleasingStackIsFull(DSAutoreleasingStack *stack) {
    return NULL != stack && DSAutoreleasingStackGetSize(stack) == DSAutoreleasingStackGetCount(stack);
}

void DSAutoreleasingStackPushObject(DSAutoreleasingStack *stack, void *object) {
    if (NULL != stack) {
        assert(false == DSAutoreleasingStackIsFull(stack));
        
        void **head = DSAutoreleasingStackGetHead(stack) + 1;
        *head = object;
        DSAutoreleasingStackSetCount(stack, DSAutoreleasingStackGetCount(stack) + 1);
    }

}

DSAutoreleasingStackPopType DSAutoreleasingStackPopObject(DSAutoreleasingStack *stack) {
    DSAutoreleasingStackPopType result = kDSAutoreleasingStackPoppedNULL;
    if (NULL != stack) {
        assert(false == DSAutoreleasingStackIsEmpty(stack));
        void **head = DSAutoreleasingStackGetHead(stack);
        
        if (NULL != *head) {
            DSObjectRelease(*head);
            result = kDSAutoreleasingStackPoppedObject;
        }
        
        DSAutoreleasingStackSetCount(stack, DSAutoreleasingStackGetCount(stack) - 1);
    }
    
    return result;
}

DSAutoreleasingStackPopType DSAutoreleasingStackPopObjectsUntilNULL(DSAutoreleasingStack *stack) {
    if (NULL != stack) {
        assert(false == DSAutoreleasingStackIsEmpty(stack));
        
        DSAutoreleasingStackPopType type;
        do {
            type = DSAutoreleasingStackPopObject(stack);
        } while (kDSAutoreleasingStackPoppedObject == type
                 && false == DSAutoreleasingStackIsEmpty(stack));
        
        return type;
    }
    
    return 0;
}

#pragma mark -
#pragma mark Private Implementations

void DSAutoreleasingStackSetCount(DSAutoreleasingStack *stack, uint32_t count) {
    DSObjectAssignSetter(stack, _count, count);
}

uint32_t DSAutoreleasingStackGetCount(DSAutoreleasingStack *stack) {
    DSObjectGetterSimpleTypes(stack, _count)
}

void DSAutoreleaseStackSetData(DSAutoreleasingStack *stack, void **data) {
    DSObjectAssignSetter(stack, _data, data);
}

void **DSAutoreleasingStackGetData(DSAutoreleasingStack *stack) {
    DSObjectGetter(stack, _data);
}

void *DSAutoreleasingStackGetHead(DSAutoreleasingStack *stack) {
    return (NULL != stack) ? DSAutoreleasingStackGetData(stack) + DSAutoreleasingStackGetCount(stack) - 1 : NULL;
}

void DSAutoreleasingStackSetSize(DSAutoreleasingStack *stack, uint32_t size) {
    if (NULL != stack) {
        uint32_t previousSize = DSAutoreleasingStackGetSize(stack);
        void **data = DSAutoreleasingStackGetData(stack);
        if (previousSize != size) {
            if (0 != previousSize) {
                free(data);
                DSAutoreleaseStackSetData(stack, NULL);
            }
            if (0 != size) {
                data = realloc(stack->_data, sizeof(*stack->_data));
                assert(NULL != data);
                DSAutoreleaseStackSetData(stack, data);
            }
            
            DSObjectAssignSetter(stack, _size, size);
        }
    }
}
uint32_t DSAutoreleasingStackGetSize(DSAutoreleasingStack *stack) {
    DSObjectGetterSimpleTypes(stack, _size);
}
