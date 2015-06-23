//
//  DSLinkedListNode.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSLinkedListNode__
#define __DSHomeWork__DSLinkedListNode__

#include <stdio.h>

#include "DSObject.h"

typedef struct DSLinkedListNode DSLinkedListNode;

struct DSLinkedListNode {
    DSObject _super;
    
    DSLinkedListNode *_nextNode;
    void *_object;
};

extern
DSLinkedListNode *DSLinkedListNodeCreateWithObject(void *object);

extern
void __DSLinkedListNodeDeallocate(void *object);

extern
DSLinkedListNode *DSLinkedListNodeGetNextNode(DSLinkedListNode *node);

extern
void DSLinkedListNodeSetNextNode(DSLinkedListNode *node, DSLinkedListNode *nextNode);

extern
DSObject *DSLinkedListNodeGetObject(DSLinkedListNode *node);

extern
void DSLinkedListNodeSetObject(DSLinkedListNode *node, void *object);


#endif /* defined(__DSHomeWork__DSLinkedListNode__) */
