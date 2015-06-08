//
//  DSString.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 26.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSString__
#define __DSHomeWork__DSString__

#include <stdio.h>
#include <stdbool.h>

#include "DSObject.h"


typedef struct {
    DSObject _super;
    
    char *_string;
    uint64_t _length;
}DSString;


extern
DSString *DSStringCreate(void);

extern
char *DSStringGetString(DSString *string);

extern
void DSStringSetString(void *string, char *newString);

extern
uint64_t DSStringGetLength(DSString *string);

extern
void __DSStringDeallocate(void *string);


#endif /* defined(__DSHomeWork__DSString__) */
