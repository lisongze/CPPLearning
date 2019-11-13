#include <iostream>

class A
{
protected:
    int a_;
};

class B : virtual public A
{
protected:
    int b_;
};

class C : virtual public A
{
protected:
    int c_;
};

class D : public B, public C
{
public:
    void set_a(int a)
    {
        a_ = a;  // if B and C is virtual Derived, error happened, error: reference to ‘a_’ is ambiguous
    }

    void set_b(int b)
    {
        b_ = b;
    }

    void set_c(int c)
    {
        c_ = c;
    }
};

int main()
{
    D d;
    return 0;
}