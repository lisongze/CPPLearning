// dynamic_cast<type_id>(expression) : 
//      1. type_id must be pointer
//      2. class must have derive relationship

#include <iostream>

using namespace std;

class TestB;

class TestA
{
public:
    TestA()
    {
    }
    TestA(const TestB& o)
    {
    }

    int data;
};

class TestB
{
public:
    TestB()
    {
    }

    int data;
};

class TestC
{
public:
    TestC()
    {
    }

    int data;
};

class TestD : public TestC
{
public:
    TestD() : TestC()
    {
    }

    int data;
};

int main()
{
    TestA a;
    TestB b;

    TestA sa = std::static_cast<TestA>(b);  // ok

    // TestA* psa = std::static_cast<TestA*>(&b);    // error: invalid static_cast from type ‘TestB*’ to type ‘TestA*’

    // error: cannot dynamic_cast ‘b’ (of type ‘class TestB’) to type ‘class TestA’ (target is not pointer or reference)
    // TestA da = std::dynamic_cast<TestA>(b);

    // error: cannot dynamic_cast ‘& b’ (of type ‘class TestB*’) to type ‘class TestA*’ (source type is not polymorphic)
    // TestA* pda = std::dynamic_cast<TestA*>(b);

    TestC  c;
    TestD  d;
    TestC  sc  = std::static_cast<TestC>(d);     // ok
    TestC* psc = std::static_cast<TestC*>(&d);   // ok
    TestC* sc  = std::dynamic_cast<TestC*>(&d);  // ok
    // TestC  sc  = dynamic_cast<TestC>(d);    // error: not pointer
    return 0;
}