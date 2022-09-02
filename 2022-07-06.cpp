#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	int time[3][2];
	int timeCnt(0);
	int lastTime(0);
	int money(0);

	int truckCnt(0);

	cin >> a >> b >> c;
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> time[i][j];
			if (time[i][j] > lastTime)
			{
				lastTime = time[i][j];
			}
		}
	}

	for (int i = 1; i <= lastTime; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (time[j][0] <= i && i < time[j][1])
			{
				++truckCnt;
			}
		}

		switch (truckCnt)
		{
		case 1:
			money += a;
			break;
		case 2:
			money += (b * 2);
			break;
		case 3:
			money += (c * 3);
			break;
		default:
			break;
		}

		truckCnt = 0;
	}

	cout << money << endl;
	return 0;
}