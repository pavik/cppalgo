#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

class Object
{
public:
    Object() { cout << "Object1" << endl; }
    Object(const Object&) { cout << "Object2" << endl; }
    Object& operator=(const Object&) { cout << "Object3" << endl; }
    ~Object() { cout << "Object4" << endl; }
};

Object get_object(Object o)
{ return o; }

int main()
{
    Object o1;
    Object o2 = get_object(o1);
    // guess output? any optimizations?
}