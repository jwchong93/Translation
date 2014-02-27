#include "String.h"

void stringLeftTrim(String *string) {
	while(*(string->rawString) == ' ') {
		string->rawString++;
		string->startIndex++;
		string->length--;
	}
}