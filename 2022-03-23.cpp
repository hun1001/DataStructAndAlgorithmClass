#include <iostream>
using namespace std;

void P2(int arr[100]);
void P3(int arr[100]);
void PrintArr(int arr[100]);

// 1단계만 해결

int main() {
	int arr[100] = { 0, };
	int i1, i2;
	for (int i = 0; i < 100; i++) {
		i1 = i / 10;
		i2 = i % 10;
		cout << i1 * 10 + i2 << " ";
	}
	PrintArr(arr);
	// 2단계는 문제의 목적에 맞게 해결했으나 갑자기 문제에 없던 컴플레인이 들어와 수정하던중 시간이 없는 관계로 보다는 실력 부족으로 완성 못함 위에 반복문은 어떤 느낌으로 해결할 것인지 적어둔 것입니다.
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