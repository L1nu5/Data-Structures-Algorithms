#include <iostream>
#include <queue>

using namespace std;

class StackByQueue
{
	queue <int> q;
	
public:
	int pop();
	int peek();
	void push(int);
};

void StackByQueue :: push(int data)
{
	q.push(data);
}

int StackByQueue :: pop()
{
	int temp = q.back();
	
	for(int i=0;i<q.size()-1;i++)
	{
		q.push(q.front());
		q.pop();
	}

	return temp;
}

int main()
{
	StackByQueue stk;

	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	stk.push(50);

	cout << stk.pop() << " ";
	cout << stk.pop() << " ";
	cout << stk.pop() << " ";
	cout << stk.pop() << " ";
	cout << stk.pop() << " ";
	
	return 0;
}