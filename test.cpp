#include <stdio.h>
#include <stdlib.h>
#include "TestConfig.h"
#include <windows.h> /* Testing that this breaks macOS and Linux builds... */

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout,"%s Version %d.%d\n",
                argv[0],
                testrepo_VERSION_MAJOR,
                testrepo_VERSION_MINOR);
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }
    return 0;
}