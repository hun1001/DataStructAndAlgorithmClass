#include <iostream>
using namespace std;

void PrtDoubleArr(int*, int);
void P1();

int main() {
	P1();
	
	
	return 0;
}

void P1() {
	int a[10][10] = { 0, };
	for (int i = 0; i < 10; i++) {
		a[i][0] = 1;
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < i; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < i; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
}

void PrtDoubleArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

		}
	}
}