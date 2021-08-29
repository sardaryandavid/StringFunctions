#include "StringFunctions.h"
#include <cmath>
#include <stdio.h>
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
        if (!isDigit(enteredString[stringPointer])) {
            return returningNumber;
        }

        returningNumber *= 10;
        returningNumber += int(enteredString[stringPointer] - '0');
    }

    return returningNumber;
}

int isDigit(const char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return 1;
    }

    return 0;
}

void myItoa(int number, char* resultString) {
    int digitsAmount = amountOfNumbers(number);

    int endOfDigits = digitsAmount;

    if(number < 0) {
        *resultString++ = '-';
    }

    for(int index = 0; index < endOfDigits; ++index) {
        int digit = abs(number) / pow(10, digitsAmount - 1);

        *resultString++ = digit + '0';

        number = number % int(pow(10, digitsAmount - 1));
        --digitsAmount;
    }
}

int amountOfNumbers(int number) {
    assert(std::isfinite(number));

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
         if(firstString[index] > firstString[index]) {
            return 1;
        }

        if(firstString[index] < firstString[index]) {
            return -1;
        }

        ++index;
    }

    if(strlen(firstString) > strlen(secondString)) {
        return 1;
    }

    if(strlen(firstString) < strlen(secondString)) {
        return -1;
    }

    return 0;
}

int myPuts(const char* str) {
    if (str != nullptr) {
        for(int index = 0; index < strlen(str); ++index) {
            printf("%c", str[index]);
        }
        printf("\n");
    }

    return EOF;
}






