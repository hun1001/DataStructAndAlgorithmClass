#include <iostream>
using namespace std;

namespace NumSort1
{
	int N, n;
	int arr[1001] = {};

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (arr[i] > arr[j])
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			cout << arr[i] << "\n";
		}

		return 0;
	}
}

int N;

int main()
{
	
	return 0;
}