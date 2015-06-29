//
//  DSLinkedListPrivate.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 28.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef DSHomeWork_DSLinkedListPrivate_h
#define DSHomeWork_DSLinkedListPrivate_h

#include "DSLinkedList.h"

typedef struct DSLinkedListNode DSLinkedListNode;

typedef struct {
    DSLinkedListNode *object;
    DSLinkedListNode *previousNode;
    DSLinkedListNode *node;
} DSLinkedListNodeContext;

typedef bool (*DSLinkedListNodeComparisonFunction)(DSLinkedListNode *node, DSLinkedListNodeContext context);

extern
void DSLinkedListSetHead(DSLinkedList *list, DSLinkedListNode *node);

extern
DSLinkedListNode *DSLinkedListGetHead(DSLinkedList *list);

extern
void DSLinkedListSetMutationsCount(DSLinkedList *list, uint64_t count);

extern
uint64_t DSLinkedListGetMutationsCount(DSLinkedList *list);

extern
DSLinkedListNode *DSLinkedListFindNodeWithContext(DSLinkedList *list,
                                                    DSLinkedListNodeComparisonFunction comparator,
                                                    DSLinkedListNodeContext *context);

extern
bool DSLinkedListNodeContainsObject(DSLinkedListNode *node, DSLinkedListNodeContext context);

extern
DSLinkedListNodeContext DSLinkedListNodeGetContextForListWithObject(DSLinkedList *list, void *object);

#endif
