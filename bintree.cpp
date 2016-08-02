#include <iostream>

using namespace std;

class BTNode
{
	int data;
	BTNode *left,*right;
public:
	BTNode();
	BTNode(int);

	friend class BinaryTree;
};

BTNode :: BTNode()
{
	data = 0;
	left = right = NULL;
}

BTNode :: BTNode(int data)
{
	this -> data = data;
	left = right = NULL;
}

class BinaryTree
{
public:
	BTNode *root;
	BinaryTree();
	BinaryTree(int);
	void insertNode(int,BTNode*);
	void inOrder(BTNode*);
	void preOrder(BTNode*);
	void postOrder(BTNode*);
};

BinaryTree :: BinaryTree()
{
	root = NULL;
}

BinaryTree :: BinaryTree(int data)
{
	root = new BTNode(data);
	root -> left = root -> right = NULL;
}

void BinaryTree :: insertNode(int data,BTNode *node)
{
	if(node == NULL)
		node = new BTNode(data);
	else if(node -> left == NULL)
		insertNode(data,node->left);
	else if(node -> right == NULL)
		insertNode(data,node->right);
}

void BinaryTree :: inOrder(BTNode* node)
{
	if(node == NULL)
		return ;

	inOrder(node->left);
	cout << node -> data << " ";
	inOrder(node->right);

}

void BinaryTree :: preOrder(BTNode* node)
{
	if(node)
	{
		cout << node -> data << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
	else return;
}

void BinaryTree :: postOrder(BTNode* node)
{
	if(node)
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node -> data << " ";
	}
}

int main()
{
	BinaryTree binTree(5);
	binTree.insertNode(90,binTree.root);
	binTree.insertNode(20,binTree.root);
	binTree.insertNode(30,binTree.root);
	binTree.insertNode(40,binTree.root);
	binTree.insertNode(50,binTree.root);
	binTree.insertNode(60,binTree.root);

	cout << endl;
	binTree.inOrder(binTree.root);
	cout << endl;
	binTree.postOrder(binTree.root);
	cout << endl;
	binTree.preOrder(binTree.root);

	return 0;
}