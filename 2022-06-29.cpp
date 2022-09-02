#include <iostream>

using namespace std;

namespace MSCodingTest
{
	void DFS(int* arr, int level, int sum, int& cnt, int result);

	int main()
	{
		int n, m;
		int* arr;
		int cnt(0);

		cin >> n >> m;

		arr = new int[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		DFS(arr, 0, 0, cnt, m);

		if (cnt == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << cnt << endl;
		}

		delete[](arr);

		return 0;
	}

	void DFS(int* arr, int level, int sum, int& cnt, int result)
	{
		if (level == (sizeof(arr) / 2) + 1)
		{
			if (sum == result)
			{
				cnt++;
			}
		}
		else
		{
			DFS(arr, level + 1, sum + arr[level], cnt, result);
			DFS(arr, level + 1, sum - arr[level], cnt, result);
			DFS(arr, level + 1, sum, cnt, result);
		}
	}
}

int main()
{
	int n;
	int* arr;

	cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}



	delete[](arr);
	return 0;
}