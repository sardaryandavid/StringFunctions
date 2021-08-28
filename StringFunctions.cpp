#include "StringFunctions.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

int myAtoi(const char* enteredString) {
    int stringLength = strlen(enteredString);

    int startPointer = 0;

    if (enteredString[startPointer] == '-') {
        return -convertToNumber(enteredString, startPointer + 1, stringLength); // TODO!!!
    }

    return convertToNumber(enteredString, startPointer, stringLength);
}

int convertToNumber(const char* enteredString, const int startPointer, const int stringLength) {
    int returningNumber = 0;

    for(int stringPointer = startPointer; stringPointer < stringLength; ++stringPointer) {
        if (!isNumber(enteredString[stringPointer])) {
            return returningNumber;
        }

        returningNumber *= 10;
        returningNumber += int(enteredString[stringPointer] - '0');
    }

    return returningNumber;
}

int isNumber(const char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return 1;
    }

    return 0;
}
