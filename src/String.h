#ifndef __STRING_H__
#define __STRING_H__

typedef struct {
	char *rawString;
	int startIndex;
	int length;
} String;

// Function Prototype
void stringLeftTrim(String* string);
void stringRightTrim(String *string);

String *chopString(String string);


#endif // __STRING_H__
