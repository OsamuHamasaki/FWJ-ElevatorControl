//
// ElavatorConctrol main program
//

#include <iostream>
#include <unistd.h>
#include <cstring>
#include "IO.hpp"

static int tickInterval_us = 10000;

bool initialize()
{
	bool result = IO_initialize();

    return result;
}

void finalize()
{
    IO_finalize();
}

void tick()
{
    IO_tick();
}

int main()
{
    if (!initialize()) 
    {
        std::cout << "Error socket:" << std::strerror(errno);
        exit(1);
    }
    
    for ( ; ;)
    {
        tick();
        usleep(tickInterval_us);
    }

    finalize();

    return 0;
}

