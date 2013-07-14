#include <list>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;

class MyBase
{};

class MyDerived : public MyBase
{};

void foo(shared_ptr<MyBase> p)
{}

int main()
{
    shared_ptr<MyDerived> p(new MyDerived);
    foo(p);
    // could you explain how does it work? how does it may be implemented?
}