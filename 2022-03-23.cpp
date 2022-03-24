#include <iostream>
using namespace std;

void P2(int arr[100]);
void P3(int arr[100]);
void PrintArr(int arr[100]);

// 1단계만 해결

int main() {
	int arr[100] = { 0, };
	
}

void PrintArr(int arr[100]) {
	for (int i = 0; i < 100; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << " ";
		}
		if (i % 10 == 9) {
			cout << endl;
		}
	}
}

void P3(int arr[100]) {

}

void P2_2(int arr[100]) {
	int i1, i2;
	for (int i = 0; i < 100; i++) {
		i1 = i / 10;
		i2 = i % 10;
		if ((i1 * 10 + i2) % 10 == 0) {
			arr[i1 * 10 + i2] = 1;
			cout << endl;
		}
		else if (i1 > 0) {
			arr[i1 * 10 + i2] = arr[(i1 - 1) * 10 + i2] + arr[(i1 - 1) * 10 + (i2 - 1)];
		}
		if (arr[i] != 0)
		{
			cout << arr[i] << " ";
		}
	}
}

void P2_1(int arr[100]) {
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			arr[i] = 1;
		}
		else if (i >= 11) {
			arr[i] = arr[i - 10] + arr[i - 11];
		}
	}
	PrintArr(arr);
}