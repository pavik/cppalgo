#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	const size_t ASIZE = 5 * sizeof(string);
	string *a1 = static_cast<string*>(malloc(ASIZE));
	string *a2 = new string[5];

	//memset(a1, 0, ASIZE);
	string *s = new (a1)string("one");
	copy(a1, a1 + 5, ostream_iterator<string>(cout, "\n")); // guess output?

	// how to release all allocated memory?
	// what about destructors in a1 and a2 arrays
	// delete a1; delete a2; what happens?
}