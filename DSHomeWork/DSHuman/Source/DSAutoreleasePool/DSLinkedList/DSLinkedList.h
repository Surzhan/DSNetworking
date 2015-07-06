//
//  DSLinkedList.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSLinkedList__
#define __DSHomeWork__DSLinkedList__

#include <stdio.h>
#include <stdbool.h>

#include "DSObject.h"
#include "DSLinkedListNode.h"

typedef struct DSLinkedList DSLinkedList;

struct DSLinkedList {
    DSObject _super;
    
    DSLinkedListNode *_head;
    uint64_t _count;
    uint64_t _mutationCount;
};

extern
DSLinkedList *DSLinkedListCreate(void);

extern
void __DSLinkedListDeallocate(void *object);

extern
DSObject *DSLinkedListGetFirstObject(DSLinkedList *list);

extern
void DSLinkedListRemoveFirstObject(DSLinkedList *list);

extern
DSObject *DSLinkedListGetObjectBeforeObject(DSLinkedList *list, DSObject *object);

extern
bool DSLinkedListIsEmpty(DSLinkedList *list);

extern
void DSLinkedListAddObject(DSLinkedList *list, void *object);

extern
void DSLinkedListRemoveObject(DSLinkedList *list, void *object);

extern
void DSLinkedListRemoveAllObjects(DSLinkedList *list);

extern
bool DSLinkedListContainsObject(DSLinkedList *list, void *object);

extern
uint64_t DSLinkedListGetCount(DSLinkedList *list);

#endif /* defined(__DSHomeWork__DSLinkedList__) */
