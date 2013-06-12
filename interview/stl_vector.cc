#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(1);
    vector<int> v2 = v1;
    v2.push_back(2);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    // guess output?
}