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