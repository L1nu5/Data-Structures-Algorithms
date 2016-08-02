#include <iostream>
#include <queue>

using namespace std;

class BinGen
{
	int x;
	queue<string> que;
public:
	void getCount(int);
	void generate();
};

void BinGen :: getCount(int data)
{
	x = data;
}

void BinGen :: generate()
{
	string s1,s2;
	que.push("1");

	while(x--)
	{
		s1 = que.front();
		que.pop();
		cout << s1 << endl;

		s2 = s1;

		que.push(s1.append("0"));
		que.push(s2.append("1"));
	}
}

int main()
{
	BinGen bg;

	bg.getCount(10);
	bg.generate();
	
	return 0;
}