#include "unity.h"
#include "StringObject.h"
#include <stdio.h>
#include <malloc.h>

void setUp() {}
void tearDown() {}

void test_stringCreate_should_create_string_object() {
	String *string;
	
	string = stringCreate("h");
	
	TEST_ASSERT_NOT_NULL(string);
	TEST_ASSERT_EQUAL(0, string->startIndex);
	TEST_ASSERT_EQUAL(1, string->length);
	
	free(string);
}

void test_stringCreate_given_char_string_hello_should_create_string_object_hello_with_correct_start_index_and_length() {
	String *string;
	
	string = stringCreate("hello");
	
	TEST_ASSERT_NOT_NULL(string);
	TEST_ASSERT_EQUAL(0, string->startIndex);
	TEST_ASSERT_EQUAL(5, string->length);
	
	free(string);
}

void test_stringLeftTrim_should_trim_string_with_one_left_space() {
	// Test fixture
	String string = {" m", 0, 2};

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

void test_stringLeftTrim_should_do_nothing_on_a_null_string() {
	// Test fixture
	String string = {"", 0, 0};
	
	//printf("Raw String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
	
	// Execute subject under test
	stringLeftTrim(&string);
	
	//printf("Trimmed String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
		
	// Test the behavior or states
	TEST_ASSERT_EQUAL(0, string.startIndex);
	TEST_ASSERT_EQUAL(0, string.length);
	TEST_ASSERT_EQUAL(0, string.rawString[string.startIndex]);
}

void test_stringRightTrim_should_trim_string_with_one_right_space() {
	// Test fixture
	String string = {"hello ", 0, 6};
	
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

void test_stringRightTrim_should_do_nothing_on_a_null_string() {
	// Test fixture
	String string = {"", 0, 0};
	
	//printf("Raw String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
	
	// Execute subject under test
	stringLeftTrim(&string);
	
	//printf("Trimmed String: %s, Start Index: %d, Length: %d\n", string.rawString, string.startIndex, string.length);
		
	// Test the behavior or states
	TEST_ASSERT_EQUAL(0, string.startIndex);
	TEST_ASSERT_EQUAL(0, string.length);
	TEST_ASSERT_EQUAL(0, string.rawString[string.startIndex]);
}

void test_getWordAndUpdate_should_get_the_first_word_from_a_line_of_instruction() {
	String oneLineString = {.rawString = "movwf 0x10", .startIndex = 0, .length = 10};

	subString = getWordAndUpdate(&oneLineString, " ");
		
	TEST_ASSERT_EQUAL(5, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(5, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(5, subString->length);
	
	free(subString);
}

void test_getWordAndUpdate_should_get_the_first_and_second_word_from_a_line_of_instruction() {
	String oneLineString = {.rawString = "movwf 0x10", .startIndex = 0, .length = 10};

	subString = getWordAndUpdate(&oneLineString, " ");
		
	TEST_ASSERT_EQUAL(5, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(5, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(5, subString->length);
	
	free(subString);
	
	subString = getWordAndUpdate(&oneLineString, " ");
	
	TEST_ASSERT_EQUAL(10, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(0, oneLineString.length);
	TEST_ASSERT_EQUAL(6, subString->startIndex);
	TEST_ASSERT_EQUAL(4, subString->length);
	
	free(subString);
}


