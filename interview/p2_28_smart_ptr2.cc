#include <list>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;

class MyBase
{};

class MyDerived : public MyBase
{};

class MyDerived2 : public MyDerived
{};

void foo(shared_ptr<MyBase> p)
{
    cout << "MyBase" << endl;
}

void foo(shared_ptr<MyDerived> p)
{
    cout << "MyDerived" << endl;
}

int main()
{
    shared_ptr<MyDerived2> p(new MyDerived2);
    foo(p);
    // guess output?
}