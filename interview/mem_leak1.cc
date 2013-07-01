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
        Object objects[10];
    }
    catch (const char* e)
    {
        cout << e << endl;
    }

    _CrtDumpMemoryLeaks();
    // guess output? explain?
}