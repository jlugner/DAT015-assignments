//
//  MorseConversion.c
//  MOP.Assignments
//
//  Created by Jesper Persson on 2012-11-19.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//

#include <stdio.h>
#include "MorseConversion.h"
#include <string.h>

const int TABLE_LENGTH = 26;
char* morse_table[26] = {
    ".-",           //A
    "-...",         //B
    "-.-.",         //C
    "-..",          //D
    ".",            //E
    "..-.",         //F
    "--.",          //G
    "....",         //H
    "..",           //I
    ".---",         //J
    "-.-",          //K
    ".-..",         //L
    "--",           //M
    "-.",           //N
    "---",          //O
    ".--.",         //P
    "--.-",         //Q
    ".-.",          //R
    "...",          //S
    "-",            //T
    "..-",          //U
    "...-",         //V
    ".--",          //W
    "-..-",         //X
    "-.--",         //Y
    "--.."          //Z
};

void print_latin_in_morse(char *sentence)
{
    while(*sentence)
    {
        if(*sentence == ' ')
        {
            printf("%c",'\t');
        }
        else if (*sentence != '\n')
        {
            printf("%s%c", latin_to_morse(*sentence), ' ');
        }
        
        sentence++;
    }
}

void print_morse_in_latin(char sentence[])
{
    
}


int index_of_char(char character)
{
    if (character >= 'A' && character <= 'Z')
    {
        return character - 'A';
    }
    else if (character >= 'a' && character <= 'z')
    {
        return character - 'a';
    }
    
    return -1;
}

int index_of_morse( char *word)
{
    for (int i = 0; i < TABLE_LENGTH; i++)
    {
        if (!strcmp(word, morse_table[i]))
        {
            return i;
        }
    }
    
    return -1;
}

char* latin_to_morse(char character)
{
    int index = index_of_char(character);
    return index == -1 ? "" : morse_table[index];
}

char morse_to_latin(char *letter)
{
    int index = index_of_morse(letter);
    return index == -1 ? '?' : 'a' + index;
}

void test_print_morse_in_latin()
{
    for (int i = 0; i < TABLE_LENGTH; i++){
        printf("%s%c%s", morse_table[i], morse_to_latin(morse_table[i]), "\n");
    }
}
