#include <iostream>
using namespace std;

void HanoiTower(int num, char from, char by, char to) {
	if (num == 1) {
		cout << "����1�� " << from << "���� " << to << "�� �̵�" << endl;
	}
	else {
		HanoiTower(num - 1, from, to, by);
		cout << "����" << num << "��(��) " << from << "���� " << to << "�� �̵�";
		HanoiTower(num - 1, by, from, to);
	}
}

int Factorial(int num) {
	if (num == 1) {
		return 1;
	}
	return num * Factorial(num - 1);
}

int Fibonacci(int num) {
	if (num == 1 || num == 2) {
		return 1;
	}
	else {
		return Fibonacci(num - 1) + Fibonacci(num - 2);
	}
}

int FibonacciUseArr(int num)  {
	static int arr[10000] = { NULL, };
	if (arr[num] != NULL) {
		return arr[num];
	}
	else {
		if (num == 1 || num == 2) {
			return 1;
		}
		else {
			return arr[num] = Fibonacci(num - 1) + Fibonacci(num - 2);
		}
	}
}

int main() {
	int num;
	cin >> num;
	cout <<	FibonacciUseArr(num);
	return 0;
}