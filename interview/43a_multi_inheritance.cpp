#include <iostream>
#include <string>
using namespace std;

class Base1
{
public:
    virtual string name() const { return "Base1"; }
    virtual ~Base1() {}
};

class Base2
{
public:
	virtual string name() const { return "Base2"; }
	virtual ~Base2() {}
};

class Derived : public Base1, public Base2
{
public:
    virtual string name() const { return "Derived"; }
};

int main()
{
    Derived d;
    cout << d.name() << endl;
	cout << d.Base1::name() << endl;
	cout << d.Base2::name() << endl;
	// guess output?
}