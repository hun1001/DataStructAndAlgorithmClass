#include <iostream>
#include <stack>
using namespace std;

void P1();

int main()
{
	stack<char> s;
	string me;
	
	int parenthesesCnt(0);
	int curlyBrackets(0);
	int squareBrackets(0);
	
	cin >> me;

	for(string::iterator it = me.begin(); it != me.end(); it++)
	{
		switch (*it)
		{
		case '(':
			s.push('(');
			parenthesesCnt++;
			break;
		case '{':
			s.push('{');
			curlyBrackets++;
			break;
		case '[':
			s.push('[');
			squareBrackets++;
			break;
		case ')':
			if(s.top() == '(')
			{
				s.pop();
				parenthesesCnt--;
			}
			else
			{
				cout << "괄호 검사 실패" << endl;
				return 0;
			}
			break;
		case '}':
			if(s.top() == '{')
			{
				s.pop();
				curlyBrackets--;
			}
			else
			{
				cout << "괄호 검사 실패" << endl;
				return 0;
			}
			break;
		case ']':
			if(s.top() == '[')
			{
				s.pop();
				squareBrackets--;
			}
			else
			{
				cout << "괄호 검사 실패" << endl;
				return 0;
			}
			break;
		default:
			break;
		}
	}

	cout << "괄호 검사 성공" << endl;
	return 0;
}

void P1()
{
	string bracket;
	stack<char> s;

	int cnt = 1;

	cout << "수식\t\t: ";
	cin >> bracket;

	cout << "괄호 번호\t: ";

	for (int i = 0; i < bracket.length(); i++)
	{
		if (bracket[i] == '(')
		{
			cout << cnt;
			s.push(cnt++);
		}
		else if (bracket[i] == ')')
		{
			cout << (int)s.top();
			s.pop();
		}
	}
}