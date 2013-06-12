#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

// propose implementation of class bind_impl?

template<class T, class Arg> bind_impl<T,Arg> bind(const T& obj, void (T::*fptr)(Arg))
{
    return bind_impl<T,Arg>(obj, fptr);
}

class Printer
{
public:
    void print(const string& name)
    {
        cout << name << endl;
    }
};

int main()
{
    Printer p;
    string name = "HI";
    bind(p, &Printer::print)(name);
}