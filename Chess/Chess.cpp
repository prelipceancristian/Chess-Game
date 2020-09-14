#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "Tester.h"

int main()
{
    {
        Tester tester;
        tester.test_all();
        std::cout << "All tests passed!\n";
    }
    _CrtDumpMemoryLeaks();
}