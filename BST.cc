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

void BST::add(int val) {
	if (_val < val) {
		if (_left) {
			_left->add(val);
		} else {
			shared_ptr<BST> child = make_shared<BST>(val);
			_left = child;
			// _left->_parent = make_shared<BST>(this);
		}
	} else if (_val > val) {
		if (_right) {
			_right->add(val);
		} else {
			shared_ptr<BST> child = make_shared<BST>(val);
			_right = child;
			// _right->_parent = make_shared<BST>(this);
		}
	}
}

bool BST::remove(int val) {return false;}
// bool BST::remove(int val) {
// 	if (_val == val) {
// 		shared_ptr<BST> closestChild;
// 		if (_left) {
// 			closestChild = _left;
// 			while (closestChild->_right) {
// 				closestChild = closestChild->_right;
// 			}
// 			/*	update nodes near x
// 				o   	o
// 				 \		 \
// 				  x  or   x
// 				 /
// 				o
// 			*/
// 			closestChild->_parent->_right = closestChild->_left;
// 			if (closestChild->_left) closestChild->_left->_parent = closestChild->_parent;
// 		} else if (_right) {
// 			closestChild = _right;
// 			while (closestChild->_left) {
// 				closestChild = closestChild->_left;
// 			}
// 			/*	update nodes near x
// 				  o   	   o
// 				 /		  / 
// 				x    or  x
// 				 \
// 				  o
// 			*/
// 			closestChild->_parent->_left = closestChild->_right;
// 			if (closestChild->_right) closestChild->_right->_parent = closestChild->_parent;
// 		} else {
// 			make_shared<BST>(this) = nullptr;
// 			return;
// 		}
		

// 		// change child
// 		closestChild->_parent = _parent;
// 		closestChild->_left = _left;
// 		closestChild->_right = _right;


// 		/*	update nodes near self
// 			  o
// 			  |
// 			  x
// 			 / \
// 			o   o
// 		*/
// 		if (_parent) {
// 			if (_val < _parent->_val) {
// 				// left
// 				_parent->_left = closestChild;
// 			} else {
// 				// right
// 				_parent->_right = closestChild;
// 			}
// 		}

// 		if (_left) {
// 			_left->_parent = closestChild;
// 		}

// 		if (_right) {
// 			_right->_parent = closestChild;
// 		}

		
// 		make_shared<BST>(this) = closestChild;
// 	} else if (_val < val) {
// 		if (_left) _left->remove(val);
// 	} else {
// 		if (_right) _right->remove(val);
// 	}
// }