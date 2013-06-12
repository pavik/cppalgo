#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Double
{
public:
    Double(int n, int d):n_(n), d_(d)
    { cout << "Double" << endl; }

    Double(const Double&)
    { cout << "Double(cc)" << endl; }

    ~Double()
    { cout << "~Double" << endl;}

    friend const Double& operator*(const Double& l, const Double& r);
private:
    int n_, d_;
};

const Double& operator*(const Double& l, const Double& r)
{
    Double *res = new Double(l.n_*r.n_, l.d_*r.d_);
    return *res;
}

int main ()
{
    Double a(1,1), b(2,2), c(3,3), d(4,4);
    Double res = a*b*c*d;
    return 0;
    // Do you see any problems in this piece of code?
}