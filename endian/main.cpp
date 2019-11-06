#include <iostream>
#include <bitset>

// in little endian system
union Endian
{
    uint32_t value;
    struct
    {
        uint16_t low;  // low address <-> low byte
        uint16_t high; // high address <-> high byte
    };
};
// example: 
// Endian.value = 0x00010002;
// Endian.low = 0x0002;
// Endian.high = 0x0001;

// in big endian system
// union Endian
// {
//     uint32_t value;
//     struct
//     {
//         uint16_t low;  // low address <-> high byte
//         uint16_t high; // high address <-> low byte
//     };
// };
// Example:
// Endian.value = 0x00010002;
// Endian.low = 0x0001;
// Endian.high = 0x0002;

int main()
{
    Endian t;
    t.low = 0x0002;
    t.high = 0x0001;

    std::bitset<16> bit_low(t.low);
    std::bitset<16> bit_high(t.high);
    std::bitset<32> bit_value(t.value);

    std::cout << "low: " << t.low << ", bit: " << bit_low << std::endl;
    std::cout << "high: " << t.high << ", bit: " << bit_high << std::endl;
    std::cout << "value: " << t.value << ", bit: " << bit_value << std::endl;

    return 0;
}