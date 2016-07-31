/**
 * Stack based problem
 * Next Greater element
 * (Note: Remember it's Greater element & NOT The GREATEST)
 */

#include <iostream>
#include <vector>

using namespace std;

class NGEFinder
{
	vector <int> stack,array;
public:
	void findNGE();
	void getArray();
};

void NGEFinder :: findNGE()
{
	int next;

	stack.push_back(array[0]);
	for(int i=1;i<array.size();i++)
	{
		next = array[i];
		if(!stack.empty())
		{
			int ele = stack.back();
			stack.pop_back();
			while(ele < next)
			{
				cout << endl << ele << " ---> " << next;
				ele = stack.back();
				stack.pop_back();
			}
			if(ele > next)
				stack.push_back(ele);
		}

		stack.push_back(next);
	}
}

int main()
{
	NGEFinder nge;
	nge.findNGE();

	return 0;
}