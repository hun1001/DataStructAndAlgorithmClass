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

int Factorial(int num) {
	if (num == 1) {
		return 1;
	}
	return num * Factorial(num - 1);
}

int Combination(int n, int r)
{
	return (Factorial(n)/(Factorial(n-r)*Factorial(r)));
}

int FindCombination() {
	int n, r;
	cin >> n >> r;
	
	cout << Combination(n, r) << endl;
	return 0;
}

int main() {
	//return FindMaxNum();
	//return GreatestCommonFactor();
	return FindCombination();
}