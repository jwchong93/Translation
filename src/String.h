#ifndef __STRING_H__
#define __STRING_H__

typedef struct {
	char *rawString;
	int startIndex;
	int length;
} String;

extern String *subString;

// Function Prototype
void stringLeftTrim(String* string);
void stringRightTrim(String *string);

String *chopLineIntoWords(String line);
String *getWordAndUpdate(String *line, char *delimiter);

#endif // __STRING_H__
