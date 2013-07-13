// auto -- deduction of a type from an initializer

#include <map>
#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

class Object
{
public:
    Object()
    {
        cout << "constructor" << endl;
    }
    Object(const Object&)
    {
        cout << "copy constructor" << endl;
    }
    ~Object()
    {
        cout << "destructor" << endl;
    }
};

Object createObject()
{
    return Object();
}

int main()
{
    Object obj1 = createObject();
    // guess output?
    return 0;
}
