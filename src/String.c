#include "String.h"

void stringLeftTrim(String *string) {
	while(string->rawString[string->startIndex] == ' ' || string->rawString[string->startIndex] == '\t' ) {
		string->startIndex++;
		string->length--;
	}
}

void stringRightTrim(String *string) {
	while(string->rawString[string->length - 1] == ' ' || string->rawString[string->length - 1] == '\t') {
		string->length--;
	}
}