#include <MainConfig.h>
#include <osConfig.h>
#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/date_time.hpp>

const char osType[] = PLATFORM;

void threadedFunc()
{
    std::cout << "boost::thread - starting" << std::endl;
    std::cout << "boost::thread - going to sleep" << std::endl;
    boost::this_thread::sleep(boost::posix_time::seconds (3));
    std::cout << "boost::thread - waking up" << std::endl;
    std::cout << "boost::thread - finishing" << std::endl;
}

int main (int argc, char *argv[])
{
    std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
    std::cout << "SYSTEM: " << osType << std::endl;

    std::cout << "main - creating thread" << std::endl;
    boost::thread boostThread(threadedFunc);
    std::cout << "main - created" << std::endl;
    std::cout << "main: - waiting" << std::endl;
    boostThread.join();
    std::cout << "main: - joined" << std::endl;
    std::cout << "main - done" << std::endl;
    return 0;
}