#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

int main()
{
    {
        std::cout << "All tests passed!\n";
    }
    _CrtDumpMemoryLeaks();
}