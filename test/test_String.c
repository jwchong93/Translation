#include "unity.h"
#include "String.h"
#include <stdio.h>

void setUp() {}
void tearDown() {}

void test_stringLeftTrim_should_return_a_trimmed_string() {
	String str = {"   movlw", 3, 5};
	int i;
	
	TEST_ASSERT_EQUAL_STRING("movlw", stringLeftTrim(str));
	
	for(i = 0; i < 5; i ++) {
		putchar(*stringLeftTrim(str));
	}
}