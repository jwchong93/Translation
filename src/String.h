#ifndef __STRING_H__
#define __STRING_H__

typedef struct {
	char *rawString;
	int startIndex;
	int length;
} String;

char *stringLeftTrim(String str);

#endif // __STRING_H__
