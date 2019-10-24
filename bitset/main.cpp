#include <bitset>
#include <iomanip>
#include <iostream>

int main()
{
    uint n_main_type = 1 << 16;
    uint n_sub_type  = 256;
    uint type        = (0xffff0000 & n_main_type) | (0x0000ffff & n_sub_type);

    std::cout << "binary main: " << std::bitset<32>(0xffff0000 & n_main_type) << std::endl;
    std::cout << "binary sub: " << std::bitset<32>(0x0000ffff & n_sub_type) << std::endl;

    std::cout << "binary main type: " << std::bitset<32>(n_main_type) << std::endl;
    std::cout << "binary sub type: " << std::bitset<32>(n_sub_type) << std::endl;
    std::cout << "binary type: " << std::bitset<32>(type) << std::endl;

    std::cout << std::endl;
    std::cout << "hex main_type: " << std::setfill('0') << std::setw(8) << n_main_type << std::endl;
    std::cout << "hex sub_type: " << std::setfill('0') << std::setw(8) << n_sub_type << std::endl;
    std::cout << "hex type: " << std::setfill('0') << std::setw(8) << type << std::endl;

    return 0;
}
