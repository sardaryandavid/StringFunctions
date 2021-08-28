#include <stdio.h>
#include <stdlib.h>

#include "StringFunctions.h"

const int MAXLENGTH = 1e5;


void launchProgram();

int main()
{
#ifdef TESTS
    launchAllUnitTests();
#else
    launchProgram();
#endif // TESTS

    return 0;
}

void launchProgram() {
    printf("Please, enter the number: ");

    char* enteredString = (char*) malloc(MAXLENGTH+1);
    scanf("%s", enteredString); //fgets()

    int rezultNumber = myAtoi(enteredString);
    printf("%d", rezultNumber);
}



