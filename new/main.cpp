#include <iostream>

int main()
{
    uint8_t buffer[16];
    uint* data = reinterpret_cast<uint*>(buffer);

    std::cout << &data[0] << std::endl;
    std::cout << &data[1] << std::endl;
    std::cout << &data[2] << std::endl;
    std::cout << &data[3] << std::endl;

    // new uint at specified address, it is more efficient
    // same as data[0] = 0; but if uint is a class, there are two steps:
    // 1. Constructor. 2. Assignment operator.
    new (&data[0]) uint(0);
    new (&data[1]) uint(1);
    new (&data[2]) uint(2);
    new (&data[3]) uint(3);

    // Note: data address not changed
    std::cout << &data[0] << std::endl;
    std::cout << &data[1] << std::endl;
    std::cout << &data[2] << std::endl;
    std::cout << &data[3] << std::endl;

    std::cout << data[0] << std::endl;
    std::cout << data[1] << std::endl;
    std::cout << data[2] << std::endl;
    std::cout << data[3] << std::endl;
    return 0;
}
