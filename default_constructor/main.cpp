#include <iostream>

class Data
{
public:
    enum class Id : int8_t
    {
        L3RD    = -5,
        L2ND    = -3,
        L1ST    = -1,
        R1ST    = 1,
        R2ND    = 3,
        R3RD    = 5,
        INVALID = 15,
    };

    enum class Type : uint8_t
    {
        UNDECIDED = 0,
        SOLID     = 1,
        EDGE      = 2,
        DASHED    = 3,
        INVALID   = 15
    };

    enum class Color : uint8_t
    {
        WHITE   = 0,
        YELLOW  = 1,
        BLUE    = 2,
        INVALID = 15
    };

public:
    /**
     * @brief default constructor
     */
    Data() = default;

public:
    Id    id_;
    Type  type_;
    Color color_;
    int   width_;
    float confidence_;
    bool  predicted_;

};  // Data

int main()
{
    Data lb;
    std::cout << "id_: " << static_cast<int>(lb.id_) << std::endl;         // random result
    std::cout << "type_: " << static_cast<uint>(lb.type_) << std::endl;    // random result
    std::cout << "color_: " << static_cast<uint>(lb.color_) << std::endl;  // random result
    std::cout << "width_: " << lb.width_ << std::endl;                     // random result
    std::cout << "confidence_: " << lb.confidence_ << std::endl;           // random result
    std::cout << "predicted_: " << lb.predicted_ << std::endl;             // random result

    return 0;
}