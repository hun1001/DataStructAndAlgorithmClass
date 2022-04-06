#include <iostream>
using namespace std;

int GetMaxInArr(int* arr, int i = 0, int max = 0)
{
	if (i == 0)
	{
		max = arr[0];
	}
	if (arr[i] > max)
	{
		max = arr[i];
	}
	if (i == 4)
	{
		return max;
	}
	return GetMaxInArr(arr, i + 1, max);
}

int FindMaxNum() {
	int num[5];
	cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
	cout << GetMaxInArr(num) << endl;
	return 0;
}

int FindGreatestCommonFactor(int x, int y) {
	int temp = x % y;
	if (temp == 0)
	{
		return y;
	}
	return FindGreatestCommonFactor(y, temp);
}

int GreatestCommonFactor() {
	int x, y;
	cin >> x >> y;
	cout << FindGreatestCommonFactor(x, y) << endl;
	return 0;
}


// 이거 4번인데 미완임
int Combination(int n, int r)
{
	if(n == 0)
	{
		return 1;
	}
	return (n/((n-r)*r)) * Combination(n-1, r-1);
}

int main() {
	int n, r;
	cin >> n >> r;
	
	cout << Combination(n, r) << endl;
	return 0;
}