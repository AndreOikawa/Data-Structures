#ifndef __Tree__
#define __Tree__

#include <memory>

using namespace std;

class Tree {
public:
	int _val;
	Tree();
	Tree(int val);
	virtual void print() = 0;
	virtual int numChildren() = 0;
	virtual void add(int val, shared_ptr<Tree> currNode) = 0;
	virtual bool remove(int val) = 0;
};

#endif