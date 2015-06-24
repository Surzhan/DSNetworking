//
//  DSLinkedListNode.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <assert.h>

#include "DSLinkedListNode.h"
#include "DSMacros.h"

#pragma mark -
#pragma Pablic Implementation

DSLinkedListNode *DSLinkedListNodeCreateWithObject(void *object) {
    DSLinkedListNode *node = DSObjectCreateOfType(DSLinkedListNode);
    DSLinkedListNodeSetObject(node, object);
    
    return node;
}

void __DSLinkedListNodeDeallocate(void *node) {
    DSLinkedListNodeSetObject(node, NULL);
    DSLinkedListNodeSetNextNode(node, NULL);
    __DSObjectDeallocate(node);
}

DSLinkedListNode *DSLinkedListNodeGetNextNode(DSLinkedListNode *node) {
    DSObjectGetter(node, _nextNode);
}

void DSLinkedListNodeSetNextNode(DSLinkedListNode *node, DSLinkedListNode *nextNode) {
    DSObjectRetainSetter(node, _nextNode, nextNode);
}

DSObject *DSLinkedListNodeGetObject(DSLinkedListNode *node) {
    DSObjectGetter(node, _object);
}

void DSLinkedListNodeSetObject(DSLinkedListNode *node, void *object) {
    assert(node != object);
    DSObjectRetainSetter(node, _object, object);
}
