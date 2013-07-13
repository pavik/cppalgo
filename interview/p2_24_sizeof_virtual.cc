#include <iostream>
#include <vector>
#include <string>
using namespace std;

class A
{
public:
    virtual ~A(){}
};

class B : virtual public A
{
public:
    virtual ~B(){}
};

class C : virtual public A
{
public:
    virtual ~C(){}
};

class D : public B, public C
{};

int main()
{
    cout << sizeof (A) << endl;
    cout << sizeof (B) << endl;
    cout << sizeof (C) << endl;
    cout << sizeof (D) << endl;
    // guess output?
}