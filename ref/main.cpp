#include <functional>
#include <iostream>

void add(const int a, const int b, int& c)
{
    c = a + b;
}

int main()
{
    int a = 2;
    int b = 3;
    int c = 10;
    std::function<void()> f_no_ref = std::bind(add, a, b, c);
    std::function<void()> f_ref = std::bind(add, a, b, std::ref(c));
    f_no_ref();
    std::cout << "f_no_ref: " << c << std::endl;
    f_ref();
    std::cout << "f_ref: " << c << std::endl;
    return 0;
}