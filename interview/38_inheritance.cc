#include <iostream>
#include <vector>
#include <string>
using namespace std;

class A
{
public:
    virtual void hi(const string& name = "A")
    { cout << "hi from A, " << name << endl; }
};

class B : public A
{
public:
    void hi(const string& name = "B")
    { cout << "hi from B, " << name << endl; }
};

int main ()
{
    B x;
    A* aptr = &x;
    B* bptr = &x;
    aptr->hi();
    bptr->hi();
    // guess output? explain?
}