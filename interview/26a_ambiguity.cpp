#include <iostream>
using namespace std;

void f(int i)
{
	cout << "int" << endl;
}

void f(char c)
{
	cout << "char" << endl;
}

int main()
{
	f(1.0);
	// does it correct? guess output?
}