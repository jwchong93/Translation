#ifndef __STRING_H__
#define __STRING_H__

typedef struct {
	char *rawString;
	int startIndex;
	int length;
} String;

void stringLeftTrim(String* string);
void stringRightTrim(String *string);

#endif // __STRING_H__
