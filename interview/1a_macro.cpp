#include <iostream>
using namespace std;

#define maximum(a, b) a > b ? a : b 
// is it correct?
// alternative solution not using macro?

int main()
{
	int a = 0, b = 0;
	maximum(++a, b);
	maximum(++a, b + 5);
	cout << a << endl << b << endl; // guess output?
}