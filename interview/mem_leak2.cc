#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Object
{
public:
    Object():buf(0)
    {
        buf = new char[10];
        if (n > 3)
            throw "only 3 object allowed";
        else
            ++n;
    }

    ~Object()
    {
        --n;
        if (buf)
            delete[] buf;
    }

private:
    static size_t n;
    char *buf;
};

size_t Object::n = 0;

int main ()
{
    try
    {
        Object *objects = new Object[10];
    }
    catch (const char* e)
    {
        cout << e << endl;
    }

    _CrtDumpMemoryLeaks();
    // how many memory leaks possible here?
    // what'll be if we create 3 objects array?
    // how to protect code from memory leaks?
    // guess output? explain?
}