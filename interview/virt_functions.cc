#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Printer
{
public:
    void print1()
    {
        cout << "print1" << endl;
    }

    virtual void print2()
    {
        cout << "print2" << endl;
    }
};

int main()
{
    Printer *p = 0;
    p->print1();
    p->print2();
}