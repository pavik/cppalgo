#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Object
{
public:
    void process()
    {
      /* some complex implementation
       * that reads object from database
       * and writes into the filesystem
      */
    };
};

int main ()
{
    for (size_t i = 0; i < 10; ++i)
    {
        try
        {
            Object *o = new Object();
            o->process();
            delete o;
        }
        catch (...)
        {
            cout << "error" << endl;
        }
    }

    // does it correct? explain and improve?
}