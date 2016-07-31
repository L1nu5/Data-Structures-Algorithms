#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BracketsEval
{
	vector<char> stack;
public:
	bool verifyExpr(string);
};


bool BracketsEval :: verifyExpr(string str)
{
	for(char& ch : str)
	{
		if((ch == '(') || (ch == '{') || (ch == '['))
			stack.push_back(ch);
		else if((ch == ')') || (ch == '}') || (ch == ']'))
		{
			char ex = stack.back();
			if((ex == '(' && ch == ')') || (ex == '[' && ch == ']') || (ex == '{' && ch =='}'))
				stack.pop_back();
			else
				return false;
		}
	}
	return true;
}


int main()
{
	BracketsEval be;
	cout << be.verifyExpr("()()()") << endl;
	cout << be.verifyExpr("()()()") << endl;
	cout << be.verifyExpr("()()()") << endl;
	cout << be.verifyExpr("{([)}]") << endl;
	return 0;
}