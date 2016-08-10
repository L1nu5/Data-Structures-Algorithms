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
	void revRotate(int);
	void reverse(int,int);
	void printLeaders();
	int findMaxSumNoAdj();
	int findMajorityEle();
	int findCandidate();
	int searchInCircularSorted(int);

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

void ArrayProblems :: reverse(int start,int end)
{	
	if(start > 0 && end < size)
	{
		while(start <= end)
		{
			int temp = array[start];
			array[start] = array[end];
			array[end] = temp;

			start ++;
			end --;
		}
	}
}

void ArrayProblems :: revRotate(int d)
{
	reverse(0,d);
	reverse(d,size-1);
	reverse(0,size-1);
}

void ArrayProblems :: printLeaders()
{
	if(size == 1){
		cout << "Leader: " << array[0];
		return ;
	}

	if(size == 2){
		cout << "Leader: " << max(array[1],array[0]);
		return ;
	}

	int rightMax = max(array[size-1],array[size-2]);
	cout << "Leader: " << rightMax;
	for(int i=size-3;i>=0;i--)
	{
		if(rightMax < array[i]){
			cout << "Leader: " << array[i];
			rightMax = array[i];
		}
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

int ArrayProblems :: findMaxSumNoAdj()
{
	int sum[size];
	sum[0] = array[0];
	sum[1] = max(array[0],array[1]);

	for(int i=2;i<size;i++)
	{
		int mxm = max(array[i]+sum[i-2],array[i]);
		sum[i] = max(mxm,sum[i-1]);
	}

	return sum[size-1];
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

int ArrayProblems :: searchInCircularSorted(int x)
{
	int low = 0, high = size -1;

	while(low <= high)
	{
		int mid = (low + high)/2;
		if(array[mid] == x)
			returm mid;

		if(array[mid] <= array[high])
		{
			if(x > array[mid] && x <= array[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
		else
		{
			if(x < array[mid] && x >= array[low])
				high = mid - 1;
			else
				low = mid + 1;
		}
		
	}

	return -1;
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