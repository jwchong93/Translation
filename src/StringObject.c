#include "StringObject.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

String *subString;

/**
 * Create a string object
 *
 * Input:
 * 	string			char string that will create into stringObject
 * 
 * Return:
 * 	stringObject	pointer of the string object created
 */
String *stringCreate(char *string) {
	String *stringObject = malloc(sizeof(String));
	
	stringObject->rawString = string;
	stringObject->startIndex = 0;
	stringObject->length = strlen(string);
	
	return stringObject;
}

/**
 * Trim out the left space/tab of string
 *
 * Input:
 *	string	word or line of string
 */
void stringLeftTrim(String *string) {
	while(string->rawString[string->startIndex] == ' ' || string->rawString[string->startIndex] == '\t' ) {
		string->startIndex++;
		string->length--;
	}
}

/**
 * Trim out the right space/tab of string
 *
 * Input:
 *	string	word or line of string
 */
void stringRightTrim(String *string) {
	while(string->rawString[string->length - 1] == ' ' || string->rawString[string->length - 1] == '\t') {
		string->length--;
	}
}

/**
 * Get word from a line according to delimiters and update the status of the line (startIndex and length)
 *
 * Input:
 *	line		A line of string
 *	delimiter	Symbol to separate words
 *
 * Return:
 *	word		First word from a line
 */
String *getWordAndUpdate(String *line, char *delimiter) {
	String *word = malloc(sizeof(String));
	int i;

	stringLeftTrim(line);

	word->length = 0;
	word->startIndex = line->startIndex;
	
	for(i = 0; i < line->length; i++) {
		if(line->rawString[i] != *delimiter) {
			line->startIndex++;
			word->length++;
		} else {
			break;
		}
	}
	
	line->length = line->length - i;
	
	return word;
}