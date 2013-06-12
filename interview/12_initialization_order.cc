#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Object
{
public:
    Object(const string& tag):s(tag)
    { cout << s << endl; }

    Object(const Object& o):s(o.s)
    { cout << s << endl; }

    ~Object()
    { cout << "~" << s << endl; }

private:
    string s;
};

class Subject
{
public:
    Subject():o1("o1"), o2("o2")
    {}

    Subject(const Subject& s):o2(s.o2), o1(s.o1)
    {}

private:
    Object o1, o2;
};

int main()
{
    Subject s1, s2(s1);
    // guess output?
}