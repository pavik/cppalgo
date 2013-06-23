#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

union Share
{
    int a;
    char b[4];
};

int main()
{
    Share s;
    s.a = 1;
    cout << int(s.b[0]) << int(s.b[1]) << int(s.b[2]) << int(s.b[3]) << endl;
    // guess output?
}