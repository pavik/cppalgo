// auto -- deduction of a type from an initializer

#include <map>
#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

void foo(vector<int>& vec)
{
    for (auto& x : vec) ++x;	// using a reference to allow us to change the value
    for (auto x : vec) cout << x << endl;
    for (const auto x : { 1, 2, 3, 5, 8, 13, 21, 34 }) cout << x << endl;
	// does not matter auto&, auto&&, auto always is const int& here
}

class Patient;
class PatientListIterator;
class PatientList
{
public:
    PatientListIterator& begin();
    const PatientListIterator& begin() const;
    PatientListIterator& end();
    const PatientListIterator& end() const;
};

class PatientListIterator
{
public:
    bool operator!=(const PatientListIterator& right);
    const PatientListIterator& operator++();
    Patient& operator*();
};

PatientListIterator& begin(const PatientList&);
PatientListIterator& end(const PatientList&);

int main()
{
    // standard library
    foo(vector<int>(5, 1));

    // custom types
    PatientList mycontainer;
    for (auto& x : mycontainer)
        cout << "element" << endl;

    return 0;
}