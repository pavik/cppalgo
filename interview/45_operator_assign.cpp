#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	Base(): c('1') {}

private:
	const char c;
};

int main()
{
    Base b1;
    Base b2;
	b1 = b2;
    // does it correct?
}