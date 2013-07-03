#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Object
{
public:
    Object():s1(0), s2(0), s3(0)
    {
        s1 = new string("one");
        s2 = new string("two");
        s3 = new string("three");
      /* some complex implementation
       * that reads object from database
       * and writes into the filesystem
      */
    };

    void dosomething() {}

    ~Object()
    {
        delete s1;
        delete s2;
        delete s3;
    }

private:
    string *s1, *s2, *s3;
};

int main ()
{
    for (size_t i = 0; i < 10; ++i)
    {
        try
        {
            Object o;
            o.dosomething();
        }
        catch (...)
        {
            cout << "error" << endl;
        }
    }

    // does it correct? explain and improve?
}