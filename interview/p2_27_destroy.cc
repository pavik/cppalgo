#include <iostream>
#include <vector>
#include <string>
using namespace std;

class A
{
public:
    void Destroy()
    {
        /* complex object destroy ...*/
        delete this; /* free memory */
    }
};

int main()
{
    A a1;
    A *a2 = new A;

    a1.Destroy();
    a2->Destroy();
    // does it correct? how correctly implement self-destroy?
    // how can we guarantee that object is created in the heap?
}