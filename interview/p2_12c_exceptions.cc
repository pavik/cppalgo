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
{ throw new DerivedException(); } // what if 'new' or constructor throw exception?

void callfoo()
{
    try
    { foo(); }
    catch (BaseException*)
    { throw; }
}

int main ()
{
    try
    { callfoo(); }
    catch (DerivedException*)
    { cout << "exception in main" << endl; }

    _CrtDumpMemoryLeaks();
    // guess output? does it correct/safe? explain and improve?
}