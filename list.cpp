/*
 * A Basic implementation of Singly Linked List
 * Operations: Insertion, Deletion, Updating, Searching, Reversing & Rotation
 * Challenges: Templating the class, Addition of 2 numbers represented by Linked List
 */

#include <climits>
#include <iostream>

using namespace std;

class Node
{
	int data;
	Node * next;
public:
	Node();
	Node(int);

	friend class LinkedList;
};

Node :: Node()
{
	data = INT_MAX;
	next = NULL;
}

Node :: Node(int data)
{
	this -> data = data;
	next = NULL;
}

class LinkedList
{
	Node * head,* last;
public:
	void insertNode(int);
	void deleteNode(int);
	bool searchNode(int);
	void updateNode(int,int);
	void createList(int);
	void rotateList(int);
	void printList();
	void reverseList();
};	

void LinkedList :: createList(int data)
{
	Node * temp = new Node(data);
	head = temp;
	last = head;
}

void LinkedList :: insertNode(int data)
{
	if(head == NULL){
		createList(data);
		return ;
	}
		

	last -> next = new Node(data);
	last = last -> next;
}

void LinkedList :: deleteNode(int data)
{
	Node * temp = head;
	Node * prev;

	/* Deletion: First Node */
	if(head -> data == data)
	{
		head = head -> next;
		temp = NULL;
		delete(temp);
		return ;
	}

	/* Deletion: Normal */
	prev = head;
	temp = head -> next;
	while(temp != NULL)
	{
		if(temp -> data == data)
		{
			prev -> next = temp -> next;
			if(temp -> next == NULL)
				last = prev;

			temp -> next = NULL;
			delete(temp);
			temp = NULL;
			return ;
		}

		temp = temp -> next;
		prev = prev -> next;
	}
}

bool LinkedList :: searchNode(int data)
{
	Node * temp = head;
	int count = 1;
	bool flag = false;

	while(temp != NULL)
	{
		if(temp -> data == data)
		{
			cout << "Node found at: " << count << endl;
			count ++;
			flag = true;
		} 

		temp = temp -> next;
	}

	return flag;
}

void LinkedList :: updateNode(int data1,int data2)
{
	Node * temp = head;

	while(temp != NULL)
	{
		if(temp -> data == data1){
			temp -> data = data2;
			break;
		}
		temp = temp -> next;
	}

	if(temp == NULL)
		cout << "Node not found!" << endl;

}

void LinkedList :: rotateList(int count)
{
	int size=0;
	Node *temp = head;
	Node *h1,*h2;

	for(;temp!=NULL;temp=temp->next)
		++size;

	temp = head;
	for(int i=1;i<(size-count);i++)
		temp = temp -> next;

	h2 = temp -> next;
	temp -> next = NULL;

	Node *th = h2;
	while(th -> next != NULL)
		th = th -> next;

	th -> next = head;
	head = h2;
}

void LinkedList :: reverseList()
{
	Node *curr,*prev,*fwd;
	prev = NULL;
	curr = head;

	while(curr != NULL)
	{
		fwd = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = fwd;
	}

	this -> head = prev;
}

void LinkedList :: printList()
{
	Node * temp = head;

	while(temp != NULL){
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
	cout << "NULL"<<endl;
}

int main()
{
	LinkedList list;

	list.createList(11);
	list.insertNode(2);
	list.insertNode(10);
	list.insertNode(76);
	list.insertNode(5);
	list.insertNode(13);
	list.insertNode(44);
	list.printList();

	list.rotateList(3);
	list.printList();

	list.reverseList();
	list.printList();	

	return 0;
}