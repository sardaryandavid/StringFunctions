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

    for (int index = 0; index < stringLength; ++index) {
        if (!isdigit(*(enteredString + index))) {
            return returningNumber;
        }

        returningNumber *= 10;
        returningNumber += enteredString[index] - '0';
    }

    return returningNumber;
}

char* myItoa(int number, const int base) {
    int isNegative = 0;
    int digitsAmount = 0;

    if (number < 0) {
        isNegative = 1;
        digitsAmount = amountOfDigits(-number, base);
    }

    else {
        digitsAmount = amountOfDigits(number, base);
    }

    char* resultString = (char*) calloc(digitsAmount + 2, sizeof(*resultString)); // for '\0' and '-'
    char* returningResultString = resultString;

    if (isNegative) {
        *resultString++ = '-';
        number = -number;
    }

    while (number > 0) {
        *resultString++ = number % base + '0';
        number /= base;
    }

    if (isNegative) {
        myReverse(returningResultString + 1);
    }

    else {
       myReverse(returningResultString);
    }

    return returningResultString;
}

void myReverse(char* str) {
    size_t strLen = strlen(str);
    char* tmpStr = (char*) calloc(strLen, sizeof(*tmpStr));

    int index = strLen - 1; //почему с size_t не работало
    int i = 0;

    while (index >= 0) {
        *(tmpStr + i++) = *(str + index);
        --index;
    }

    for(int i = 0; i < strLen; ++i) {
        *(str + i) = *(tmpStr + i);
    }
}

int amountOfDigits(int number, const int base) {
    if (number == 0) {
        return 1;
    }

    int counter = 0;

    while (number != 0) {
        ++counter;
        number /= base;
    }

    return counter;
}

int myStrcmp(const char* firstString, const char* secondString) {
    int index = 0;

    while (firstString[index] != '\0' && secondString[index] != '\0') {
         if (firstString[index] != secondString[index]) {
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

int myGetline(char** ptrOnStr, int* maxLengthOfLine, FILE* stream) {
    assert(ptrOnStr != nullptr);

    int lengthOfLine = 0;
    int symbol = 0;

    while ((symbol = getchar()) != '\n') {
        *(*ptrOnStr)++ = symbol;
        ++lengthOfLine;

        if (lengthOfLine > *maxLengthOfLine) {
            char* ptrOnNewMemory = (char*) calloc(lengthOfLine * 2, sizeof(int));
            strcpy(ptrOnNewMemory, *ptrOnStr);
            ptrOnStr = &ptrOnNewMemory;
            *maxLengthOfLine = 2 * lengthOfLine;
            //second variant:
            //char* ptrOnNewMemory = (char*) realloc(ptrOnStr, sizeof(*ptrOnStr));
        }

    }

    *((*ptrOnStr)++) = '\0';

    return lengthOfLine;
}

char* strdup(char* str) {
    char* copyOfStr = (char*) calloc(myStrlen(str) + 1, sizeof(*str));

    if (copyOfStr != nullptr) {
        myStrcpy(copyOfStr, str);
    }

    return copyOfStr;
}

int myStrlen(char* str) {
    int lengthOfStr = 0;

    while (*str++ != '\0') {
        ++lengthOfStr;
    }

    return lengthOfStr;
}

void myStrcpy(char* copyOfStr, char* str) {
    while ((*copyOfStr++ = *str++) != '\0') {
        /* empty body */
    }
}
