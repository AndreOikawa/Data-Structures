#include <iostream>
#include <stdlib.h>

#include "RBTree.h"

using namespace std;

RBTree::RBTree(int val) : BST(val) {
	_isBlack = true;
}

void RBTree::print() {
	vector<bool> drawH;
	print(drawH);
}

void RBTree::print(vector<bool> drawH) {
	drawH.push_back(true);
	cout << _val << "("<< (_isBlack ? "Black" : "Red") << ")" << endl;
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
		dynamic_pointer_cast<RBTree>(_left)->print(drawH);
	}

	if (_right) {
		for (int j = 0; j < drawH.size() - 1; ++j) {
			if (drawH[j]) cout << "| ";
			else cout << "  ";
		}
		cout << "└─";
		drawH[drawH.size() - 1] = false;

		dynamic_pointer_cast<RBTree>(_right)->print(drawH);
	}
}

void RBTree::rotateLL() {
	shared_ptr<RBTree> self = dynamic_pointer_cast<RBTree>(_parent->_left);
	shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
	shared_ptr<RBTree> grandparent = dynamic_pointer_cast<RBTree>(_parent->_parent);
	
	parent->_left = parent->_right;
	parent->_right = grandparent->_right;
	if (parent->_right) parent->_right->_parent = parent;
	int oldParentVal = parent->_val;
	parent->_val = grandparent->_val;

	grandparent->_val = oldParentVal;
	grandparent->_right = parent;
	grandparent->_left = self;

	self->_parent = grandparent;
}

void RBTree::rotateLR() {
	shared_ptr<RBTree> self = dynamic_pointer_cast<RBTree>(_parent->_right);
	shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
	shared_ptr<RBTree> grandparent = dynamic_pointer_cast<RBTree>(_parent->_parent);

	shared_ptr<RBTree> selfLeft = dynamic_pointer_cast<RBTree>(_left);
	_left = parent;
	_parent = grandparent;

	parent->_parent = self;
	parent->_right = selfLeft;

	parent->rotateLL();
}

void RBTree::rotateRL() {
	shared_ptr<RBTree> self = dynamic_pointer_cast<RBTree>(_parent->_left);
	shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
	shared_ptr<RBTree> grandparent = dynamic_pointer_cast<RBTree>(_parent->_parent);

	shared_ptr<RBTree> selfRight = dynamic_pointer_cast<RBTree>(_right);
	parent->_left = selfRight;
	parent->_parent = self;

	self->_right = parent;
	self->_parent = grandparent;
	
	parent->rotateRR();

}

void RBTree::rotateRR() {
	shared_ptr<RBTree> self = dynamic_pointer_cast<RBTree>(_parent->_right);
	shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
	shared_ptr<RBTree> grandparent = dynamic_pointer_cast<RBTree>(_parent->_parent);

	parent->_right = parent->_left;
	parent->_left = grandparent->_left;
	if (parent->_left) parent->_left->_parent = parent;
	int oldParentVal = parent->_val;
	parent->_val = grandparent->_val;

	grandparent->_val = oldParentVal;
	grandparent->_right = self;
	grandparent->_left = parent;

	self->_parent = grandparent;
}

void RBTree::rotate() {
	int self = _val;
	int parent;
	if (_parent) parent = _parent->_val;
	else return;
	int grandparent;
	if (_parent->_parent) grandparent = _parent->_parent->_val;
	else return;
	// R
	if (grandparent < parent) {
		// cout << "R";
		// R
		if (parent < self) {
			// cout << "R" << endl;
			rotateRR();
		// L
		} else {
			// cout << "L" << endl;
			rotateRL();
		}
	// L
	} else {
		// cout << "L";
		// R
		if (parent < self) {
			// cout << "R" << endl;
			rotateLR();
		// L
		} else {
			// cout << "L" << endl;
			rotateLL();
		}
	}
}

void RBTree::balance() {
	if (_parent == nullptr) {
		_isBlack = true;
		return;
	}
	
	shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
	if (!parent->_isBlack) {
		// uncle is black need to rotate
		if (!recolor()) {
			// cout << "balance" << endl;
			rotate();
		}
		
	}
	
}

bool RBTree::recolor() {
	if (!_parent || !_parent->_parent) return false;
	shared_ptr<BST> u = _parent->_val > _parent->_parent->_val ? _parent->_parent->_left : _parent->_parent->_right;
	if (!u) return false;
	shared_ptr<RBTree> uncle = dynamic_pointer_cast<RBTree>(u);
	// cout << (uncle->_isBlack ? "true" : "false") << endl;
	if (!uncle->_isBlack) {
		shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
		parent->_isBlack = true;
		uncle->_isBlack = true;
		shared_ptr<RBTree> grandparent = dynamic_pointer_cast<RBTree>(parent->_parent);
		grandparent->_isBlack = false;
		grandparent->balance();
		return true;
	}
	return false;
}


