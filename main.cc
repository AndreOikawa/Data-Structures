#include <iostream>

#include "BalancedBST.h"
#include "Tree.h"

using namespace std;

int main(int argc, char *argv[]) {
	BalancedBST tree(1);
	for (int i = 2; i <= 13; ++i) tree.add(i);

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