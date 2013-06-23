#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Base
{
public:
    virtual int getInt() const { return a; }
private:
    int a;
};

class Derived : public Base
{
public:
    virtual int getInt() const { return b; }
private:
    int b;
};

void print(Base a[])
{
    for (size_t i = 0; i < 10; ++i)
        cout << a[i].getInt() << endl;
}

int main()
{
    Derived d[10];
    print(d);
    // guess output?
}