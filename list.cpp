/*
 * A Basic implementation of Singly Linked List
 * Operations: Insertion, Deletion, Updating, Searching, Reversing & Rotation
 * Challenges: Making the Class Generic
 * An excercise for solving all the problems related to Linked Lists.
 * More Challeges: Union & Intersection of Linked Lists, Find middle node(s) of List
 */

#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_set>

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
 	LinkedList();
 	void insertNode(int);
 	void deleteNode(int);
 	bool searchNode(int);
 	void updateNode(int,int);
 	void createList(int);
 	void rotateList(int);
 	void printList();
 	void reverseList();
 	void removeDups();
 	void findMiddle();
 	LinkedList addLists(LinkedList);
 	int getLength();

	// More!
 	bool isPallindrome();
 };	

 LinkedList :: LinkedList()
 {
 	head = last = NULL;
 }

 void LinkedList :: createList(int data)
 {
 	Node * temp = new Node(data);
 	head = temp;
 	last = head;
 }

 int LinkedList :: getLength()
 {
 	Node * temp = head;
 	int size=0;
 	while(temp != NULL)
 	{
 		size ++;
 		temp = temp -> next;
 	}

 	return size;
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

 LinkedList LinkedList :: addLists(LinkedList list2)
 {
 	int sum = 0;
 	int carry = 0;

 	int l1 = this -> getLength();
 	int l2 = list2.getLength();
 	LinkedList sumList;

 	// Check for lengths & handle accordingly
 	if(l1 != l2)
 	{
 		LinkedList temp;
 		for(int i=0;i<(abs(l2-l1));i++)
 			temp.insertNode(0);

 		if(l1 < l2){
 			temp.last = this -> head;
 			this -> head = temp.head;
 		}else if(l1 > l2){
 			temp.last = list2.head;
 			list2.head = temp.head;
 		}
 	}

 	// Actual Addition of LinkedLists
 	Node *t1,*t2;
 	t1 = this -> head;
 	t2 = list2.head;

 	while(t1 != NULL)
 	{
 		sum = carry + t1 -> data + t2 -> data;
 		carry = sum / 10;
 		sum = sum % 10;
 		sumList.insertNode(sum);

 		t1 = t1 -> next;
 		t2 = t2 -> next;
 	}
 	sumList.insertNode(carry);
 	
 	return sumList;
 }

// Function uses O(N) time & O(N) space. Alternative using O(N^2) time & O(1) space
 void LinkedList :: removeDups()
 {
 	Node *temp = head;
 	Node *prev = NULL;
 	unordered_set<int> hash;

 	while(temp != NULL)
 	{
 		auto search = hash.find(temp -> data);
 		if(search != hash.end()){
 			prev -> next = temp -> next;
 		}else{
 			hash.insert(temp -> data);
 			prev = temp;
 		}

 		temp = temp -> next;
 	}
 }

 void LinkedList :: findMiddle()
 {
 	Node *slow,*fast,*mid;
 	slow = head;
 	fast = head;

 	// odd or even, get ref to mid node
 	while(fast -> next != NULL && fast -> next -> next != NULL)
 	{
 		slow = slow -> next;
 		fast = fast -> next -> next;
 	}

 	if(fast -> next == NULL)
 	{
 		mid = slow;
 		cout << "Mid is : " << mid -> data << endl;
 	}
 	else
 	{
 		mid = slow -> next;
 		cout << "Double middle case- " << endl;
 		cout << "first mid = " << slow -> data << endl;
 		cout << "second mid = " << mid -> data << endl;
 	}
 }

/* Main - To Test LinkedList class */

 int main()
 {
 	LinkedList listA;

 	listA.insertNode(1);
 	listA.insertNode(1);
	listA.insertNode(2);
 	listA.insertNode(1);
 	listA.insertNode(3);
 	listA.insertNode(4);
 	listA.insertNode(3);
 	listA.insertNode(2);
 	listA.insertNode(3);
 	listA.printList();

 	listA.findMiddle();
 	listA.printList();

 	return 0;
 }