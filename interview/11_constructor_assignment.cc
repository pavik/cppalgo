#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class String
{
public:
	String(const char *s)
	{
		if (s)
		{
			data = new char[strlen(s) + 1];
			strcpy(data, s);
		}
		else
		{
			data = new char[1];
			*data = '\0';
		}
	}

    const char* rep() const
    { return data; }

	~String()
	{ delete[] data;}

private:
	char *data;
};

void print(String s)
{
    cout << s.rep() << endl;
}

int main()
{
	String a("hello"), b("world");
	a = b;
	String c = a;

	// What problems have this code? How to solve them?
    // Implement assignment operator and copy constructor.	

    print(a);
    cout << a.rep() << endl;
}