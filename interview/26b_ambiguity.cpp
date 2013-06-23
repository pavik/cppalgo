#include <iostream>
using namespace std;

class Int;
class Double
{
public:
	Double() {}
	Double(const Int& o) {}
};

class Int
{
public:
	Int() {}
	Int(const Double& o) {}
	operator Double() const { return Double(); }
};


void print(const Double& i)
{
	cout << "Hi" << endl;
}

int main()
{
	Int i;
	Double d;
	print(d);
	print(i);
	// doest it correct? guess output?
}