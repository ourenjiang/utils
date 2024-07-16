#include "utils/backtrace.h"
#include <iostream>
#include <memory>

using namespace std;

void test_01()
{
    shared_ptr<string> ptr;
    *ptr = "hello";
}

int main()
{
    backtrace_init();
    test_01();
}
