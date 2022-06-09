#include <iostream>
#include <queue>
#include <stack>
using namespace std;

namespace Mongshell
{
	int main()
	{
		queue<int> q;
		int n, k;
		int cnt = 0;
		cin >> n >> k;

		for (int i = 1; i <= n; i++)
		{
			q.push(i);
		}

		while (q.size() != 1)
		{
			cnt++;
			if (cnt == k)
			{
				cnt = 0;
			}
			else
			{
				q.push(q.front());
			}
			q.pop();
		}

		cout << q.front() << endl;
		return 0;
	}
}

int main()
{
	stack<int> st;
	queue<char> q;
	int n;
	int* train;
	int cnt(1);
	bool isPossible = true;
	
	cin >> n;
	train = new int[n];
	for (int i = 0; i < n; i++) 
	{
		cin >> train[i];
	}

	st.push(train[0]);
	q.push('P');
	for (int i = 0;cnt <= n;i)
	{
		if (st.empty()&& i < n)
		{
			st.push(train[i++]);
		}
		if (st.top() == cnt)
		{
			++cnt;
			st.pop();
			q.push('O');
		}
		else
		{
			if (i >= n)
			{
				isPossible = false;
				break;
			}
			st.push(train[i++]);
			q.push('P');
		}
	}

	if (isPossible)
	{
		while (!q.empty())
		{
			cout << q.front();
			q.pop();
		}
	}
	else
	{
		cout << "impossible" << endl;
	}
}