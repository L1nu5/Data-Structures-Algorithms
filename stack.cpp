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
	stk.push(10);
	stk.push(12);
	stk.push(15);

	stk.reverseStack();
	for(int i=0;i<3;i++)
		cout << " " << stk.pop();

	stk.push(15);
	stk.push(13);
	stk.push(10);
	stk.reverseStack();
	for(int i=0;i<3;i++)
		cout << " " << stk.pop();

	return 0;
}