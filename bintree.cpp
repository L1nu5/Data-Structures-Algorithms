/**
	TODO:
	- getHeight, getWidth, isSubtreeOf, inPlaceMirroring
	- AVL balancing(ez)
	- Level Order Traversal
 */

#include <cmath>
#include <queue>
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
	BTNode* insertNode(int,BTNode*);
	BTNode* mirrorTree(BTNode*);
	int getHeight(BTNode*);
	void inOrder(BTNode*);
	void preOrder(BTNode*);
	void postOrder(BTNode*);
	void bfsTraversal(BTNode*);
	void inPlaceMirror(BTNode*);
	bool myAncestors(BTNode*,int);
	int isBST();
	int isBSTUtil(BTNode*,int,int);
	int getCeil(BTNode*,int);

	//yet to finish 
	int getWidth(BTNode*);
	int isBalanced(BTNode*);
};

typedef struct WdtAssist
{
	BTNode *node;
	int level;
}WdtAssist;

BinaryTree :: BinaryTree()
{
	root = NULL;
}

BinaryTree :: BinaryTree(int data)
{
	root = new BTNode(data);
	root -> left = root -> right = NULL;
}

// Need Suggestions on insertion in Binary Tree & NOT Binary Search Tree.
// The following implementation, goes on adding nodes in right subtree.
BTNode* BinaryTree :: insertNode(int data,BTNode *node)
{
	if(node == NULL)
		node = new BTNode(data);
	else if(node -> left == NULL)
		node -> left = insertNode(data,node->left);
	else
		node -> right = insertNode(data,node->right); 

	return node;
}

BTNode* BinaryTree :: mirrorTree(BTNode* node)
{
	if(!node)
		return NULL;
	else
	{
		BTNode* temp = new BTNode(node->data);
		temp -> left = mirrorTree(node->right);
		temp -> right = mirrorTree(node->left);

		return temp;
	}
}

void BinaryTree :: inPlaceMirror(BTNode* node)
{
	if(!node)
		return;
	else
	{
		BTNode *temp = node -> left;
		node -> left = node -> right;
		node -> right = temp;
		
		inPlaceMirror(node->left);
		inPlaceMirror(node->right);
	}
}

int BinaryTree :: getHeight(BTNode* node)
{
	if(node)
		return 1+max(getHeight(node->left),getHeight(node->right));
	return 0;
}

// Implement bfsTraversal before getWidth.
int BinaryTree :: getWidth(BTNode* node)
{

}

void BinaryTree :: bfsTraversal(BTNode* start)
{
	unsigned lvl = 0;
	unsigned count[100];

	queue <WdtAssist> q;
	WdtAssist wa,temp,left,right;

	for(int i=0;i<100;i++)
		count[i] = 0;

	wa.node = start;
	wa.level = lvl;

	q.push(wa);
	while(!q.empty())
	{
		temp = q.front();
		cout << " " << temp.node -> data;
		count[temp.level]++;
		q.pop();

		lvl ++;
		left.node = temp.node -> left;
		left.level = lvl;  
				
		right.node = temp.node -> right;
		right.level = lvl;
		
		if(left.node)
			q.push(left);

		if(right.node)
			q.push(right);
	}

	unsigned max = count[0];
	for(int i=1;i<=lvl;i++)
	{
		if(max < count[i])
			max = count[i];
	}

	cout << endl<< "MAXWIDTH : "<< max;
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

bool BinaryTree :: myAncestors(BTNode* node,int target)
{
	if(node == NULL)
		return false;

	if(node -> data == target)
		return true;

	if(myAncestors(node->left,target) || myAncestors(node->right,target))
	{
		cout << noded -> data << " ";
		return true;
	}

	return false;
}

int BinaryTree :: getCeil(BTNode* node,int value)
{
	if(node == NULL)
		return -1;

	if(node -> data == value)
		return node -> data;

	if(node -> data < value)
		return getCeil(node -> right,value);

	/* Complicated a little 
	   return current value if ceil goes negative i.e. no other node is present */
	
	int ceil = getCeil(node -> left,value);
	return (ceil>=value)?ceil:root->data;
}

int BinaryTree :: isBST()
{
	return(isBSTUtil(this->root,INT_MIN,INT_MAX));
}

int BinaryTree :: isBSTUtil(BTNode *node,int min,int max)
{
 	if(node == NULL)
 		return 1;

 	if(node -> data < min || node -> data > max)
 		return 0;

 	return isBSTUtil(node->left,min,node->data-1) && isBSTUtil(node->right,node->data+1,max);
}

int BinaryTree :: isBalanced(BTNode* node)
{
	return (getHeight(node->left)-getHeight(node->right));
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
	cout << endl << "Height : " << binTree.getHeight(binTree.root);
	cout << endl << "Balance check : " << binTree.isBalanced(binTree.root);
	cout << endl;
	binTree.myAncestors(binTree.root,60);

	return 0;
}