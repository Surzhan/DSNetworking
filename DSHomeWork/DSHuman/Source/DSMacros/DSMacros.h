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
do { \
_DSPrintTestHeader(); \
printf(" %s started...\n", #testFunction); \
testFunction(); \
_DSPrintTestFooter(); \
printf(" %s finished.\n", #testFunction); \
} while(0)


#endif
