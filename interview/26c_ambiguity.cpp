#include <iostream>
#include <string>
using namespace std;

class Base1
{
public:
    string name() const { return "Base1"; }
    virtual ~Base1() {}
};

class Base2
{
protected:
	string name() const { return "Base2"; }
public:
	virtual ~Base2() {}
};

class Derived : public Base1, public Base2
{
public:
    Derived() {}
};

int main()
{
    Derived d;
    d.name();
}