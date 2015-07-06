//
//  DSLinkedListEnumerator.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSLinkedListEnumerator__
#define __DSHomeWork__DSLinkedListEnumerator__

#include <stdbool.h>

#include "DSObject.h"

typedef struct DSLinkedListEnumerator DSLinkedListEnumerator;
typedef struct DSLinkedListNode DSLinkedListNode;
typedef struct DSLinkedList DSLinkedList;

struct DSLinkedListEnumerator{
    DSObject _super;
    
    void *_list;
    DSLinkedListNode *_node;
    uint64_t _mutationsCount;
    
    bool _valid;
};

extern
DSLinkedListEnumerator *DSLinkedListEnumeratorCreateWithList(DSLinkedList *list);

extern
void __DSLinkedListEnumeratorDeallocate(void *object);

extern
void *DSLinkedListEnumeratorGetNextObject(DSLinkedListEnumerator *enumerator);

extern
bool DSLinkedListEnumeratorIsValid(DSLinkedListEnumerator *enumerator);

#endif /* defined(__DSHomeWork__DSLinkedListEnumerator__) */
