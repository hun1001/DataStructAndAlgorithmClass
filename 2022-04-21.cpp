#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;
	string mathE;
	int result(0);
	int iMemory;
	char cMemory;
	
	getline(cin, mathE);

	for (int i = 0; i < mathE.length(); i++)
	{
		cMemory = mathE[i];
		switch (cMemory)
		{
		case '+':
			iMemory = st.top();
			st.pop();
			iMemory += st.top();
			st.pop();
			st.push(iMemory);
			break;
		case '-':
			iMemory = st.top();
			st.pop();
			iMemory -= st.top();
			st.pop();
			st.push(iMemory);
			break;
		case '*':
			iMemory = st.top();
			st.pop();
			iMemory *= st.top();
			st.pop();
			st.push(iMemory);
			break;
		case '/':
		{
			iMemory = st.top();
			st.pop();
			int iMemoryT = st.top();
			st.pop();
			st.push(iMemoryT / iMemory);
		}
			break;
		default:
			switch (cMemory)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				st.push(cMemory - '0');
				break;
			default:
				break;
			}
			break;
		}
	}
	
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}