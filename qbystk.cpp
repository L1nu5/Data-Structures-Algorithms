#include <iostream>
#include <vector>

using namespace std;

#define THRESH 10

class QueueViaStacks
{
	vector<int> stackFr,stackBk;
public:
	int back();
	int front();
	bool isEmpty();
	void insert(int);
	int deleteFromQ();
};

int QueueViaStacks :: back()
{
	return this -> stackBk.back();
}

int QueueViaStacks :: front()
{
	return stackFr.back();
}

int QueueViaStacks :: deleteFromQ()
{
	int temp;
	
	if(isEmpty()){
		cout << "Queue Empty!" << endl;
		return 0;
	}

	if(stackFr.empty())
	{
		while(!stackBk.empty())
		{
			stackFr.push_back(stackBk.back());
			stackBk.pop_back();
		}
	}

	temp = stackFr.back();
	stackFr.pop_back();
	return temp;
}	

void QueueViaStacks :: insert(int data)
{
	stackBk.push_back(data);
}

bool QueueViaStacks :: isEmpty()
{
	if(stackFr.empty() && stackBk.empty())
		return true;
	return false;
}

int main()
{
	QueueViaStacks qs;

	qs.insert(1);
	qs.insert(4);
	qs.insert(6);
	qs.insert(10);
	qs.insert(11);
	qs.insert(12);

	for(int i=0;i<6;i++)
		cout << endl << qs.deleteFromQ();

	return 0;
}