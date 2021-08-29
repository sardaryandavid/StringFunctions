#include "StringFunctions.h"
#include "tests.h"

#include <stdio.h>
#include <cassert>

void launchAllUnitTests() {
    unitTestForMyAtoi("123", 123);
    unitTestForMyAtoi("-123", -123);
    unitTestForMyAtoi("0", 0);
    unitTestForMyAtoi("123kq", 123);
    unitTestForMyAtoi("kq123", 0);

    unitTestForMyItoa(10, 10, "10");
    unitTestForMyItoa(123, 10, "123");
    unitTestForMyItoa(15, 15, "10");
    unitTestForMyItoa(-123, 10, "-123");

    unitTestForMyStrcmp("123", "123", 0);
    unitTestForMyStrcmp("1234", "123", 1);
    unitTestForMyStrcmp("123", "1234", -1);
}

void unitTestForMyAtoi(const char* str, const int numberExpected) {
    assert(myAtoi(str) == numberExpected);
}

void unitTestForMyItoa(int number, const int base, const char* stringExpected) {
    assert(myStrcmp(myItoa(number, base), stringExpected) == 0);
}

void unitTestForMyStrcmp(const char* str1, const char* str2, const int numberExpected) {
    assert(myStrcmp(str1, str2) == numberExpected);
}

