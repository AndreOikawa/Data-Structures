#ifndef __TREE__
#define __TREE__

#include <memory>
#include <vector>

#include "Base.h"

using namespace std;

class Tree: public Base {
private:
	void print(vector<bool> drawH);
public:
	int _val;
	vector<shared_ptr<Tree>> _children;

	Tree(int val);
	void print();
	void add(int val);
	bool remove(int val);
};

#endif