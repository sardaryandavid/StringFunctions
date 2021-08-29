#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

extern const int MAXLENGTH;

void launchAllUnitTests();
void unitTestForMyAtoi(const char* str, const int numberExpected);
void unitTestForMyItoa(int number, const int base, const char* stringExpected);
void unitTestForMyStrcmp(const char* str1, const char* str2, const int numberExpected);

#endif // TESTS_H_INCLUDED