void RBTree::add(int val, shared_ptr<Tree> currNode) {
	if (_val < val) {
		if (_right) {
			_right->add(val, _right);
		} else {
			_right = make_shared<RBTree>(val);
			
			shared_ptr<RBTree> right = dynamic_pointer_cast<RBTree>(_right);
			right->_isBlack = false;
			right->_parent = dynamic_pointer_cast<RBTree>(currNode);
			right->balance();
		}
	} else {
		if (_left) {
			_left->add(val, _left);
		} else {
			_left = make_shared<RBTree>(val);

			shared_ptr<RBTree> left = dynamic_pointer_cast<RBTree>(_left);
			left->_isBlack = false;
			left->_parent = dynamic_pointer_cast<RBTree>(currNode);
			left->balance();
		}
	}
}

shared_ptr<RBTree> RBTree::closest() {
	shared_ptr<BST> child;
	if (_right) {
		child = _right;
		while (child->_left) {
			child = child->_left;
		}
	} else if (_left) {
		child = _left;
		while (child->_right) {
			child = child->_right;
		}
	}

	return dynamic_pointer_cast<RBTree>(child);
}

bool RBTree::removeRed() {
	shared_ptr<RBTree> left = dynamic_pointer_cast<RBTree>(_left);
	shared_ptr<RBTree> right = dynamic_pointer_cast<RBTree>(_right);
	if (!_isBlack || (left && !left->_isBlack) || (right && !right->_isBlack)) {
		// _isBlack = true;
		if (left) {
			_val = left->_val;
			
			_left = left->_left;
			_right = left->_right;
		} else if (right) {
			_val = right->_val;

			_left = left->_left;
			_right = left->_right;
		} else {
			if (_parent) {
				if (_parent->_val < _val) {
					_parent->_right = nullptr;
				} else {
					_parent->_left = nullptr;
				}
			}
		}
		return true;
	}
	return false;
}

bool RBTree::removeLL() {

}

bool RBTree::removeLR() {

}

bool RBTree::removeRL() {


}

bool RBTree::removeRR() {
	shared_ptr<RBTree> self = dynamic_pointer_cast<RBTree>(_parent->_left);
	shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
	shared_ptr<RBTree> sibling = dynamic_pointer_cast<RBTree>(_parent->_right);

	_val = parent->_val;	
	if (_right) _left = _right;
	_right = sibling->_left;
	if (_right) _right->_parent = self;

	parent->_val = sibling->_val;

	sibling->_val = sibling->_right->_val;
	sibling->_left = sibling->_right->_left;
	if (sibling->_left) sibling->_left->_parent = sibling;
	sibling->_right = sibling->_right->_right;
	if (sibling->_right) sibling->_right->_parent = sibling;

	return true;
}

bool RBTree::remove() {
	if (removeRed()) {
		return true;
	}

	bool siblingLeft = _parent->_val < _val;
	shared_ptr<RBTree> sibling = dynamic_pointer_cast<RBTree>((siblingLeft ? _parent->_left : _parent->_right));
	if (sibling && sibling->_isBlack) {
		shared_ptr<RBTree> left = dynamic_pointer_cast<RBTree>(sibling->_left);
		shared_ptr<RBTree> right = dynamic_pointer_cast<RBTree>(sibling->_right);
		if (left && !left->_isBlack) {
			if (siblingLeft) return removeLL();
			return removeRL();
		} else if (right && !right->_isBlack) {
			if (siblingLeft) return removeLR();
			return removeRR();
		}
	}
	return false;
}

// bool RBTree::removeSingleChild() {
// 	if (removeRed()) {
// 		return true;
// 	}
// 	return false;
// }

bool RBTree::remove(int val) {
	if (_val == val) {
		shared_ptr<RBTree> replacement = closest();
		if (!replacement) return remove();

		_val = replacement->_val;
		// if (replacement->_left || replacement->_right) return removeSingleChild();
		return replacement->remove();

	} else if (_val > val && _left) { //left
		// if (_left->_val == val) {

		// } else {
			return _left->remove(val);
		// }
	} else if (_val < val && _right) {
		// if (_right->val == val) {

		// } else {
			return _right->remove(val);
		// }
	}
	return false;
}