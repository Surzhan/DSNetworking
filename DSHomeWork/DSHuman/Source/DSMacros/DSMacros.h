//
//  DSMacros.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 02.06.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef DSHomeWork_DSMacros_h
#define DSHomeWork_DSMacros_h

#define performTest(testFunction) \
    printf("- %s - Started...\n", #testFunction); \
    testFunction(); \
    printf("- %s - Finished.\n\n", #testFunction); \

#define DSObjectGetter(object, _iVar) \
    return NULL != object ? object->_iVar : NULL;

#define DSObjectGetterSimpleTypes(object, _iVar) \
    return NULL != object ? object->_iVar : 0;

#define DSObjectAssignSetter(object, ivar, newIvar) \
    if(NULL != object) { \
    object->ivar = newIvar; \
}

#define DSObjectRetainSetter(object, _iVar, data) \
    if (NULL != object && object != (void*)data && data != object->_iVar) { \
        DSObjectRetain(data); \
        DSObjectRelease(object->_iVar); \
        object->_iVar = data; \
}

#endif
