#include <iostream>
#include <algorithm>

using namespace std;

class ArrayProblems
{
	int *array;
	unsigned size;
public:
	ArrayProblems();
	ArrayProblems(int);

	int *getLocation(); //Be careful with this method!
	void print();
	void resize(int);
	void insert(int);
	int &operator[](int);

	//Problems & Solutions
	void findSumXforTwo(int); /* Check whether arrays contains two numbers whose sum = x */
	void findSumX(int); // Variant of above, efficient
	int findMajorityEle();
	int findCandidate();
};

int &ArrayProblems :: operator[](int i)
{
	if(i > size)
	{
		cout << endl<< "Array index out of bounds!";
		return array[0];
	}
	return array[i];
}

ArrayProblems :: ArrayProblems()
{
	array = NULL;
	size = 0;
}

ArrayProblems :: ArrayProblems(int size)
{
	array = new int[size];
	this -> size = size;
}

void ArrayProblems :: print()
{
	cout << endl;
	for(int i=0;i<size;i++)
		cout << " " << array[i];
}

void ArrayProblems :: resize(int newSize)
{
	if(newSize < 0 || size == 0 || newSize == size)
		return ;

	int temp[newSize];

	for(int i=0;i<newSize;i++)
		temp[i] = array[i];

	if(newSize > size)
		for(int i=size;i<newSize;i++)
			temp[i] = 0;

	delete []array;
	array = temp;
}

/*----------  Problems related to Arrays  ----------*/

void ArrayProblems :: findSumXforTwo(int x)
{
	sort(array,array+size);

	int l = 0;
	int r = size - 1;
	unsigned count = 0;
	unsigned sum = array[l] + array[r];

	while(l <= r)
	{
		if(sum == x)
			count ++;
		else if(sum > x)
			r --;
		else if(sum < x)
			l ++;
	}

	cout << endl << "Pairs found : " << count ;
}

void ArrayProblems :: findSumX(int x)
{
	int temp;
	bool binMap[10000] = {0};

	for(int i=0;i<size;i++)
	{
		temp = x - array[i];
		if(temp >= 0 && binMap[temp] == 1)
			cout << endl << "Pair with given sum exists: " << array[i] << " " << temp;
		binMap[array[i]] = 1;
	}
}

int ArrayProblems :: findCandidate()
{
	int count=1;
	int maj_index=0;

	for(int i=1;i<size;i++)
	{
		if(array[maj_index] == a[i])
			count ++;
		else
			count --;
		if(count == 0)
		{
			maj_index = i;
			count = 1;
		}
	}

	return array[maj_index];
}

int ArrayProblems :: findMajorityEle(int x)
{
	int count=0;
	for(int i=0;i<size;i++)
		if(array[i] == x)
			count ++;
	if(count > size/2)
		return x;
	else
		return 0;
}

int* ArrayProblems :: getLocation()
{
	return array;
}

int main()
{
	ArrayProblems prb;

	return 0;
}