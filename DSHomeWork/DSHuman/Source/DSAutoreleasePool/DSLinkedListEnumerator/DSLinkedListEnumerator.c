//
//  DSLinkedListEnumerator.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//
#include <assert.h>

#include "DSLinkedListEnumeratorPrivate.h"
#include "DSLinkedListPrivate.h"
#include "DSMacros.h"

#pragma mark -
#pragma mark Private Declaration

static
void DSLinkedListEnumeratorSetValid(DSLinkedListEnumerator *enumerator, bool valid);

static
void DSLinkedListEnumeratorSetList(DSLinkedListEnumerator *enumerator, DSLinkedList *list);

static
DSLinkedList *DSLinkedListEnumeratorGetList(DSLinkedListEnumerator *enumerator);

static
void DSLinkedListEnumeratorSetNode(DSLinkedListEnumerator *enumerator, DSLinkedListNode *node);

static
void DSLinkedListEnumeratorSetMutationsCount(DSLinkedListEnumerator *enumerator, uint64_t mutationsCount);

static
uint64_t DSLinkedListEnumeratorGetMutationsCount(DSLinkedListEnumerator *enumerator);

static
bool DSLinkedListEnumeratorMutationsValidate(DSLinkedListEnumerator *enumerator);

#pragma mark -
#pragma mark Pablic Implementation

DSLinkedListEnumerator *DSLinkedListEnumeratorCreateWithList(DSLinkedList *list) {
    if (NULL == list || NULL == DSLinkedListGetHead(list)) {
        
        return NULL;
    }
    DSLinkedListEnumerator *enumerator = DSObjectCreateOfType(DSLinkedListEnumerator);
    DSLinkedListEnumeratorSetList(enumerator, list);
    DSLinkedListEnumeratorSetMutationsCount(enumerator, DSLinkedListGetMutationsCount(list));
    DSLinkedListEnumeratorSetValid(enumerator, true);
    
    return enumerator;
}

void __DSLinkedListEnumeratorDeallocate(void *object) {
    DSLinkedListEnumeratorSetNode(object, NULL);
    DSLinkedListEnumeratorSetList(object, NULL);
    
    __DSObjectDeallocate(object);
}

void *DSLinkedListEnumeratorGetNextObject(DSLinkedListEnumerator *enumerator) {
    if (NULL == enumerator || false == DSLinkedListEnumeratorMutationsValidate(enumerator)) {
        return NULL;
    }
    DSLinkedListEnumeratorIsValid(enumerator);
    DSLinkedListNode *node = DSLinkedListEnumeratorGetNode(enumerator);
    DSLinkedList *list = DSLinkedListEnumeratorGetList(enumerator);
    if (NULL != node) {
        node = DSLinkedListNodeGetNextNode(node);
    } else {
        node = DSLinkedListGetHead(list);
    }
    DSLinkedListEnumeratorSetNode(enumerator, node);
            
    if (NULL == node) {
        DSLinkedListEnumeratorSetValid(enumerator, false);
    }
            
    return DSLinkedListNodeGetObject(node);
}

bool DSLinkedListEnumeratorIsValid(DSLinkedListEnumerator *enumerator) {
    if (NULL != enumerator) {
        DSLinkedList *list = DSLinkedListEnumeratorGetList(enumerator);
        assert(DSLinkedListEnumeratorGetMutationsCount(enumerator) == DSLinkedListGetMutationsCount(list));
        
        return true;
    }
    
    return false;
}

#pragma mark -
#pragma mark Private Implementations

void DSLinkedListEnumeratorSetValid(DSLinkedListEnumerator *enumerator, bool valid) {
    DSObjectAssignSetter(enumerator, _valid, valid);
}

void DSLinkedListEnumeratorSetList(DSLinkedListEnumerator *enumerator, DSLinkedList *list) {
    DSObjectRetainSetter(enumerator, _list, list);
}

DSLinkedList *DSLinkedListEnumeratorGetList(DSLinkedListEnumerator *enumerator) {
    DSObjectGetter(enumerator, _list);
}

void DSLinkedListEnumeratorSetNode(DSLinkedListEnumerator *enumerator, DSLinkedListNode *node) {
    DSObjectRetainSetter(enumerator, _node, node);
}

void DSLinkedListEnumeratorSetMutationsCount(DSLinkedListEnumerator *enumerator, uint64_t mutationsCount) {
    DSObjectAssignSetter(enumerator, _mutationsCount, mutationsCount);
}

uint64_t DSLinkedListEnumeratorGetMutationsCount(DSLinkedListEnumerator *enumerator) {
    DSObjectGetterSimpleTypes(enumerator, _mutationsCount);
}

bool DSLinkedListEnumeratorMutationsValidate(DSLinkedListEnumerator *enumerator) {
    return NULL != enumerator && enumerator->_valid;
}

#pragma mark -
#pragma mark Private Implementations (Private Header)

DSLinkedListNode *DSLinkedListEnumeratorGetNode(DSLinkedListEnumerator *enumerator) {
    DSObjectGetter(enumerator, _node);
}
