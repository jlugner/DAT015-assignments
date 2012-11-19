//
//  MorseConversion.h
//  MOP.Assignments
//
//  Created by Jesper Persson on 2012-11-19.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//

#ifndef MOP_Assignments_MorseConversion_h
#define MOP_Assignments_MorseConversion_h



//
// Given a character, will return the
// index of that character. Sorted alphabetically.
//
// Param - The char whose index is to be found.
// Return - Int index, the index of the character.
//
int index_of_char(char character);

//
// Given a char, will return the morse-code for
// that character.
//
// Param - the character
// Return - char*, the morse code for the character.
char* latin_to_morse(char character);

//
// Given a char array, will convert each
// letter to morse-code, and print it.
// Signs not found in the Latin alphabet
// will be ignored.
//
// Param - The char array to be printed
// Return - None.
void print_latin_in_morse(char sentance[] );

#endif
