#include <iostream>

int main()
{
    std::cout << "char: " << sizeof(char) << std::endl;                // 1
    std::cout << "short: " << sizeof(short) << std::endl;              // 2
    std::cout << "int: " << sizeof(int) << std::endl;                  // 4
    std::cout << "uint: " << sizeof(uint) << std::endl;                // 4
    std::cout << "long: " << sizeof(long) << std::endl;                // 4
    std::cout << "float: " << sizeof(float) << std::endl;              // 4
    std::cout << "double: " << sizeof(double) << std::endl;            // 8
    std::cout << "long long: " << sizeof(long long) << std::endl;      // 8
    std::cout << "long int: " << sizeof(long int) << std::endl;        // 8
    std::cout << "long double: " << sizeof(long double) << std::endl;  // 16

    return 0;
}