#include <iostream>
#include <stdlib.h>

#include "BalancedBST.h"

using namespace std;

BalancedBST::BalancedBST(int val) {
	// super(val);
	_val = val;
	_leftHeight = 0;
	_rightHeight = 0;
	_children.push_back(nullptr);
	_children.push_back(nullptr);
}

void BalancedBST::balance() {
	bool isLeftBigger = _leftHeight > _rightHeight;
	int side = (isLeftBigger ? 0 : 1);
	shared_ptr<Tree> self = make_shared<BalancedBST>(_val);
	int myVal = _val;
	_val = _children[side]->_val;
	if (isLeftBigger) {
		shared_ptr<Tree> right = _children[0]->_children[1];
		_children[0] = _children[0]->_children[0];
		self->_children[1] = _children[1];
		self->_children[0] = right;
		_children[1] = self;
	} else {
		shared_ptr<Tree> left = _children[1]->_children[0];
		_children[1] = _children[1]->_children[1];
		self->_children[0] = _children[0];
		self->_children[1] = left;
		_children[0] = self;
	}

	if (_children[0]) _leftHeight = _children[0]->newHeight() + 1;
	else _leftHeight = 0;

	if (_children[1]) _rightHeight = _children[1]->newHeight() + 1;
	else _rightHeight = 0;
}

int BalancedBST::add(int val) {
	if (val < _val) {
		if (_children[0] == nullptr) {
			shared_ptr<Tree> child = make_shared<BalancedBST>(val);
			_children[0] = child;
			_leftHeight++;
		} else {
			_leftHeight = _children[0]->add(val) + 1;

		}
		
	} else if (val > _val) {
		if (_children[1] == nullptr) {
			shared_ptr<Tree> child = make_shared<BalancedBST>(val);
			_children[1] = child;
			_rightHeight++;
		} else {
			_rightHeight = _children[1]->add(val) + 1;

		}
	}
	if (abs(_leftHeight - _rightHeight) > 1) balance();
	// cout << _val << " left: " << _leftHeight << " right: " << _rightHeight << endl;
	return max(_leftHeight, _rightHeight);
	
}

// bool BalancedBST::remove(int val) {
// 	if (_val == val && _children.size() > 0) {
// 		shared_ptr<Tree> temp = _children[_children.size() - 1];
// 		_val = temp->_val;
// 		_children.pop_back();
// 		for (int i = 0; i < temp->_children.size(); ++i) {
// 			_children.push_back(temp->_children[i]);
// 		}
// 		return true;
// 	} else if (_val < val) {
		
// 	} else if (_val > val) {
		
// 	}
// 	return false;
// }