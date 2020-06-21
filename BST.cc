#include <iostream>

#include "BST.h"

using namespace std;

BST::BST() {}

BST::BST(int val) : Tree(val) {}

int BST::numChildren() {
	int count = 0;
	if (_left) count++;
	if (_right) count++;
	return count;
}
void BST::print(vector<bool> drawH) {
	drawH.push_back(true);
	cout << _val << endl;
	int children = numChildren();
	if (children == 0) return;
	if (_left) {
		for (int j = 0; j < drawH.size() - 1; ++j) {
			if (drawH[j]) cout << "| ";
			else cout << "  ";
		}
		if (children > 1) cout << "├";
		else {
			drawH[drawH.size() - 1] = false;
			cout << "└";
		}
		cout << "─";
		_left->print(drawH);
	}

	if (_right) {
		for (int j = 0; j < drawH.size() - 1; ++j) {
			if (drawH[j]) cout << "| ";
			else cout << "  ";
		}
		cout << "└─";
		drawH[drawH.size() - 1] = false;

		_right->print(drawH);
	}
}

void BST::print() {
	vector<bool> drawH;
	print(drawH);
}

void BST::add(int val, shared_ptr<Tree> currNode) {
	if (_val > val) {
		if (_left) {
			_left->add(val, _left);
		} else {
			shared_ptr<BST> child = make_shared<BST>(val);
			_left = child;
			_left->_parent = dynamic_pointer_cast<BST>(currNode);
		}
	} else if (_val < val) {
		if (_right) {
			_right->add(val, _right);
		} else {
			shared_ptr<BST> child = make_shared<BST>(val);
			_right = child;
			_right->_parent = dynamic_pointer_cast<BST>(currNode);
		}
	}
}

shared_ptr<BST> BST::closestChildReplacement() {
	shared_ptr<BST> child;
	if (_left) {
		child = _left;
		while (child && child->_right) {
			child = child->_right;
		}
		/*	update nodes near x
			o   	o
			 \		 \
			  x  or   x
			 /
			o
		*/
		if (child->_parent->_right) child->_parent->_right = child->_left;
		else child->_parent->_left = child->_left;
		if (child->_left) child->_left->_parent = child->_parent;
	} else {
		child = _right;
		while (child && child->_left) {
			child = child->_left;
		}
		/*	update nodes near x
			  o   	   o
			 /		  / 
			x    or  x
			 \
			  o
		*/
		if (child->_parent->_left) child->_parent->_left = child->_right;
		else child->_parent->_right = child->_right;
		if (child->_right) child->_right->_parent = child->_parent;
	}
	return child;
}

bool BST::remove(int val) {
	if (_val == val) {
		shared_ptr<BST> closestChild = closestChildReplacement();		
		_val = closestChild->_val;
		return true;
	} else if (_val > val) {
		if (_left && _left->_val == val) {
			shared_ptr<BST> closestChild = _left->closestChildReplacement();
			_left->_val = closestChild->_val;
			return true;
		} else if (_left) return _left->remove(val);
		
	} else {
		if (_right && _right->_val == val) {
			shared_ptr<BST> closestChild = _right->closestChildReplacement();
			_right->_val = closestChild->_val;
			return true;
		} else if (_right) return _right->remove(val);
	}
	return false;
}