#include <iostream>
#include <vector>
#include <string>
using namespace std;

string get_str()
{
    return "Hi:)";
}

int main ()
{
    const char *msg = get_str().c_str();
    cout << msg << endl;
    return 0;
    // guess output?
}