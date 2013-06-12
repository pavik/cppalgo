#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Object
{
public:
    Object(const string& s):s1(s)
    {}
    ~Object() {}
private:
    string s1;
};

class Subject : public Object
{
public:
    Subject(const string& s):Object(s), s2(s)
    {}
private:
    string s2;
};

int main()
{
    Object *o = new Subject("hello");
    delete o;
    // what about virtual destructors?
    _CrtDumpMemoryLeaks();
}