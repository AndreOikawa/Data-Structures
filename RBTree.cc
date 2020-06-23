#include <iostream>
#include <stdlib.h>

#include "RBTree.h"

using namespace std;

RBTree::RBTree(int val) : BST(val) {
	_isBlack = true;
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
}

void RBTree::rotateLR() {
}

void RBTree::rotateRL() {
}

void RBTree::rotateRR() {
}

void RBTree::rotate() {
	int self = _val;
	int parent = _parent->_val;
	int grandparent = _parent->_parent->_val;
	// R
	if (parent < self) {
		// R
		if (grandparent < parent) {
			rotateRR();
		// L
		} else {
			rotateRL();
		}
	// L
	} else {
		// R
		if (grandparent < parent) {
			rotateLR();
		// L
		} else {
			rotateLL();
		}
	}
}

void RBTree::balance() {
	if (_parent == nullptr) {
		_isBlack = true;
		return;
	}
	if (_parent) {
		shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
		if (!parent->_isBlack) {
			// uncle is black need to rotate
			if (!recolor()) {
				rotate();
			}
			
		}
	}
}

bool RBTree::recolor() {
	shared_ptr<BST> u = _val > _parent->_val ? _parent->_left : _parent->_right;
	if (!u) return false;
	shared_ptr<RBTree> uncle = dynamic_pointer_cast<RBTree>(u);
	if (!uncle->_isBlack) {
		shared_ptr<RBTree> parent = dynamic_pointer_cast<RBTree>(_parent);
		parent->_isBlack = true;
		uncle->_isBlack = true;
		shared_ptr<RBTree> grandparent = dynamic_pointer_cast<RBTree>(parent->_parent);
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
		}
	}
}

bool RBTree::remove(int val) {
	return false;
}