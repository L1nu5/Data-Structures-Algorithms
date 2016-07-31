#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ExprConvertor
{
	string expr;
	vector<char> stack;
public:
	ExprConvertor();
	ExprConvertor(string);
	void toInfix();
	void toPrefix();
	void toPostfix();
	bool isOperand(char);
	int precOp(char);
};

ExprConvertor :: ExprConvertor(string exp)
{
	expr = exp;
}

int ExprConvertor :: precOp(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 2;

		case '^':
			return 3;
	}
	return -1;
}

bool ExprConvertor :: isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z');
}

void ExprConvertor :: toPostfix()
{
	vector <char> out;

	for(char& ch : expr)
	{
		if(isOperand(ch))
			out.push_back(ch);
		else if(ch == '(')
			stack.push_back(ch);
		else if(ch == ')')
		{
			while(!stack.empty() && (stack.back() != '('))
			{
				out.push_back(stack.back());
				stack.pop_back();
			}
			if(!stack.empty() && (stack.back() != '('))
				return ;
			else
				stack.pop_back();
		}
		else
		{
			while((!stack.empty()) && (precOp(ch) <= precOp(stack.back())))
			{
				out.push_back(stack.back());
				stack.pop_back();
			}

			stack.push_back(ch);
		}
	}

	while(!stack.empty())
	{
		out.push_back(stack.back());
		stack.pop_back();
	}

	cout << endl;
	for(char& ch : out)
	{
		cout << ch;
	}
	cout << endl;
}

int main()
{
	ExprConvertor e("a+b+c*d/e");
	e.toPostfix();
	return 0;
}