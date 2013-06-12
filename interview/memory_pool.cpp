#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// implements effective memory allocation/deallocation
// for small objects of size >= 4 bytes
// implementation is not thread safe
template <class T> class Pool
{
public:
	// initialize memory pool for n objects
	Pool(size_t n): pmem_(0), blocksize_(n) {}

	// release memory pool
	// it is your responsibility to make sure that all objects already released
	~Pool()
	{
		if (orig_)
			::operator delete(orig_);
		orig_ = 0;
	}

	// allocate memory for one object of given size
	void* alloc(size_t size)
	{
		if (sizeof(T) == size)
		{
			T* p = pmem_;
			if (p)
				pmem_ = pmem_->next_;
			else
			{
				T* nextblock = static_cast<T*>(::operator new(blocksize_*sizeof(T)));
				orig_ = nextblock;
				p = nextblock;
				for (size_t i = 1; i < blocksize_ - 1; ++i)
					nextblock[i].next_ = &nextblock[i+1];
				nextblock[blocksize_ - 1].next_ = 0;
				pmem_ = &nextblock[1];
			}
			return p;
		}
		else
			return ::operator new(size);
	}

	// free memory for one object
	void free(void *p, size_t size)
	{
		if (sizeof(T) == size && p)
		{
			T *dead = static_cast<T*>(p);
			dead->next_ = pmem_;
			pmem_ = dead;
		}
		else
			::operator delete(p);
	}

private:
	T *pmem_;
	T *orig_;
	size_t blocksize_;
};

class Message
{
public:
	static void* operator new(size_t size)
	{ return pool_.alloc(size); }

	static void operator delete(void *obj, size_t size)
	{ pool_.free(obj, size); }

//private:
	Message *next_;
	friend class Pool<Message>;
	static Pool<Message> pool_;
};
Pool<Message> Message::pool_(10);

class Message2 : public Message
{
public:
	int x,y;
};

int main()
{
	for (int i = 0; i < 5; ++i)
		Message2 *m = new Message2;
	//Message::pool_.~Pool();
	_CrtDumpMemoryLeaks();
}