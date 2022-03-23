#include <iostream>
using namespace std;

void P2(int arr[100]);
void P3(int arr[100]);
void PrintArr(int arr[100]);

int main() {
	int arr[100] = { 0, };
	int i1, i2;
	for (int i = 0; i < 100; i++) {
		i1 = i / 10;
		i2 = i % 10;
		cout << i1 * 10 + i2 << " ";
	}
	PrintArr(arr);
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
	int index = 0, indey = 0;
	for (int i = 0; i < 100; i++) {
		indey = ((i / 10) * 10);
		index = (i % 10);
		if (index == 0) {
			arr[i] = 1;
		}
		else if (i >= 11) {
			arr[i] = arr[(indey-1)*10 + index - 1] + arr[((indey - 1) * 10) + indey];
		}
	}
}

void P2(int arr[100]) {
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			arr[i] = 1;
		}
		else if (i >= 11) {
			arr[i] = arr[i - 10] + arr[i - 11];
		}
	}
}