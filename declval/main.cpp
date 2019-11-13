/**
 * @brief declval
 * Defined in header <utility>
 * template<class T>
 * typename std::add_rvalue_reference<T>::type declval() noexcept;  (since C++11)
 * Converts any type T to a reference type, making it possible to use member functions in decltype expressions without
 * the need to go through constructors.
 * declval is commonly used in templates where acceptable template parameters may have no constructor in common, but
 * have the same member function whose return type is needed.
 */

#include <iostream>
#include <utility>

struct Default
{
    int foo() const
    {
        return 1;
    }
};

struct NonDefault
{
    NonDefault(const NonDefault& other)
    {
    }

    int foo() const
    {
        return 0;
    }
};

int main()
{
    decltype(Default().foo()) n1 = 1;
    // decltype(NonDefault().foo()) n2 = n1;  // error: no default constructor
    decltype(std::declval<NonDefault>().foo()) n2 = n1;

    std::cout << "n1 = " << n1 << std::endl;
    std::cout << "n2 = " << n2 << std::endl;

    return 1;
}