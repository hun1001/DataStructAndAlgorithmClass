#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

int fiboMap[10000] = { 0, };
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
	vector<int> numArr;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		if (i == 0 || i == 1) {
			numArr.push_back(1);
		}
		else {
			numArr.push_back(numArr[i - 1] + numArr[i - 2]);
		}
	}
	cout << numArr[numArr.size() - 1] << endl;
}

// 미완성
void Fibonacci4() {
	int i = 0;
	int temp = 0;
	int limit;
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
	// 사용할 배열의 마지막 인덱스는 limit
	limit = i - 1;
	rnum -= fiboMap[i];
}

int main() {
	Fibonacci3();
}
