#include <MainConfig.h>
#include <osConfig.h>
#include <iostream>
#include <thread>

const char osType[] = PLATFORM;

void workerFunc()
{
    std::cout << "Worker: running" << std::endl;
    std::cout << "Worker: finished" << std::endl;
}

int main (int argc, char *argv[])
{
    std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
    std::cout << "SYSTEM: " << osType << std::endl;

    std::thread workerThread(workerFunc);

    std::cout << "main: waiting for thread" << std::endl;

    workerThread.join();

    std::cout << "main: done" << std::endl;
    return 0;
}