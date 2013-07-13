// auto -- deduction of a type from an initializer

#include <map>
#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

void print_name1(const string& s)
{
    cout << s << endl;
}

void print_name2(const string s)
{
    cout << s << endl;
}

void print_name3(string s)
{
    cout << s << endl;
}

int main()
{
    char name [] = "Aliaksei";
    print_name1(name);
    print_name2(name);
    print_name3(name);
    // how many temporary objects will be created?
    return 0;
}
