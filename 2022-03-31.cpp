#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

int fiboMap[10000] = { 0, };
vector<int> numArr;

int Fibo(int n) {
	if (n == 0) {
		exit(-1);
	}
	if (fiboMap[n] > 0) {
		return fiboMap[n];
	}
	else {
		return (fiboMap[n] = Fibo(n - 2) + Fibo(n - 1));
	}
}

void Fibonacci3() {
	int num;
	while (true)
	{
		cin >> num;
		for (int i = numArr.size(); i < num; i++) {
			if (i == 0 || i == 1) {
				numArr.push_back(1);
			}
			else {
				numArr.push_back(numArr[i - 1] + numArr[i - 2]);
			}
		}
		cout << numArr[num-1] << endl;
	}
}

// �̿ϼ�
void Fibonacci4() {
	int i = 0;
	int temp = 0;
	int limit;
	vector<int> numUnion;
	fiboMap[1] = fiboMap[2] = 1;
	srand((unsigned int)time(NULL));
	int rnum = rand() % 10001;
	cout << "rnum : " << rnum << endl;
	for (i = 1;; i++) {
		temp = Fibo(i);
		if (temp > rnum) {
			break;
		}
	}
	// ����� �迭�� ������ �ε����� limit
	limit = i - 1;
	for (i = limit; i >= 0; i--) {
		temp = fiboMap[i];
		if(rnum - temp < 0) {
			continue;
		}
		else {
			numUnion.push_back(temp);
			rnum -= temp;
		}
	}
	if (rnum == 0) {
		for(vector<int>::iterator it = numUnion.begin(); it != numUnion.end(); it++) {
			if (*it != 0) {
				cout << *it << " ";
			}
		}
	}
	else {
		cout << -1 << endl;
	}
}

int main() {
	Fibonacci4();
}
