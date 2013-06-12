#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

class Object
{
public:
    Object(int i):n(i)
    { cout << "Object " << n << endl; }
    ~Object()
    { cout << "~Object " << n << endl; }
private:
    int n;
};

Object o1(1);

void foo()
{
    static Object o(2);
}

void bar()
{
    static Object o(3);
}

int main()
{
    bar();
    foo();
    // guess output?
}