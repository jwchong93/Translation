#include "unity.h"
#include "String.h"
#include <stdio.h>
#include <malloc.h>

void setUp() {}
void tearDown() {}

void test_stringLeftTrim_should_trim_string_with_one_left_space() {
	// Test fixture
	String string = {" m", 0, 2};
	int index = 0;
	
	//printf("Raw String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
	
	// Execute subject under test
	stringLeftTrim(&string);
	
	//printf("Trimmed String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
		
	// Test the behavior or states
	TEST_ASSERT_EQUAL(1, string.startIndex);
	TEST_ASSERT_EQUAL(1, string.length);
	TEST_ASSERT_EQUAL('m', string.rawString[string.startIndex]);
}

void test_stringLeftTrim_should_trim_string_with_left_spaces() {
	// Test fixture
	String string = {"   movlw", 0, 8};
	int index = 0;
	
	//printf("Raw String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
	
	// Execute subject under test
	stringLeftTrim(&string);
	
	//printf("Trimmed String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
		
	// Test the behavior or states
	TEST_ASSERT_EQUAL(3, string.startIndex);
	TEST_ASSERT_EQUAL(5, string.length);
	TEST_ASSERT_EQUAL('m', string.rawString[string.startIndex]);
	TEST_ASSERT_EQUAL('o', string.rawString[string.startIndex + 1]);
	TEST_ASSERT_EQUAL('v', string.rawString[string.startIndex + 2]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 3]);
	TEST_ASSERT_EQUAL('w', string.rawString[string.startIndex + 4]);
}

void test_stringLeftTrim_should_trim_string_with_left_tab() {
	// Test fixture
	String string = {"\thello", 0, 6};
	int index = 0;
	
	//printf("Raw String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
	
	// Execute subject under test
	stringLeftTrim(&string);
	
	//printf("Trimmed String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
		
	// Test the behavior or states
	TEST_ASSERT_EQUAL(1, string.startIndex);
	TEST_ASSERT_EQUAL(5, string.length);
	TEST_ASSERT_EQUAL('h', string.rawString[string.startIndex]);
	TEST_ASSERT_EQUAL('e', string.rawString[string.startIndex + 1]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 2]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 3]);
	TEST_ASSERT_EQUAL('o', string.rawString[string.startIndex + 4]);
}

void test_stringRightTrim_should_trim_string_with_one_right_space() {
	// Test fixture
	String string = {"hello ", 0, 6};
	int index = 0;
	
	//printf("Raw String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
	
	// Execute subject under test
	stringRightTrim(&string);
	
	//printf("Trimmed String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
		
	// Test the behavior or states
	TEST_ASSERT_EQUAL(0, string.startIndex);
	TEST_ASSERT_EQUAL(5, string.length);
	TEST_ASSERT_EQUAL('h', string.rawString[string.startIndex]);
	TEST_ASSERT_EQUAL('e', string.rawString[string.startIndex + 1]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 2]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 3]);
	TEST_ASSERT_EQUAL('o', string.rawString[string.startIndex + 4]);
}

void test_stringRightTrim_should_trim_string_with_right_spaces() {
	// Test fixture
	String string = {"hello   ", 0, 8};
	int index = 0;
	
	//printf("Raw String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
	
	// Execute subject under test
	stringRightTrim(&string);
	
	//printf("Trimmed String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
		
	// Test the behavior or states
	TEST_ASSERT_EQUAL(0, string.startIndex);
	TEST_ASSERT_EQUAL(5, string.length);
	TEST_ASSERT_EQUAL('h', string.rawString[string.startIndex]);
	TEST_ASSERT_EQUAL('e', string.rawString[string.startIndex + 1]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 2]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 3]);
	TEST_ASSERT_EQUAL('o', string.rawString[string.startIndex + 4]);
}

void test_stringRightTrim_should_trim_string_with_right_tab() {
	// Test fixture
	String string = {"hello\t", 0, 6};
	int index = 0;
	
	//printf("Raw String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
	
	// Execute subject under test
	stringRightTrim(&string);
	
	//printf("Trimmed String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
		
	// Test the behavior or states
	TEST_ASSERT_EQUAL(0, string.startIndex);
	TEST_ASSERT_EQUAL(5, string.length);
	TEST_ASSERT_EQUAL('h', string.rawString[string.startIndex]);
	TEST_ASSERT_EQUAL('e', string.rawString[string.startIndex + 1]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 2]);
	TEST_ASSERT_EQUAL('l', string.rawString[string.startIndex + 3]);
	TEST_ASSERT_EQUAL('o', string.rawString[string.startIndex + 4]);
}

void test_chopLineIntoWords_should_chop_data_and_return_startIndex_and_length_for_each_of_them() {
	String oneLineString = {"#define MAX 10", 0, 14};
	// startIndex			 ^      ^   ^
	//						[0]	   [8] [12]
	
	String *choppedString = {0};
	
	choppedString = chopLineIntoWords(oneLineString);
	
	// First word
	TEST_ASSERT_EQUAL(0, choppedString[0].startIndex);
	TEST_ASSERT_EQUAL(7, choppedString[0].length);	
	
	// Second word
	TEST_ASSERT_EQUAL(8, choppedString[1].startIndex);
	TEST_ASSERT_EQUAL(3, choppedString[1].length);

	// Third word
	TEST_ASSERT_EQUAL(12, choppedString[2].startIndex);
	TEST_ASSERT_EQUAL(2, choppedString[2].length);
	
	free(choppedString);
}

void test_getWordAndUpdate_should_get_the_first_word_from_a_line_of_instruction() {
	String oneLineString = {.rawString = "movwf 0x10", .startIndex = 0, .length = 10};

	subString = getWordAndUpdate(&oneLineString, " ,;");
		
	TEST_ASSERT_EQUAL('m', subString->rawString[0]);
	TEST_ASSERT_EQUAL('o', subString->rawString[1]);
	TEST_ASSERT_EQUAL('v', subString->rawString[2]);
	TEST_ASSERT_EQUAL('w', subString->rawString[3]);
	TEST_ASSERT_EQUAL('f', subString->rawString[4]);
	TEST_ASSERT_NOT_EQUAL(' ', subString->rawString[5]);
	TEST_ASSERT_NOT_EQUAL('0', subString->rawString[6]);
	TEST_ASSERT_NOT_EQUAL('x', subString->rawString[7]);
	TEST_ASSERT_NOT_EQUAL('1', subString->rawString[8]);
	TEST_ASSERT_NOT_EQUAL('0', subString->rawString[9]);
	
	TEST_ASSERT_EQUAL(5, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(5, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(5, subString->length);
}




