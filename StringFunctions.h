#ifndef STRINGFUNCTIONS_H_INCLUDED
#define STRINGFUNCTIONS_H_INCLUDED

int myAtoi( const char* str );

int convertToNumber(const char* str, const int stringLength);

int isDigit(const char symbol);

void myItoa(int number, char * str, int base);

int amountOfDigits(int number);

int myStrcmp(const char* firstString, const char* secondString);

int myPuts(const char* str);
#endif // STRINGFUNCTIONS_H_INCLUDED
