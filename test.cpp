#include <stdio.h>
#include <stdlib.h>
#include "TestConfig.h"
#include "os.h"

const char var1[] = FOO;

int main (int argc, char *argv[])
{
    fprintf(stdout,"Version: %i.%i\n", testrepo_VERSION_MAJOR, testrepo_VERSION_MINOR);
    fprintf(stdout,"SYSTEM: %s\n", var1);
    return 0;
}