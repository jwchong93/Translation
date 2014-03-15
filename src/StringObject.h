#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

typedef struct {
	char *rawString;
	int startIndex;
	int length;
} String;

extern String *subString;

// Function Prototype
String *stringCreate(char *string);

void stringLeftTrim(String* string);
void stringRightTrim(String *string);

String *chopLineIntoWords(String line);
String *getWordAndUpdate(String *line, char *delimiter);

#endif // __STRING_OBJECT_H__
