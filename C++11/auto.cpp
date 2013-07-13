// auto -- deduction of a type from an initializer

#include <vector>
#include <iostream>
using namespace std;

template<class T> void printall(const vector<T>& v)
{
    //for (typename vector<T>::const_iterator p = v.begin(); p != v.end(); ++p)
    //for (auto p = v.begin(); p != v.end(); ++p)
    for (auto& p : v)
        cout << p << endl;
}

int main()
{
    vector<int> vecA(10, 1);
    const vector<int> vecB(10, 1);
    
    auto acopy = *vecA.begin(); // int
    auto bcopy = *vecB.begin(); // int
    auto& aref = *vecA.begin(); // int&
    auto& bref = *vecB.begin(); // const int&
    auto acopy_not_ref = vecA.front(); // int
    auto& aref_not_copy = vecA.front(); // int&
    auto bcopy_not_ref = vecB.front(); // int
    auto& bref_not_copy = vecB.front(); // const int&

    auto aiter = vecA.begin(); // iterator
    auto biter = vecB.begin(); // const_iterator

    auto* aptr = &aref; // int*
    auto* bptr = &bref; // const int*
	
	int a = 5;
    int& b = a;
    auto& c = b; // int&

    // better to use 'auto' only for minimizing long types names
    // where templates are used. 
    // let C++ remain strongly typed language.
    
    return 0;
}