//
//  MorseConversion.h
//  MOP.Assignments
//
//  Created by Jesper Persson on 2012-11-19.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//

#ifndef MOP_Assignments_MorseConversion_h
#define MOP_Assignments_MorseConversion_h



void print_latin_in_morse(char *sentance);

//
// Given a character, will return the
// index of that character. Sorted alphabetically.
//
// Param - The char whose index is to be found.
// Return - Int index, the index of the character.
//
int index_of_char(char character);

//
// Given the morse-code for a letter
// in the alphabet, the index of
// that letter will be returned. Should
// a invalid code be given as input, -1 will
// be returned.
//
// Param - The morse code for the letter
// Return - -1 if invalid input, else the index of the given letter
int index_of_morse ( char *word);

//
// Given a char, will return the morse-code for
// that character.
//
// Param - the character
// Return - char*, the morse code for the character.
char* latin_to_morse(char character);

//
// Given a morse-code representing a letter
// the char representing that letter
// will be returned.
//
// Param - The morse code for the letter
// Return - The character
char morse_to_latin(char *letter);

//
// Given a char array, will convert each
// letter to morse-code, and print it.
// Signs not found in the Latin alphabet
// will be ignored.
//
// Param - The char array to be printed
// Return - None.
void test_print_morse_in_latin();




#endif
