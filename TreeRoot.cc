#include <iostream>
#include <memory>
#include <string>

#include "BST.h"
#include "RBTree.h"
#include "TreeRoot.h"

using namespace std;

TreeRoot::TreeRoot() {}

TreeRoot::TreeRoot(string s) {
	if (s == "BST") {
		_treeType = bst;
	} else if (s == "RBTree") {
		_treeType = rb;
	}
}


void TreeRoot::print() {
	if (_tree) _tree->print();
}

void TreeRoot::add(int val) {
	if (_tree) _tree->add(val, _tree);
	else if (_treeType == bst) {
		_tree = make_shared<BST>(val);
	} else if (_treeType == rb) {
		_tree = make_shared<RBTree>(val);
	}
}

bool TreeRoot::remove(int val) {
	if (_tree) {
		if (_tree->_val == val && _tree->numChildren() == 0) {
			_tree = nullptr;
			return true;
		} else {
			return _tree->remove(val);
		}
	}

	return false;
}