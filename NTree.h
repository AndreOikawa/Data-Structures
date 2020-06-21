#ifndef __NTREE__
#define __NTREE__

#include <memory>
#include <vector>

#include "Base.h"

using namespace std;

class Tree: public Base {
protected:

private:
	void print(vector<bool> drawH);
public:
	int _val;
	int _leftHeight;
	int _rightHeight;
	vector<shared_ptr<Tree>> _children;

	Tree();
	Tree(int val);
	void print();
	// void add(int val);
	int add(int val);
	bool remove(int val);
	int newHeight();
};

#endif