#include <iostream>

#include "Tree.h"

using namespace std;

Tree::Tree() {}

Tree::Tree(int val) : _val{val} {}

int Tree::newHeight() {
	int height = 0;
	for (int i = 0; i < _children.size(); ++i) {
		if (_children[i]) {
			height = max(height, _children[i]->newHeight() + 1);
		}
	}
	return height;
}

void Tree::print(vector<bool> drawH) {
	drawH.push_back(true);
	cout << _val << endl;
	bool nonNull = false;
	for (int i = 0; i < _children.size(); ++i) {
		if (_children[i]) {
			nonNull = true;
			break;
		}
	}
	if (!nonNull) return;
	for (int i = 0; i < _children.size(); ++i) {
		if (!_children[i]) {
			// if (!last) cout << "|";
			// cout << endl;
			continue;
		}
		for (int j = 0; j < drawH.size() - 1; ++j) {
			if (drawH[j]) cout << "| ";
			else cout << "  ";
		}
		bool last = i == _children.size() - 1;
		if (!last) {
			cout << "├";
		}
		else {
			cout << "└";
			drawH[drawH.size() - 1] = false;
		}
		cout << "─";
		_children[i]->print(drawH);
		
	}
}

void Tree::print() {
	vector<bool> drawH;
	print(drawH);
}

int Tree::add(int val) {
	shared_ptr<Tree> child = make_shared<Tree>(val);
	_children.push_back(child);
	return 0;
}

bool Tree::remove(int val) {
	if (_val == val && _children.size() > 0) {
		shared_ptr<Tree> temp = _children[_children.size() - 1];
		_val = temp->_val;
		_children.pop_back();
		for (int i = 0; i < temp->_children.size(); ++i) {
			_children.push_back(temp->_children[i]);
		}
		return true;
	} else {
		for (int i = 0; i < _children.size(); ++i) {
			shared_ptr<Tree> child = _children[i];
			if (child->_val == val) {
				if (child->_children.size() > 0) {
					_children[i] = child->_children.back();
					child->_children.pop_back();

					for (int j = 0; j < child->_children.size(); ++j) {
						
						_children[i]->_children.push_back(child->_children[j]);
					}
				} else {
					_children.erase(_children.begin() + i);
				}
				return true;
			} else if (child->remove(val)) return true;
		}
	} 
	return false;
}