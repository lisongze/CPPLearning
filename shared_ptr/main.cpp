#include <cstring>
#include <iostream>
#include <memory>

class Base
{
public:
    Base()
    {
    }

    virtual int GetType() const = 0;
};

class Derived : public Base
{
public:
    Derived() : Base()
    {
    }

    int GetType() const override
    {
        return type_;
    }

    void SetType(int type)
    {
        type_ = type;
    }

private:
    int type_;
};

int main()
{
    // construct a derived class instance
    Derived derived;

    // set type
    derived.SetType(5);

    std::cout << derived.GetType() << std::endl;

    // make shared_ptr for Derived class
    std::shared_ptr<Derived> derived_ptr = std::make_shared<Derived>(derived);

    // cout use count
    std::cout << "use count: " << derived_ptr.use_count() << std::endl;

    // get Base shared_ptr by static_pointer_cast
    std::shared_ptr<Base> base_ptr = std::static_pointer_cast<Base>(derived_ptr);

    std::cout << base_ptr->GetType() << std::endl;
    std::cout << "use count: " << derived_ptr.use_count() << std::endl;
    std::cout << "use count: " << base_ptr.use_count() << std::endl;

    // make Base shared_ptr directly
    std::shared_ptr<Base> base_ptr_2 = std::make_shared<Derived>(derived);

    std::cout << base_ptr_2->GetType() << std::endl;
    std::cout << base_ptr_2.use_count() << std::endl;
    return 0;
}
