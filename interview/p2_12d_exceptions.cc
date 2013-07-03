#include <iostream>
#include <vector>
#include <string>
using namespace std;

void foo()
{ throw 1; }

int main()
{
    try
    { foo(); }
    catch (double& e)
    { cout << e << endl; }

    // guess output? explain?
}