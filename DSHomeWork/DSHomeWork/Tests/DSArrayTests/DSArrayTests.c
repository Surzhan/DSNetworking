//
//  DSArrayTests.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 26.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <assert.h>

#include "DSArrayTests.h"
#include "DSArray.h"
#include "DSHuman.h"

static
void DSArrayOneObjectBehaviorTest(void);

static
void DSArrayMultipleObjectBehaviorTest(void);

#pragma mark -
#pragma mark Public

void DSArrayBehaviorTest() {
   DSArrayOneObjectBehaviorTest();
   DSArrayMultipleObjectBehaviorTest();
}

#pragma mark -
#pragma mark Private Implementations

void DSArrayOneObjectBehaviorTest(void) {
    //  after array was created
    DSArray *array = DSObjectCreateOfType(DSArray);
    
    //      array must not be NULL
    assert(NULL != array);
    
    //      array retain count must be equal 1
     assert(1 == DSObjectGetReferenceCount(array));
    
    //      array objects count muts be equal 0
     assert(0 == DSArrayGetCount(array));
    
    // after object was created
    DSHuman *newArray = DSHumanCreateWithParameters(kDSHumanMale);
    
    //      object must not be NULL
    assert(NULL != newArray);
    
    //      object reference count must be equal to 1
    assert(1 == DSObjectGetReferenceCount(newArray));
    
    //      object index in array must be invalid (object not found)
    
    // after object was added to array
    //      array count must be equal to 1
    //      array reference count must not change
    //      object index in array must be 0
    //      object reference count must be incremented by 1
    //      array object at index 0 must be equal to added object
    //      array must contain an object
    // after object was removed from array
    //      array count must be equal to 0
    //      array reference count must not change
    //      object index in array must be invalid (object not found)
    //      object reference count must be decremented by 1
    //      array must not contain an object
    
    DSObjectRelease(array);
}

void DSArrayMultipleObjectBehaviorTest(void) {
    //  after one origin object was added 5 times in array
    //      array count must be equal to 5
    //      objects at indices 0 - 4 must be equal to object
    //  after added another object2 (not equal to origin object)
    //      array count must be equal to 6
    //      objects at indices 0 - 4 must be equal to origin object
    //      added object2 must be at index 5
    // after object at index 3 was removed
    //      array count must be equal to 5
    //      objects at indices 0 - 3 must be equal to origin object
    //      added object2 must be at index 4
    // after removing all object from array
    //      array must be empty
    //      array must no contain origin object ang object2
}
