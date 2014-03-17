#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

typedef struct {
	char *rawString;
	int startIndex;
	int length;
} String;

//Will be update when discuss with bing xuan group.
typedef enum {INVALID_INDENTIFIER,UNKNOWN_OPERATOR} Error;

typedef struct{
	char *rawString;
	char *message;
	int position;
}ErrorMessage;

String *subString;
ErrorMessage *errorMessage;

// Function Prototype
String *stringCreate(char *expression) ;
void stringCopy(char *source, char*destination, int startLocation, int length);

void stringLeftTrim(String* string);
void stringRightTrim(String *string);

String *getWordAndUpdate(String *line, char *delimiter);

#endif // __STRING_OBJECT_H__
