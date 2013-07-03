#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Sesssion
{
public:
    Sesssion()
    {
        start_transaction();
        write_to_database("Sesssion created");
    };

    ~Sesssion()
    {
        write_to_database("Sesssion destroyed");
        end_transaction();
    }

private:
    void start_transaction() {};
    void end_transaction() {};
    void write_to_database(const char *msg)
    { /* writes string into database */ }
};

int main ()
{
    // complex program use Session objects
    // does it safe/correct? explain and improve?
}