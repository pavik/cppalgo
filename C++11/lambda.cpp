// auto -- deduction of a type from an initializer

#include <map>
#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

void setLambda()
{}

// pass lambdas in to the functions, register callbacks!
// http://www.cprogramming.com/c++11/c++11-lambda-closures.html

int main()
{
    vector<int> v = { 50, -10, 20, -30 };

    // nothing capture
    bool absval = true;
    // nothing capture
    //std::sort(v.begin(), v.end(), [](int a, int b) { return absval ? abs(a) < abs(b) : a < b; });
    //std::sort(v.begin(), v.end(), [this](int a, int b) { return absval ? abs(a) < abs(b) : a < b; });
    std::sort(v.begin(), v.end(), [absval, &v](int a, int b) { return absval ? abs(a) < abs(b) : a < b; });

    // capture all local variables by value
    std::sort(v.begin(), v.end(), [&](int a, int b) { return absval ? abs(a) < abs(b) : a < b; });
    // capture all local variables by name
    std::sort(v.begin(), v.end(), [=](int a, int b) { return absval ? abs(a) < abs(b) : a < b; });
    // capture only absval by value
    std::sort(v.begin(), v.end(), [absval](int a, int b) { return absval ? abs(a) < abs(b) : a < b; });

    auto lambda = [absval](int a, int b) { return absval ? abs(a) < abs(b) : a < b; };
    lambda(1, 4); // call function
    std::sort(v.begin(), v.end(), lambda);

    // better to use lambdas for creation 'one(few) statement' function objects
    return 0;

}