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

namespace NumSort2
{
	int N;
	int arr[1000001] = {};
	int temp[1000001] = {};

	void MergeSort(int arr[], int left, int right)
	{
		int mid;
		int i, j, k, l;

		if (left < right)
		{
			mid = (left + right) / 2;
			MergeSort(arr, left, mid);
			MergeSort(arr, mid + 1, right);

			i = left;
			j = mid + 1;
			k = left;

			while (i <= mid && j <= right)
			{
				if (arr[i] <= arr[j])
				{
					temp[k++] = arr[i++];
				}
				else
				{
					temp[k++] = arr[j++];
				}
			}

			if (i > mid)
			{
				for (l = j; l <= right; l++)
				{
					temp[k++] = arr[l];
				}
			}
			else
			{
				for (l = i; l <= mid; l++)
				{
					temp[k++] = arr[l];
				}
			}

			for (l = left; l <= right; l++)
			{
				arr[l] = temp[l];
			}
		}
	}

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N;

		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}

		MergeSort(arr, 0, N - 1);

		for (int i = 0; i < N; ++i)
		{
			cout << arr[i] << "\n";
		}

		return 0;
	}
}

namespace NumSort3
{
	int N, n;
	int arr[10001];

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N;

		for (int i = 0; i < N; ++i)
		{
			cin >> n;
			arr[n]++;
		}

		for (int i = 1; i <= 10000; ++i)
		{
			if (arr[i] > 0)
			{
				while (arr[i] > 0)
				{
					cout << i << "\n";
					arr[i]--;
				}
			}
		}

		return 0;
	}
}