#ifndef __GENERIC__
#define __GENERIC__

class Base {
public:
	virtual void print() = 0;
	virtual void add(int val) = 0;
	virtual bool remove(int val) = 0;
};

#endif