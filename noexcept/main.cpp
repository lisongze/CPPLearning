#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

class test
{
public:
    test() noexcept
    {
        throw std::string("In constructor with noexcept");
    }
};

class Test
{
public:
    Test()
    {
        throw std::string("In constructor without noexcept");
    }
};

int main()
{
    test t;  //  warning: throw will always call terminate() [-Wterminate]
    Test t2;
    return 0;
}
