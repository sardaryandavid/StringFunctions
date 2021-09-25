#include <stdio.h>
#include <stdlib.h>

#include "tests.h"
#include "StringFunctions.h"

#include <iostream>

//#define TESTS

void launchProgram();

int main()
{
#ifdef TESTS
    printf("Start testing\n");
    launchAllUnitTests();
    printf("End testing\n");
#else
    launchProgram();
#endif // TESTS

    return 0;
}

void launchProgram() {
    printf("Use functions from StringFunctions!");
}



