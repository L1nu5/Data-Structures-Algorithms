/**
 * BEWARE ALL THE FUNCTIONS ARE UNTESTED & THE WHOLE SOURCE CODE HASN'T BEEN COMPILED YET.
 */


#include <cmath>
#include <stack>
#include <cstdio>
#include <ctime>
#include <cstdlib>
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
	void findTripletForX(int);
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
	void printMaximum();
	void findMinDistance(int,int);
	void findDuplicates();
	void maxBitonicSeq();
	void findSingle();
	void shuffleArray();
	bool areConsecutives();
	int *constrOrig();
	int findFixedPoint(int,int);
	int findMaxSumNoAdj();
	int findMajorityEle();
	int findCandidate();
	int searchInCircularSorted(int);
	int maxContigSum();
	int getMax();
	int getMin();

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

// 17th September 2016 
void ArrayProblems :: findTripletForX(int x)
{
	sort(array,array+size);
	
	unsigned l,r;

	for(int i=0;i<size-2;i++)
	{
		l = i + 1;
		r = size - 1;

		while(l < r)
		{
			if((array[i] + array[l] + array[r]) == sum){
				cout << endl << "TRUE! : " << array[i] << " " << array[l] << " " << array[r];
				return ;
			}
			else if(array[i] + array[l] + array[r] > sum)
				r --;
			else
				l ++;
		}
	}

	cout << "NOPE! None."
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

	cout << endl << "Repeaters : " << x << " " << y;
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
	sort(array,array+size);

	for(int i=0;i<size;i++)
	{
		while(i < n-1 && array[i] == array[i+1])
			i++;

		cout << " " << array[i];
	}
}

// 3rd September 2016
void ArrayProblems :: findMinMissing(int low,int high)
{
	if(low > high)
		return ;

	if(low != array[low]){
		return low;
	}

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

void ArrayProblems :: findMinDistance(int x,int y)
{
	int i,prev;
	int minDist = INT_MAX;
	for(i=0;i<n;i++)
	{
		if(array[i] == x || array[i] == y){
			prev = i;
			break;
		}
	}

	for(;i<n;i++)
	{
		if(array[i] == x || array[i] == y)
		{
			if(array[prev] != array[i] && (i-prev) < minDist)
			{
				minDist = i;
				prev = i;
			}	
			else
				prev = i;
		}
	}

	cout << endl << "Minimum Distance : " << minDist;
}

// 5th September 2016
//Requires numbers to be in range from 0 to N

void ArrayProblems :: findDuplicates()
{
	cout << endl << "Repeating Elements : ";
	for(int i=0;i<n;i++)
	{
		if(A[abs(A[i])] >= 0)
			A[abs(A[i])] = - A[abs(A[i])];
		else
			cout << endl << "Duplicate : " << A[i];	
	}
}

int ArrayProblems :: findFixedPoint(int low,int high)
{
	if(high >= low)
	{
		int mid = (low + high) / 2;
		if(mid == array[mid])
			return mid;
		else if(mid > array[mid])
			return findFixedPoint(mid+1,high);
		else
			return findFixedPoint(low,mid-1);
	}

	return -1;
}	

// 
void ArrayProblems :: printMaximum()
{
	cout << endl;
	sort(array,array+size,myCompare);
	for(int i=0;i<size;i++)
		cout << array[i];
}

// 8th September 2016
bool ArrayProblems :: areConsecutives()
{
	int max = getMax();
	int min = getMin();
	int temp;

	if(max - min + 1 == size)
	{
		for(int i=0;i<size;i++)
		{
			if(array[i] < 0)
				temp = -array[i] - min;
			else
				temp = array[i] - min;

			if(array[temp] > 0)
				array[temp] = -array[temp];
			else
				return false;
		}

		return true;
	}

	return false;
}

// 9th September 2016
// Longest Bitonic sequence
void ArrayProblems :: maxBitonicSeq()
{
	unsigned lis[size],lds[size];

	lis[0] = 1;
	lds[size-1] = 1;
	for(int i=1;i<size;i++)
	{
		if(array[i] > array[i-1])
			lis[i] = lis[i-1] + 1;
		else
			lis[i] = 1;
	}

	for(int i=size-2;i>=0;i--)
	{
		if(array[i] > array[i-1])
			lds[i] = lds[i+1] + 1;
		else
			lds[i] = 1;
	}

	unsigned max = lis[0] + lds[0] - 1;
	for(int i=1;i<size;i++)
	{
		if(lis[i]+lds[i]-1 > max)
			max = lis[i]+lds[i]-1;
	}

	cout << endl << "Maximum Bitonic Seq: " << max;
}

bool myCompare(string x,string y)
{
	return x+y > y+x; 
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

// 15th September 2016
// requires repeating numbers to be occuring in even count
void ArrayProblems :: findSingle()
{
	int res = 0;
	for(int i=0;i<size;i++)
		res = res ^ array[i];

	cout << endl << "Single: " << res;
}

// Construct original from Pair-Sum
// REQUIRES SIZE OF ORIGINAL ARRAY!
int *ArrayProblems :: constrOrig()
{
	int orig[size];
	// Here 'n' = size of the ORIGINAL array & not the pair[]
	orig[0] = (array[0]+array[1]-array[n-1])/2;
	for(int i=1;i<size;i++)
		orig[i] = array[i-1] - orig[0]; 


}

// 1st October 2016
// Shuffle Array
void ArrayProblems :: shuffleArray()
{
	srand(time(NULL));
	for(int i=n-1;i>0;i--){
		int j = rand() % (i+1);

		swap(&array[i],&array[j]);
	}
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

int ArrayProblems :: getMin()
{
	int max = array[0];
	for(int i=1;i<size;i++)
		if(max < array[i])
			max = array[i];

	return max;
}

int ArrayProblems :: getMax()
{
	int min = array[0];
	for(int i=1;i<size;i++)
		if(min > array[i])
			min = array[i];

	return min;
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