#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int N_arr[100000] = {};
int M_arr[100000] = {};

void MergeSort(int arr[], int left, int right)
{
	// 모르겠다
}

int BinarySearch(int arr[], int left, int right, int target)
{
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid] == target)
		{
			return 1;
		}
		else if (arr[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return 0;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> N_arr[i];
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> M_arr[i];
	}

	//MergeSort(N_arr, 0, N - 1);
	sort(N_arr, N_arr + N);

	for (int i = 0; i < M; ++i)
	{
		cout << BinarySearch(N_arr, 0, N - 1, M_arr[i]) << "\n";
	}
}