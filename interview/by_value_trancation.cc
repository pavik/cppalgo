#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

class Parent
{
public:
    virtual const char* name() const { return "Parent"; };
    virtual ~Parent() {}
};

class Child : public Parent
{
public:
    virtual const char* name() const { return "Child"; };
    virtual ~Child() {}
};

void print_name(Parent p)
{ cout << p.name() << endl; }

int main()
{
    Child c;
    print_name(c);
    // guess output?
}