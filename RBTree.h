#ifndef __RBT__
#define __RBT__

#include <memory>
#include <vector>

#include "BST.h"

using namespace std;

class RBTree: public BST {
private:
	void balance();
	bool recolor();
	void rotate();

	// void rotateR();
	// void rotateL();

	void rotateLL();
	void rotateLR();
	void rotateRL();
	void rotateRR();

	void print(vector<bool> drawH);
public:
	// int _val;
	// vector<shared_ptr<Tree>> _children;
	bool _isBlack;

	RBTree(int val);
	void print() override;
	void add(int val, shared_ptr<Tree> currNode) override;
	bool remove(int val) override;
};

#endif

// public:
// 	shared_ptr<BST> _left;
// 	shared_ptr<BST> _right;
// 	shared_ptr<BST> _parent;

// 	BST();
// 	BST(int val);
// 	void print();
// 	int numChildren();

	
// 	bool remove(int val);
