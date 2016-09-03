// Added Dutch National Flag problem & solution
// Some of the following functions work as set of 2


#include <cmath>
#include <stack>
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
	void findSumX(int); 
	void findSumXforTwo(int); 
	void revRotate(int);
	void reverse(int,int);
	void swap(int &,int &);
	void printLeaders();
	void segregateDutch();
	void twoRepeaters();
	void findUnsortedRegion();
	void moveZeroesToEnd();
	void findTotalOnes(int,int);
	void findMinMissing(int,int);
	void printDistinct();
	void printEquilibrium();
	void printNGE();
	int findMaxSumNoAdj();
	int findMajorityEle();
	int findCandidate();
	int searchInCircularSorted(int);
	int maxContigSum();

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

void ArrayProblems :: moveZeroesToEnd()
{
	int count = 0;
	for(int i=0;i<size;i++)
	{
		if(array[i])
			array[count++] = array[i]
	}

	while(count < n)
		array[count++] = 0;
}

// A little different approach, for the same problem solved by the solution above
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

// An element is a leader if it's greater than the elements on the right side of its position
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

void ArrayProblems :: segregateDutch()
{
	int mid = 0;
	int low = 0;
	int high = size - 1;

	while(mid <= high)
	{
		switch(mid)
		{
			case 0: swap(array[mid],array[low]);
					mid++;
					low++;
					break;
			case 1:
					mid++;
					break;
			case 2:
					swap(array[mid],array[high]);
					high--;
					break;
		}
	}
}

void ArrayProblems :: findTotalOnes(int low,int high)
{
	if(high >= low)
	{
		int mid = (low+high)/2;
		if((mid == high || array[mid+1] == 0) && (array[mid] == 1))
			{
				cout << "Total 1s: " << mid+1;
				return ;
			}		
		if(array[mid] == 1)
			findTotalOnes(mid+1,high);
		findTotalOnes(low,mid-1);
	}
}


// Strictly follows that numbers > 0 & numbers <= n
void ArrayProblems :: twoRepeaters()
{
	int S=0,P=1;
	int n = size - 2;
	int D;
	int x,y;

	for(int i=0;i<size;i++)
	{
		S = S + array[i];
		P = P * array[i];
	}

	S = S - n*(n+1)/2;
	P = P / fact(n);

	D = sqrt(S*S-4*P);
	x = (D + S)/2;
	y = (S - D)/2;

	cout << 	endl << "Repeaters : " << x << " " << y;
}

void ArrayProblems :: findUnsortedRegion()
{
	int max,min;

	for(int s=0;s<size;s++)
	{
		if(array[s] > array[s+1])
			break;
	}

	if(s == size) return ;

	for(int e=size-1;e>=0;e--)
		if(array[e] < array[e-1])
			break;

	max = array[s];
	min = array[s];
	for(int i=s+1;i<=e;i++)
	{
		if(min > array[i])
			min = array[i];
		if(max < array[i])
			max = array[i];
	}

	for(int i=0;i<s;i++)
	{
		if(array[i] > min)
		{
			s = i;
			break;
		}
	}

	for(int i=n-1;i>=e+1;i--)
	{
		if(array[i] < max)
		{
			e = i;
			break;
		}
	}

	cout << "Start: " << s << " " << "End: "<< e << endl;
}

void ArrayProblems :: printDistinct()
{
	sort(&array[0],&array[size-1]);

	for(int i=0;i<size;i++)
	{
		while(i < n-1 && array[i] == array[i+1])
			i++;

		cout << " " << array[i];
	}
}

void ArrayProblems :: findMinMissing(int low,int high)
{
	if(low > high)
		return end + 1;

	if(low != array[low])
		return low;

	int mid = (low+high)/2;

	if(array[mid] > mid)
		findMinMissing(low,mid);
	else
		findMinMissing(mid+1,high);
}

void ArrayProblems :: printEquilibrium()
{
	int total = 0,leftSum = 0;

	for(int i=0;i<size;i++)
		total += array[i];

	for(int i=0;i<size;i++)
	{
		total -= array[i];

		if(leftSum == total){
			cout << endl << " Index : " << i;
			return ;
		}

		leftSum += array[i];
	}

	cout << endl << "none";
	return;
}

void ArrayProblems :: printNGE()
{
	stack<int> stk;
	int i=1;
	stk.push_back(array[0]);
	while(!stk.empty())
	{
		x = array[i];
		while(x > stk.back())
		{
			int temp = stk.pop_back();
			cout << "NGE pair: " << temp << " " << x; 
		}

		if(stk.back() > x)
			stk.push_back(array[i]);

		stk.push_back(x);
		i++;
	}
}

void ArrayProblems :: swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
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

// Moderately difficult problem
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

int ArrayProblems :: maxContigSum()
{
	int maxSum = array[0];
	int currMax = array[0];

	for(int i=1;i<size;i++)
	{
		currMax = max(array[i],currMax + array[i]);
		maxSum = max(currMax,maxSum);
	}

	return maxSum;	
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

int fact(int n)
{
	return (n == 0)?1:n*fact(n-1);
}