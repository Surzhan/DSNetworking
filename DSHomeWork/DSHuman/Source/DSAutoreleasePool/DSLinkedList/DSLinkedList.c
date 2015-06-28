//
//  DSLinkedList.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 23.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include "DSLinkedListPrivate.h"
#include "DSLinkedListNode.h"
#include "DSLinkedListEnumerator.h"
#include "DSMacros.h"

#pragma mark -
#pragma mark Private Declaration

static
void DSLinkedListSetCount(DSLinkedList *list, uint64_t count);


#pragma mark -
#pragma Pablic Implementation

DSLinkedList *DSLinkedListCreate(void) {
    return DSObjectCreateOfType(DSLinkedList);
}

void __DSLinkedListDeallocate(void *object) {
    __DSObjectDeallocate(object);
}

DSObject *DSLinkedListGetFirstObject(DSLinkedList *list) {
    return DSLinkedListNodeGetObject(DSLinkedListGetHead(list));
}

//void DSLinkedListRemoveFirstObject(DSLinkedList *list) {
//    
//}
//
//DSObject *DSLinkedListGetObjectBeforeObject(DSLinkedList *list, DSObject *object) {
//    
//}
//
//bool DSLinkedListIsEmpty(DSLinkedList *list) {
//    
//}
//
//void DSLinkedListAddObject(DSLinkedList *list, void *object) {
//    
//}
//
//void DSLinkedListRemoveObject(DSLinkedList *list, void *object) {
//    
//}
//
//void DSLinkedListRemoveAllObjects(DSLinkedList *list) {
//    
//}
//
//bool DSLinkedListContainsObject(DSLinkedList *list, void *object) {
//    
//}
//
//uint64_t DSLinkedListGetCount(DSLinkedList *list) {
//    
//}
//
#pragma mark -
#pragma mark Private Implementations

//void DSLinkedListSetCount(DSLinkedList *list, uint64_t count) {
//    
//}

//DSLinkedListSetHead(DSLinkedList *list, DSLinkedListNode *head) {
//    
//}

DSLinkedListNode *DSLinkedListGetHead(DSLinkedList *list) {
    DSObjectGetter(list, _head);
}

//void DSLinkedListSetMutationsCount(DSLinkedList *list, uint64_t count) {
//    
//}

//uint64_t DSLinkedListGetMutationsCount(DSLinkedList *list) {
//    
//}

//DSLinkedListNode *DSLinkedListFindNodeWithContext(DSLinkedList *list,
//                                                  DSLinkedListNodeComparisonFunction comparator,
//                                                  DSLinkedListNodeContext *context) {
//    
//}
//
//bool DSLinkedListNodeContainsObject(DSLinkedListNode *node, DSLinkedListNodeContext context) {
//    
//}
