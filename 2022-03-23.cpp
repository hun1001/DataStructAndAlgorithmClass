#include <iostream>
using namespace std;

int main() {
	int arr[100] = { 0, };

	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			arr[i] = 1;
		}
		else if (i >= 11) {
			arr[i] = arr[i - 10] + arr[i - 11];
		}
	}

	// 배열 프린트해주는 코드
	for (int i = 0; i < 100; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << " ";
		}
		if (i % 10 == 9) {
			cout << endl;
		}
	}

}