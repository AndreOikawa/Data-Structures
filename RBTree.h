#ifndef __RBT__
#define __RBT__

#include <memory>
#include <vector>

#include "Tree.h"

using namespace std;

class RBTree: public Tree {
private:
	// void print(vector<bool> drawH);
	
	void balance();
public:
	// int _val;
	// vector<shared_ptr<Tree>> _children;
	bool _isBlack;
	shared_ptr<RBTree> parent;

	RBTree(int val);
	// void print();
	int add(int val) override;
	bool remove(int val) override;
};

#endif