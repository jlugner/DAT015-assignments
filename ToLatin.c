//
//  ToLatin.c
//  MOP.Assignments
//
//  Created by Jesper Persson on 2012-11-19.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//

#include "MorseConversion.h"
#include <stdio.h>

int main(int argc, const char * argv[])
{
     
    char input[150];
    fgets(input, 150, stdin);
    char *input_Iterator = input;
    
    char converted [75];
    char *converted_Iterator = converted;
    
    char tmp [5];
    int i = 0;
    
    while (*input_Iterator)
    {
        if (*input_Iterator == ' ' || *input_Iterator == '\t' || *input_Iterator == '\n')
        {
            tmp[i] = 0;
            *converted_Iterator = morse_to_latin(tmp);
            converted_Iterator++;
            i = 0;
            
            if (*input_Iterator == '\t')
            {
                *converted_Iterator = ' ';
                converted_Iterator++;
            }
        }
        else
        {
            tmp[i] = *input_Iterator;
            ++i;
        }
        
        input_Iterator++;
    }
    
    printf("%s", converted);
    
}