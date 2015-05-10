//
//  main.c
//  DSHomeWork
//
//  Created by Denis Surzhan on 06.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#include <stdio.h>

#include "DSPrintSizeOfType.h"
#include "DSParentsSelect.h"
#include "DSParentsOutput.h"


int main(int argc, const char * argv[]) {
    DSSyzeOfTypeOutput(); // output size of type with sizeof
    printf ("\nEnd of the fist task\n\n");
    DSParentsOutputTest();
    printf ("\nEnd of the second task");
    
    return 0;
}
