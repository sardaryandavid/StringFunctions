#include <stdio.h>
#include <stdlib.h>

#include "tests.h"
#include "StringFunctions.h"

//#define TESTS

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
    printf("Use functions from StringFunctions!");
}



