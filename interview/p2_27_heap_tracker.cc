#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

class HeapTracker
{
public:
    class InvalidAddress {};
    virtual ~HeapTracker() {};
    static void* operator new(size_t size)
    {
        void* ptr = ::operator new(size);
        addr.push_front(ptr);
        return ptr;
    }
    static void operator delete(void* p)
    {
        list<RawAddress>::iterator ptr = 
            find(addr.begin(), addr.end(), p);
        if (ptr != addr.end())
        {
            addr.erase(ptr);
            ::operator delete(p);
        }
        else
            throw InvalidAddress();
    }
    bool ontheheap() const
    {
        RawAddress p = dynamic_cast<RawAddress>(this);
        list<RawAddress>::const_iterator ptr = 
            find(addr.begin(), addr.end(), p);
        return ptr != addr.end();
    }
private:
    typedef const void* RawAddress;
    static list<RawAddress> addr;
};
list<HeapTracker::RawAddress> HeapTracker::addr;

class MyClass : public HeapTracker
{
public:
};

int main()
{
    MyClass a1, *a2 = new MyClass;
    MyClass a3[1], *a4 = new MyClass[1];
    cout << a1.ontheheap() << a2->ontheheap() << endl;
    cout << a3[0].ontheheap() << a4->ontheheap() << endl;
    delete a2;
    delete[] a4;
    // guess output?
    // what for class HeapTracker is need?
    // what does class HeapTracker do?
    // what for is virtual destructor in class HeapTracker?
}