#ifndef __BST__
#define __BST__

#include <memory>
#include <vector>

#include "Tree.h"

using namespace std;

class BST: public Tree {
protected:
	shared_ptr<BST> closestChildReplacement();

private:
	void print(vector<bool> drawH);
public:
	shared_ptr<BST> _left;
	shared_ptr<BST> _right;
	shared_ptr<BST> _parent;

	BST();
	BST(int val);
	void print();
	int numChildren();

	void add(int val, shared_ptr<Tree> currNode);
	bool remove(int val);
};

#endif