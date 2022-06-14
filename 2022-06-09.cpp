#include <iostream>

using namespace std;

int main()
{
	int* arr;
	int minAge, maxAge;
	
	int left, right, middle;

	char* buffer = new char[5];
	
	cout << "������ �ּҰ�, �ִ밪 �Է�: ";
	cin >> minAge >> maxAge;
	cout << "���̰� �´ٸ� YES, �� ���ٸ� UP, �� ���ٸ� DOWN�� �Է��ϼ���." << endl << endl;

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
		cout << arr[middle] << "�� �Դϱ�?: ";
		cin >> buffer;
		if (left == right)
		{
			cout << "������ ���� �Ф�" << endl;
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
			cout << "�Ӷ� �úθ���" << endl;
			return 0;
		}
	}
}