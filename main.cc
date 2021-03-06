#include <algorithm>
#include <iostream>

#include "TreeRoot.h"
#include "BST.h"
#include "Tree.h"

using namespace std;

int main(int argc, char *argv[]) {
	TreeRoot tree("RBTree");
	// vector<int> vals = {5,11,12,13,1,6,3,2,7,10,4,8,9};
	vector<int> vals = {3,4,2,1};
	// vector<int> vals = {30,40,20,35,50};
	// vector<int> vals;
	// for (int i = 1; i <= 13; ++i) vals.push_back(i);
	// random_shuffle(vals.begin(), vals.end());

	for (int val : vals) {
		cout << val << " ";
		tree.add(val);
		// tree.print();
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