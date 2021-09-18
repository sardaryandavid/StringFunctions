#include "StringFunctions.h"
#include <cmath>
#include <stdio.h>
#include <cctype>
#include <cassert>
#include <algorithm>
#include <string.h>

const int MAXLENGTH = 1E5;

int myAtoi(const char* enteredString) {
    int stringLength = strlen(enteredString);

    int startIndex = 0;

    if (enteredString[startIndex] == '-') {
        return -convertToNumber(enteredString + 1, stringLength);
    }

    return convertToNumber(enteredString, stringLength);
}

int convertToNumber(const char* enteredString, const int stringLength) {
    int returningNumber = 0;

    for(int index = 0; index < stringLength; ++index) { // TODO!!!
        if (!isdigit(enteredString[index])) {
            return returningNumber;
        }

        returningNumber *= 10;
        returningNumber += enteredString[index] - '0';
    }

    return returningNumber;
}

char* myItoa(int number, const int base) {
    int digitsAmount = amountOfDigits(number);

    char* resultString = (char*) calloc(digitsAmount + 2, sizeof(char)); // for '\0' and '-'
    char* returningResultString = resultString;

    int endOfDigits = digitsAmount;

    if(number < 0) {
        *resultString++ = '-';
    }

    for(int index = 0; index < endOfDigits; ++index) {

        int digit = abs(number) / pow(base, digitsAmount - 1);

        *resultString++ = digit + '0';

        number = number % int(pow(base, digitsAmount - 1));
        --digitsAmount;
    }

    return returningResultString;
}

int amountOfDigits(int number) {
    if (number == 0) {
        return 1;
    }

    int counter = 0;

    while (number != 0) {
        ++counter;
        number /= 10;
    }

    return counter;
}

int myStrcmp(const char* firstString, const char* secondString) {
    int index = 0;

    while(firstString[index] != '\0' && secondString[index] != '\0') {
         if(firstString[index] != secondString[index]) {
            return firstString[index] - secondString[index];
        }

        ++index;
    }

    return strlen(firstString) - strlen(secondString);
}

int myPuts(const char* str) {
    if (str != nullptr) {
            printf("%s\n", str);
        }

    return EOF;
}

int myGetline(char* str, const int maxLengthOfLine) {
    int lengthOfLine = 0;
    int c;

    while((c = getchar()) != '\n' && lengthOfLine < maxLengthOfLine - 1) {
        *str++ = c;
        ++lengthOfLine;
    }

    *(++str) = '\0';

    return lengthOfLine;
}

char* strdup(char* str) {
    char* copyOfStr = (char*) calloc(myStrlen(str) + 1, sizeof(*str));

    if(copyOfStr != nullptr) {
        myStrcpy(copyOfStr, str);
    }

    return copyOfStr;
}

int myStrlen(char* str) {
    int lengthOfStr = 0;

    while(*str++ != '\0') {
        ++lengthOfStr;
    }

    return lengthOfStr;
}

void myStrcpy(char* copyOfStr, char* str) {
    while((*copyOfStr++ = *str++) != '\0') {
        /* empty body */
    }
}
