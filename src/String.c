#include "String.h"
#include <stdio.h>
#include <malloc.h>

String *subString;

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
 * Divide string into words by 'space' or 'tab'
 *
 * Input:
 *	string	line of string
 *
 * Return:
 *	list	array of String structure which contains divided string info
 *  
 * not yet fully developed!!!
 *
 * stringCopy might be used to copy a word from a string with parsing startIndex and length to it
*/
String *chopLineIntoWords(String line) {
	String *list = malloc(sizeof(String));
	int word = 0;
	int i = 0;
	
	for(i = line.startIndex, list[word].startIndex = 0, list[word].length = 0; i < line.length; i++) {
		if (line.rawString[i] == ' ' || line.rawString[i] == '\t') {
			word++;
			list[word].startIndex = i;
			list[word].length = 0;
			list[word].startIndex++;
		} else {
			list[word].length++;
		}
	}
	
	return list;
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
	word->startIndex = 0;
	
	for(i = line->startIndex; i < line->length; i++) {
		if(line->rawString[i] != ' ') {
			word->rawString[i] = line->rawString[i];
			line->startIndex++;
			word->length++;
		} else {
			break;
		}
	}
	
	line->length = line->length - i;
	
	return word;
}