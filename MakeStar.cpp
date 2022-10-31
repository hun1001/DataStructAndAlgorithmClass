#include <iostream>
#include <cmath>
using namespace std;

struct Vecter2
{
	int num;
	float x;
	float y;
};

struct Length
{
	int n1, n2;
	float length;
};

int Parent[101];

Vecter2 vec[101];
Length len[99999999];

int n;
int lenCnt = 0;

float sum = 0;

int Find(int num)
{
	return Parent[num] == vec[num].num ? vec[num].num : Find(Parent[num]);
}

void Union(int a, int b)
{
	int headA = Find(a);
	int headB = Find(b);

	Parent[headA] = headB;
}

int main()
{
	cout.precision(3);
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].x >> vec[i].y;
		vec[i].num = i;
		Parent[i] = vec[i].num;
	}

	const int lengthCount = n + (n * (n - 3) / 2);

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			len[lenCnt].n1 = vec[i].num;
			len[lenCnt].n2 = vec[j].num;
			len[lenCnt].length = sqrt(pow(vec[i].x - vec[j].x, 2) + pow(vec[i].y - vec[j].y, 2));
			lenCnt++;
		}
	}

	for(int i = 0;i<100;++i)
	{
		for (int j = 0; j < lengthCount - 1; ++j)
		{
			if (len[j].length > len[j + 1].length)
			{
				Length temp = len[j];
				len[j] = len[j + 1];
				len[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < lengthCount - 1; ++i)
	{
		if (Find(vec[i].num) != Find(vec[i + 1].num))
		{
			Union(vec[i].num, vec[i + 1].num);
			sum += len[i].length;
		}
	}

	cout << sum;
	
	return 0;
}