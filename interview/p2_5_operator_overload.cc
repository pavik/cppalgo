#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> class Array
{
public:
    Array(int size) { v_.resize(size); }
    T& operator[](int i) { return v_.at(i); }
    int size() const { return v_.size(); }
private:
    vector<int> v_;
};

bool operator==(const Array<int>& l, const Array<int>& r)
{
    if (l.size() != r.size())
        return false;
    else
        return true;
}

int main()
{
    Array<int> a(10);
    Array<int> b(10);

    if (a == b[0])
        cout << "equals" << endl;
    else
        cout << "not equals" << endl;
    // guess output? how to resolve problem if exists?
}