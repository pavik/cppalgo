#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Base
{
public:
    Base()
    { cout << "Base" << endl; }
    ~Base()
    { cout << "~Base" << endl; }
private:
    int a;
};

int main()
{
    Base *a = new Base[10];
    delete a;
    // guess output? does it correct?
}