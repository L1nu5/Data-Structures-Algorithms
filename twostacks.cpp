#include <iostream>

using namespace std;

class TwoStacks
{
	int stack[10];
	int topA,topB;
public:
	TwoStacks();

	int popA();
	int popB();
	void pushA(int);
	void pushB(int);
};

TwoStacks :: TwoStacks()
{
	topA = -1;
	topB = 10;
}

void TwoStacks :: pushA(int data)
{
	if(topA < topB - 1)
	{
		topA ++ ;
		stack[topA] = data;
	}
	else
		cout << "Stack A full!"<<endl;
}

int TwoStacks :: popA()
{
	if(topA >= 0)
		return stack[topA--];
	else
		return -1;
}

void TwoStacks :: pushB(int data)
{
	if(topA < topB - 1)
	{
		topB --;
		stack[topB] = data;
	}
	else
		cout << "Stack B full!"<<endl;
}

int TwoStacks :: popB()
{
	if(topB <= 9)
		return stack[topB++];
	else
		return -1;
}

int main()
{
	TwoStacks tstk;

	tstk.pushA(5);
	tstk.pushA(55);
	tstk.pushA(333);
	tstk.pushA(4444);
	tstk.pushA(3413);

	tstk.pushB(11111);
	tstk.pushB(1111);
	tstk.pushB(111);
	tstk.pushB(11);
	tstk.pushB(1);

	cout << "StackA" <<endl;
	for(int i=0;i<5;i++)
		cout << tstk.popA() << endl;

	cout << "StackB" <<endl;
	for(int i=0;i<5;i++)
		cout << tstk.popB() << endl;

	return 0;
}