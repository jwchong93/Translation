#include "String.h"

char *stringLeftTrim(String str) {
	char *newString;
	int i;
	
	for(i = str.startIndex; i < str.length; i ++) {
		*newString = str.rawString[i];
		
		str.rawString++;
		newString++;
	}
	
	*newString = 0;
	
	return newString;
}