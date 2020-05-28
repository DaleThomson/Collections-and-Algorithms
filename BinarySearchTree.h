class BinarySearchTree
{
private:
	struct Tree
	{
		Tree* left; // Left Node
		Tree* right; // Right Node
	};
	Tree* root; // Root Node

public:
	BinarySearchTree(){}; // Constructor

	void insert(); // Used to insert a value into the tree.
	void search(); // Used to search pre-existing values within the tree.

};