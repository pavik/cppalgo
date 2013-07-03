#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BaseException
{
public:
    BaseException()
    { cout << "BaseException" << endl; }

    BaseException(const BaseException&)
    { cout << "BaseException(const BaseException&)" << endl; }

    ~BaseException()
    { cout << "~BaseException" << endl; }
};

class DerivedException : public BaseException
{
public:
    DerivedException()
    { cout << "DerivedException" << endl; }

    DerivedException(const DerivedException&)
    { cout << "DerivedException(const DerivedException&)" << endl; }

    ~DerivedException()
    { cout << "~DerivedException" << endl; }
};

void foo()
{ throw DerivedException(); }

void callfoo()
{
    try
    { foo(); }
    catch (DerivedException& e)
    { throw e; }
}

int main ()
{
    try
    { callfoo(); }
    catch (DerivedException&)
    { cout << "exception in main" << endl; }

    // guess output? explain and improve?
}