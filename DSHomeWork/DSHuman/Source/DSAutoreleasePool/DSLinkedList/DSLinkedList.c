//
//  DSLinkedList.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//
#include <string.h>

#include "DSLinkedListPrivate.h"
#include "DSLinkedListEnumeratorPrivate.h"
#include "DSMacros.h"

#pragma mark -
#pragma mark Private Declaration

static
void DSLinkedListSetCount(DSLinkedList *list, uint64_t count);

static
void DSLinkedListMutate(DSLinkedList *list);

#pragma mark -
#pragma mark Pablic Implementation

DSLinkedList *DSLinkedListCreate(void) {
    return DSObjectCreateOfType(DSLinkedList);
}

void __DSLinkedListDeallocate(void *object) {
    DSLinkedListRemoveAllObjects(object);
    
    __DSObjectDeallocate(object);
}

DSObject *DSLinkedListGetFirstObject(DSLinkedList *list) {
    return DSLinkedListNodeGetObject(DSLinkedListGetHead(list));
}

void DSLinkedListRemoveFirstObject(DSLinkedList *list) {
    if (NULL != list && false == DSLinkedListIsEmpty(list)) {
        DSLinkedListNode *node =  DSLinkedListGetHead(list);
        
        DSLinkedListSetHead(list, DSLinkedListNodeGetNextNode(node));
        DSLinkedListSetCount(list, DSLinkedListGetCount(list) - 1);
    }
}

DSObject *DSLinkedListGetObjectBeforeObject(DSLinkedList *list, DSObject *object) {
    DSLinkedListNodeContext context = DSLinkedListNodeGetContextForListWithObject(list, object);
    
    return NULL != context.object ? DSLinkedListNodeGetObject(context.previousNode) : NULL;
}

bool DSLinkedListIsEmpty(DSLinkedList *list) {
  return (NULL != list) && (0 == list->_count);  
}

void DSLinkedListAddObject(DSLinkedList *list, void *object) {
    if (NULL != list && NULL != object) {
        DSLinkedListNode *newNode = DSLinkedListNodeCreateWithObject(object);
        
        DSLinkedListNodeSetNextNode(newNode, DSLinkedListGetHead(list));
        DSLinkedListSetHead(list, newNode);
        DSLinkedListSetCount(list, DSLinkedListGetCount(list) + 1);
        
        DSObjectRelease(newNode);
    }
}

void DSLinkedListRemoveObject(DSLinkedList *list, void *object) {
    DSLinkedListNode *node;
    DSLinkedListNodeContext context = DSLinkedListNodeGetContextForListWithObject(list, object);
    while (NULL != (node = DSLinkedListFindNodeWithContext(list,
                                                            DSLinkedListNodeContainsObject,
                                                            &context)))
    {
        if (NULL != node) {
            DSLinkedListNodeSetNextNode(context.previousNode, DSLinkedListNodeGetNextNode(context.node));
            DSLinkedListSetCount(list, DSLinkedListGetCount(list) - 1);
        }
    }

}

void DSLinkedListRemoveAllObjects(DSLinkedList *list) {
    if (NULL != list) {
        DSLinkedListSetHead(list, NULL);
        DSLinkedListSetCount(list, 0);
    }
}

bool DSLinkedListContainsObject(DSLinkedList *list, void *object) {
    bool result = false;
    if (NULL != list) {
        DSLinkedListNodeContext context = DSLinkedListNodeGetContextForListWithObject(list, object);
        result = NULL != context.node;
    }
    
    return result;
}

uint64_t DSLinkedListGetCount(DSLinkedList *list) {
    DSObjectGetterSimpleTypes(list, _count);
}

#pragma mark -
#pragma mark Private Implementations

void DSLinkedListSetCount(DSLinkedList *list, uint64_t count) {
    if (NULL != list) {
        if (0 == count) {
            DSLinkedListSetHead(list, NULL);
        }
        
        list->_count = count;
        DSLinkedListMutate(list);
    }
}

void DSLinkedListMutate(DSLinkedList *list) {
     DSLinkedListSetMutationsCount(list, DSLinkedListGetMutationsCount(list) + 1);
}

#pragma mark -
#pragma mark Private Implementations (Private Header)

void DSLinkedListSetHead(DSLinkedList *list, DSLinkedListNode *node) {
    DSObjectRetainSetter(list, _head, node);
}

DSLinkedListNode *DSLinkedListGetHead(DSLinkedList *list) {
    DSObjectGetter(list, _head);
}

void DSLinkedListSetMutationsCount(DSLinkedList *list, uint64_t count) {
    DSObjectAssignSetter(list, _mutationCount, count);
}

uint64_t DSLinkedListGetMutationsCount(DSLinkedList *list) {
    DSObjectGetterSimpleTypes(list, _mutationCount);
}

DSLinkedListNode *DSLinkedListFindNodeWithContext(DSLinkedList *list,
                                                  DSLinkedListNodeComparisonFunction comparator,
                                                  DSLinkedListNodeContext *context)
{
    DSLinkedListNode *result = NULL;
    if (NULL != list) {
        DSLinkedListEnumerator *enumerator = DSLinkedListEnumeratorCreateWithList(list);
        
        while (true == DSLinkedListEnumeratorIsValid(enumerator)
               && (NULL != DSLinkedListEnumeratorGetNextObject(enumerator)))
        {
            DSLinkedListNode *node = DSLinkedListEnumeratorGetNode(enumerator);
            
            context->node = node;
            
            if (true == DSLinkedListNodeContainsObject(node, *context)) {
                result = node;
                break;
            }
            
            context->previousNode = node;
        }
        
        DSObjectRelease(enumerator);
    }
    
    return result;
}

bool DSLinkedListNodeContainsObject(DSLinkedListNode *node, DSLinkedListNodeContext context) {
    return (NULL != node) && (context.object == DSLinkedListNodeGetObject(node));
}

DSLinkedListNodeContext DSLinkedListNodeGetContextForListWithObject(DSLinkedList *list, void *object) {
    DSLinkedListNodeContext context;
    memset(&context, 0, sizeof(context));
    context.object = object;
    if (NULL != list) {
        context.node = DSLinkedListFindNodeWithContext(list, DSLinkedListNodeContainsObject, &context);
    }
    
    return context;
}
