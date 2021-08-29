#include "StringFunctions.h"
#include <cmath>
#include <stdio.h>
#include <cctype>
#include <cassert>
#include<algorithm>
#include <string.h>

int myAtoi(const char* enteredString) {
    int stringLength = strlen(enteredString);

    int startIndex = 0;

    if (enteredString[startIndex] == '-') {
        return -convertToNumber(enteredString + 1, stringLength); // TODO!!!!!!
    }

    return convertToNumber(enteredString, stringLength);
}

int convertToNumber(const char* enteredString, const int stringLength) {
    int returningNumber = 0;

    for(int stringPointer = 0; stringPointer < stringLength; ++stringPointer) {
        if (!isdigit(enteredString[stringPointer])) {
            return returningNumber;
        }

        returningNumber *= 10;
        returningNumber += enteredString[stringPointer] - '0';
    }

    return returningNumber;
}

void myItoa(int number, char* resultString, int base) {
    int digitsAmount = amountOfDigits(number);

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
         if(firstString[index] != firstString[index]) {
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

