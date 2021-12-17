//	Hesham Mohamed Mohamed
//	Created Date: 21 Aug, 2021
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkClosing(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '[' && close == ']')
		return true;
	else
		return false;

}
bool isBalanced(string exp)
{
	stack<char>s;
	for (size_t i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			s.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (s.empty() || !checkClosing(s.top(), exp[i]))
				return false;
			else
				s.pop();
		}
	}
	return s.empty() ? true : false;
}
int main()
{
	string expression;
	char x;
	do {
		cout << "Enter the expression:\n";
		cin >> expression;
		if (isBalanced(expression))
			cout << "BALANCED\n";
		else
			cout << "NOT BALANCED\n";
		cout << "Wanna try again!!  press(y/n)\t";
		cin >> x;
		cout << endl;
	} while (x = 'y');
	system("pause");
	return 0;
}
