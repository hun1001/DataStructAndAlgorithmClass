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
		for (int j = 0; j < i; j++) {
			if (j == 0) {
				a[i][j] = 1;
			}
			if (i > 0 && j > 0) {
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void PrtDoubleArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

		}
	}
}