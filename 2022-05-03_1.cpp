#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	int num;
	cout << "출력할 피보나치 수열의 개수를 입력하시오 : ";
	cin >> num;

	int temp1, temp2;
	
	for(int i = 0; i < num; i++)
	{
		if (i <= 1)
		{
			q.push(1);
			temp1 = 1;
			temp2 = 1;
		}
		else
		{
			q.push(temp1 + temp2);
			temp2 = temp1;
			temp1 = q.back();
		}
	}

	for (int i = 0; i < num; i++)
	{
		cout << q.front() << " ";
		q.pop();
	}
}