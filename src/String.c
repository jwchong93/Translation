#include "String.h"
#include <stdio.h>
#include <malloc.h>

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
String *chopString(String string) {
	String *list = malloc(sizeof(String));
	int word = 0;
	int i = 0;
	
	for(i = string.startIndex, list[word].startIndex = 0, list[word].length = 0; i < string.length; i++) {
		if (string.rawString[i] == ' ' || string.rawString[i] == '\t') {
			word++;
			list[word].startIndex = i;
			list[word].length = 0;
			list[word].startIndex++;
		} else {
			list[word].length++;
		}
	}
	
	// only startIndex and length are modified
	// display result, will be deleted later on
	printf("First Word: Start Index: %d, Length: %d\n", list[0].startIndex, list[0].length);
	printf("Second Word: Start Index: %d, Length: %d\n", list[1].startIndex, list[1].length);
	printf("Third Word: Start Index: %d, Length: %d\n", list[2].startIndex, list[2].length);
	
	return list;
}