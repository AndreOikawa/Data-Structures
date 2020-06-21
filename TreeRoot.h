#ifndef __ROOT__
#define __ROOT__

#include <memory>
#include <vector>

#include "Tree.h"

using namespace std;

class TreeRoot {
protected:

private:
	enum Type {
		bst,
	};

	Type _treeType;
public:
	shared_ptr<Tree> _tree;
	
	TreeRoot();
	TreeRoot(string type);
	void print();
	int numChildren();
	void add(int val);
	bool remove(int val);
};

#endif