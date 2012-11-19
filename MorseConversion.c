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
const char* morse_table[26] = {
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
    "._.",          //R
    "...",          //S
    "-",            //T
    "..-",          //U
    "...-",         //V
    ".--",          //W
    "-..-",         //X
    "-.--",         //Y
    "--.."          //Z
};

void print_latin_in_morse(char *sentance)
{
    while(*sentance)
    {
        if(*sentance == ' ')
        {
            printf("%c",'\t');
        }
        else
        {
            printf("%s%c", latin_to_morse(*sentance), ' ');
        }
        
        sentance++;
    }
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
        if (strcmp(word, morse_table[i]))
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
