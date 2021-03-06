#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	Base() {}
	Base(const string& arg):arg_(arg) {}
	virtual void print_arg() const
	{ cout << "Base: " << arg_ << endl; }

private:
	string arg_;
};

class BaseLeft : public virtual Base
{};

class BaseRight : public virtual Base
{};

class Derived1 : public BaseLeft, public BaseRight
{
public:
    Derived1() : Base("Derived1") {}
};

class Derived2 : public Derived1
{
public:
	Derived2() : Base("Derived2"), Derived1() {}
};

int main()
{
	Derived1 d1;
    Derived2 d2;
	d1.print_arg();
	d2.print_arg();
	// guess output?
}