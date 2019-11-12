#ifndef TEST_H
#define TEST_H

class Test
{
public:
    Test()
    {
        impl_ptr_ = nullptr;
    }

    void Fun();

private:
    class TestImpl;
    TestImpl* impl_ptr_;  // forward declaration just can be used to define pointer or reference
};

#endif  // !TEST_H