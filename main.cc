#include <algorithm>
#include <iostream>

#include "TreeRoot.h"
#include "BST.h"
#include "Tree.h"

using namespace std;

int main(int argc, char *argv[]) {
	TreeRoot tree("RBTree");
	// shared_ptr<Tree> t = make_shared<BST>(1);
	vector<int> vals;
	for (int i = 1; i <= 13; ++i) vals.push_back(i);
	random_shuffle(vals.begin(), vals.end());

	for (int val : vals) {
		cout << val << " ";
		tree.add(val);
	}
	cout << endl;
	// Tree tree(0);
	// int val = 1;
	// for (int i = 0; i < 2; ++i) {
	// 	tree.add(val++);
	// 	for (int j = 0; j < 2; ++j) {
	// 		tree._children[i]->add(val++);
	// 		for (int k = 0; k < 2; ++k) {
	// 			tree._children[i]->_children[j]->add(val++);
	// 		}
	// 	}
	// }
	tree.print();

	int toDelete;
	while (cin >> toDelete) {
		cout << "Deleting " << toDelete << endl;
		tree.remove(toDelete);
		tree.print();
	}
}