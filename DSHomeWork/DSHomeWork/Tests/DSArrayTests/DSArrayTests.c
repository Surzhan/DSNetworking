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
    assert(false == DSArrayContainsObject(array, newArray));
    
    // after object was added to array
    DSArrayAddObject(array, newArray);
    
    //      array count must be equal to 1
    assert(1 == DSArrayGetCount(array));

    //      array reference count must not change
     assert(1 == DSObjectGetReferenceCount(array));
    
    //      object index in array must be 0
    assert(0 == DSArrayGetIndexOfObject(array, newArray));
    
    //      object reference count must be incremented by 1
    assert(2 == DSObjectGetReferenceCount(newArray));
    
    //      array object at index 0 must be equal to added object
    assert(newArray == DSArrayGetObjectAtIndex(array, 0));
    
    //      array must contain an object
    assert(true == DSArrayContainsObject(array, newArray));
    
    // after object was removed from array
    DSArrayRemoveObjectAtIndex(array, 0);
    
    //      array count must be equal to 0
    assert(0 == DSArrayGetCount(array));
    
    //      array reference count must not change
    assert(1 == DSObjectGetReferenceCount(array));
    
    //      object index in array must be invalid (object not found)
     assert(-1 == DSArrayGetIndexOfObject(array, newArray));
    
    //      object reference count must be decremented by 1
     assert(1 == DSObjectGetReferenceCount(newArray));
    
    //      array must not contain an object
    assert(false == DSArrayContainsObject(array, newArray));
    
    DSObjectRelease(newArray);
    DSObjectRelease(array);
}

void DSArrayMultipleObjectBehaviorTest(void) {
    //  after one origin object was added 5 times in array
    DSArray *testArray = DSObjectCreateOfType(DSArray);
    DSHuman *human1 = DSHumanCreateWithParameters(kDSHumanFemale);
    
    //      array count must be equal to 5
    for (int iterator = 0; iterator < 5; iterator++) {
        DSArrayAddObject(testArray, human1);
    }
    
    //      objects at indices 0 - 4 must be equal to object
    assert(5 == DSArrayGetCount(testArray));
    
    //  after added another object2 (not equal to origin object)
    for (uint64_t iterator = 0; iterator < DSArrayGetCount(testArray); iterator++) {
        assert(human1 == DSArrayGetObjectAtIndex(testArray, iterator));
    }
    
    //  after added new object human2 (the new object not equal to previously placed in an array)
    DSHuman *human2 = DSHumanCreateWithParameters(kDSHumanMale);
    DSArrayAddObject(testArray, human2);
    
    //      array count must be equal to 6
    assert(6 == DSArrayGetCount(testArray));
    
    //      objects at indices 0 - 4 must be equal to origin object (human1)
    for (uint64_t iterator = 0; iterator < 5; iterator++) {
        assert(human1 == DSArrayGetObjectAtIndex(testArray, iterator));
    }
    
    //      added object human2 must be at index 5
    assert(5 == DSArrayGetIndexOfObject(testArray, human2));
    
    // after object at index 2 was removed
    DSArrayRemoveObjectAtIndex(testArray, 2);
    
    //      array count must be equal to 5
    assert(5 == DSArrayGetCount(testArray));
    
    //      objects at indices 0 - 3 must be equal to origin object
    for (uint64_t iterator = 0; iterator < 4; iterator++) {
        assert(human1 == DSArrayGetObjectAtIndex(testArray, iterator));
    }
    
    //      added object human2 must be at index 4
     assert(human2 == DSArrayGetObjectAtIndex(testArray, 4));
    
    // after removing all object from array
    DSArrayRemoveAllObjects(testArray);
    
    //      array must be empty
    assert(0 == DSArrayGetCount(testArray));
    
    //      array must no contain origin object (himan1) ang object2 (human2)
    assert(false == DSArrayContainsObject(testArray, human1));
    assert(false == DSArrayContainsObject(testArray, human2));
    
    DSObjectRelease(human1);
    DSObjectRelease(testArray);
}
