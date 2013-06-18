#include <iostream>
#include <vector>
#include <string>
using namespace std;

class A
{
public:
    void hi()
    { cout << "hi, A" << endl; }
};

class B : public A
{
public:
    void hi()
    { cout << "hi, B" << endl; }
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