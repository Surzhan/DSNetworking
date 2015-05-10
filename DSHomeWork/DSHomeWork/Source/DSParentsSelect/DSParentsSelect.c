//
//  DSParentsSelect.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 06.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include "DSParentsSelect.h"

#pragma mark -
#pragma Public Declaration

static int  kDSMotherIfDivider = 3,
            kDSFatherIfDivider = 5,
            kDSMotherFatherIfDivider = 15;

int result;



#pragma mark -
#pragma Public Implementations


#pragma mark -
#pragma Private Implementations

extern
int DSChekMotherFother(value) {
    result = DSParentUndefined;
    if (0 == value) {
        printf("%d \n", value);
        result = DSParentUndefined;
        return result;}
    if (0 == value % kDSMotherFatherIfDivider) {
        printf("%d MotherFather\n", value);
        int result = DSMother;
        return result;
    } else {
        if (0 == value % kDSFatherIfDivider) {
            printf("%d Father\n", value);
            result = DSFather;
            return result;
        } else {
            if (0 == value % kDSMotherIfDivider) {
                printf("%d Mother\n", value);
                result = DSMotherFather;
                return result;
            } else {
                printf("%d \n", value);
                result = DSParentUndefined;
                return result;
            }
        }
    }
    
   return result;
}


