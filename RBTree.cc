#include <iostream>
#include <stdlib.h>

#include "RBTree.h"

using namespace std;

RBTree::RBTree(int val) {
	// super(val);
	_val = val;
	_isBlack = true;
	_children.push_back(nullptr);
	_children.push_back(nullptr);
}

void RBTree::balance() {
	
}

int RBTree::add(int val) {
	if (_val < val) {
		if (_children[0]) {
			_children[0]->add(val);
		} else {
			shared_ptr<RBTree> child = make_shared<RBTree>(val);
			child->_isBlack = false;
			if (!_isBlack) {
				
			}
			_children[0] = child;
		}
	} else {

	}
}

bool RBTree::remove(int val) {
	
}