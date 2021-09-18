#include <stdio.h>
#include <stdlib.h>

#include "tests.h"
#include "StringFunctions.h"

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
    char* s= "ABCDEF";
    char* p = strdup(s);
    printf("%s\n", p);
    printf("Use functions from StringFunctions!");
}



