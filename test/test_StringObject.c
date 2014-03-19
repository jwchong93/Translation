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

void test_getWordAndUpdate_should_get_the_first_word_before_a_space_delimiter() {
	String oneLineString = {.rawString = "movwf 0x10", .startIndex = 0, .length = 10};

	subString = getWordAndUpdate(&oneLineString, " ");
		
	TEST_ASSERT_EQUAL(6, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(4, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(5, subString->length);
	TEST_ASSERT_EQUAL('m', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('o', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('v', subString->rawString[subString->startIndex + 2]);
	TEST_ASSERT_EQUAL('w', subString->rawString[subString->startIndex + 3]);
	TEST_ASSERT_EQUAL('f', subString->rawString[subString->startIndex + 4]);
	
	free(subString);
}

void test_getWordAndUpdate_should_get_three_words_from_a_line_with_space_as_delimiter() {
	String oneLineString = {.rawString = "wow wow wow", .startIndex = 0, .length = 11};

	subString = getWordAndUpdate(&oneLineString, " ");
		
	TEST_ASSERT_EQUAL(4, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(7, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(3, subString->length);
	TEST_ASSERT_EQUAL('w', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('o', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('w', subString->rawString[subString->startIndex + 2]);
	
	free(subString);
	
	subString = getWordAndUpdate(&oneLineString, " ");
	
	TEST_ASSERT_EQUAL(8, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(3, oneLineString.length);
	TEST_ASSERT_EQUAL(4, subString->startIndex);
	TEST_ASSERT_EQUAL(3, subString->length);
	TEST_ASSERT_EQUAL('w', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('o', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('w', subString->rawString[subString->startIndex + 2]);
	
	free(subString);
	
	subString = getWordAndUpdate(&oneLineString, " ");
	
	TEST_ASSERT_EQUAL(11, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(0, oneLineString.length);
	TEST_ASSERT_EQUAL(8, subString->startIndex);
	TEST_ASSERT_EQUAL(3, subString->length);
	TEST_ASSERT_EQUAL('w', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('o', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('w', subString->rawString[subString->startIndex + 2]);
	
	free(subString);
}

void test_getWordAndUpdate_should_get_word_with_combination_of_delimiters() {
	String oneLineString = {.rawString = "a b;c,d;e,", .startIndex = 0, .length = 10};

	subString = getWordAndUpdate(&oneLineString, " ,;");
		
	TEST_ASSERT_EQUAL(2, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(8, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(1, subString->length);
	TEST_ASSERT_EQUAL('a', subString->rawString[subString->startIndex]);
		
	free(subString);
	
	subString = getWordAndUpdate(&oneLineString, " ,;");
	
	TEST_ASSERT_EQUAL(4, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(6, oneLineString.length);
	TEST_ASSERT_EQUAL(2, subString->startIndex);
	TEST_ASSERT_EQUAL(1, subString->length);
	TEST_ASSERT_EQUAL('b', subString->rawString[subString->startIndex]);
		
	free(subString);
	
	subString = getWordAndUpdate(&oneLineString, " ,;");
		
	TEST_ASSERT_EQUAL(6, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(4, oneLineString.length);
	TEST_ASSERT_EQUAL(4, subString->startIndex);
	TEST_ASSERT_EQUAL(1, subString->length);
	TEST_ASSERT_EQUAL('c', subString->rawString[subString->startIndex]);
		
	free(subString);
	
	subString = getWordAndUpdate(&oneLineString, " ,;");
	
	TEST_ASSERT_EQUAL(8, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(2, oneLineString.length);
	TEST_ASSERT_EQUAL(6, subString->startIndex);
	TEST_ASSERT_EQUAL(1, subString->length);
	TEST_ASSERT_EQUAL('d', subString->rawString[subString->startIndex]);
		
	free(subString);
	
	subString = getWordAndUpdate(&oneLineString, " ,;");
		
	TEST_ASSERT_EQUAL(10, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(0, oneLineString.length);
	TEST_ASSERT_EQUAL(8, subString->startIndex);
	TEST_ASSERT_EQUAL(1, subString->length);
	TEST_ASSERT_EQUAL('e', subString->rawString[subString->startIndex]);
		
	free(subString);
}

void test_getWordAndUpdate_should_get_a_zero_length_word_when_getting_words_beyond_the_line() {
	String oneLineString = {.rawString = "hello hello", .startIndex = 0, .length = 11};

	subString = getWordAndUpdate(&oneLineString, " ");
	free(subString);
	
	subString = getWordAndUpdate(&oneLineString, " ");
	free(subString);
		
	subString = getWordAndUpdate(&oneLineString, " ");

	TEST_ASSERT_EQUAL(11, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(0, oneLineString.length);
	TEST_ASSERT_EQUAL(11, subString->startIndex);
	TEST_ASSERT_EQUAL(0, subString->length);
	
	free(subString);
}

void test_getWordAndUpdate_should_get_a_zero_length_word_when_getting_no_word_before_delimiters() {
	String oneLineString = {.rawString = ";get me", .startIndex = 0, .length = 7};

	subString = getWordAndUpdate(&oneLineString, " ,;");

	TEST_ASSERT_EQUAL(1, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(6, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(0, subString->length);
	
	free(subString);
}