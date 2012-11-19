//
//  MorseCode.c
//  MOP.Assignments
//
//  Created by Jesper Persson on 2012-11-15.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "MorseConversion.h"


int main(int argc, const char * argv[])
{
    char input[75];
    fgets(input, 75, stdin);
   
    print_latin_in_morse(input);
    
    return 0;
}



