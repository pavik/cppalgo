#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

class Error
{
public:
    Error() {}
    ~Error()
    { throw exception("hello"); }
};

int main()
{
    try
    {
        //Error e;
        vector<Error> errors(10);
    }
    catch (...)
    {
        cout << "exception" << endl;
    }

    // guess output? what about exceptions in constructors and destructors?
	// does memory free properly?
}