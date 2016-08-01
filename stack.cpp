/**

	TODO:
	- Find/Maintain Minimum element for a stack
	- Implement PlateStack class 

 */

#include <iostream>

#define MAX 12

using namespace std;

class Stack
{
	int top;
	int stack[MAX];

public:
	// Basic Functions
	Stack();
	int pop();
	int itop();
	void push(int);
	bool isEmpty();
	void reverseStack();
	void insertAtBottom(int);
	void sortStack();
	void sortedInsert(int);
};

Stack :: Stack()
{
	top = -1;
}

void Stack :: push(int data)
{
	if(top == MAX - 1)
		cout << "Stack Overflow!"<<endl;
	else
		stack[++top] = data;
}

int Stack :: pop()
{
	if(top == -1){
		cout << "Stack Underflow!"<<endl;
		return 0;
	}

    return stack[top--];
}

int Stack :: itop()
{
	return stack[top];
}

bool Stack :: isEmpty()
{
	return (top == -1)?1:0;
}

void Stack :: reverseStack()
{
	if(!isEmpty())
	{
		int temp = pop();
		reverseStack();
		insertAtBottom(temp);
	}
}

void Stack :: sortedInsert(int ele)
{
	int temp;
	if(isEmpty() || ele > stack[top])
		push(ele);
	else
	{
		temp = pop();
		sortedInsert(ele);
		push(temp);
	}
}

void Stack :: sortStack()
{
	if(!isEmpty())
	{
		int temp = pop();
		sortStack();
		sortedInsert(temp);
	}
}

void Stack :: insertAtBottom(int data)
{
	if(isEmpty())
		push(data);
	else
	{
		int ele = pop();
		insertAtBottom(data);
		push(ele);
	}
}

int main()
{
	Stack stk;
	stk.push(-5);
	stk.push(10);
	stk.push(3);
	stk.push(9);

	stk.sortStack();
	for(int i=0;i<4;i++)
		cout << " " << stk.pop();

	return 0;
}