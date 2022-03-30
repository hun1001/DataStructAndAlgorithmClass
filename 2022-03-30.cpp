#include <iostream>
using namespace std;

void HanoiTower(int num, char from, char by, char to) {
	if (num == 1) {
		cout << "원반1을 " << from << "에서 " << to << "로 이동" << endl;
	}
	else {
		HanoiTower(num - 1, from, to, by);
		cout << "원반" << num << "을(를) " << from << "에서 " << to << "로 이동";
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

int main() {
	int num;
	cin >> num;
	cout <<	Fibonacci(num);
	return 0;
}