#include "test.h"
#include <iostream>

class Test::TestImpl
{
public:
    TestImpl()
    {
    }

    void Fun();
};

void Test::TestImpl::Fun()
{
    std::cout << "We are in Test::TestImpl::Fun." << std::endl;
}

void Test::Fun()
{
    std::cout << impl_ptr_ << std::endl;  // 0
    impl_ptr_->Fun();  // just a member function, it is not stored in class memory, so it can be called
}