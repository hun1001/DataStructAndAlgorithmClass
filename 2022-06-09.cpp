#include <iostream>

using namespace std;

int main()
{
	int* arr;
	int minAge, maxAge;
	
	int left, right, middle;

	char* buffer = new char[5];
	
	cout << "나이의 최소값, 최대값 입력: ";
	cin >> minAge >> maxAge;
	cout << "나이가 맞다면 YES, 더 많다면 UP, 더 적다면 DOWN을 입력하세요." << endl << endl;

	arr = (int*)malloc(sizeof(int) * (maxAge - minAge + 1));
	left = 0;
	right = maxAge - minAge;
	middle = (left + right) / 2;


	for (int i = 0;i<(maxAge-minAge+1);++i)
	{
		arr[i] = minAge + i;
	}

	while (true) {
		cout << "Searching range: " << arr[left] << "-" << arr[right] << endl;
		cout << arr[middle] << "살 입니까?: ";
		cin >> buffer;
		if (left == right)
		{
			cout << "속이지 마요 ㅠㅠ" << endl;
			return 0;
		}
		if (strcmp(buffer, "UP")==0)
		{
			left = middle + 1;
			middle = (left + right) / 2;
		}
		else if (strcmp(buffer, "DOWN") == 0)
		{
			right = middle - 1;
			middle = (left + right) / 2;
		}
		else if (strcmp(buffer, "YES") == 0)
		{
			cout << "LOL" << endl;
			return 0;
		}
		else
		{
			cout << "머라 시부리노" << endl;
			return 0;
		}
	}
}