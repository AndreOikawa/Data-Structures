#ifndef __BBST__
#define __BBST__

#include <memory>
#include <vector>

#include "Tree.h"

using namespace std;

class BalancedBST: public Tree {
private:
	// void print(vector<bool> drawH);
	int _leftHeight;
	int _rightHeight;
	void balance();
	
public:
	// int _val;
	// vector<shared_ptr<Tree>> _children;

	BalancedBST(int val);
	// void print();
	int add(int val) override;
	// bool remove(int val) override;
};

#endif