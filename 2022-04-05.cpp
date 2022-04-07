#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int* iArr;

void OddNumPrt(int x, int y) {
	if (x >= y) return;
	if (x % 2 == 1){
		arr.push_back(x);
	}
	OddNumPrt(x + 1, y);
}

/// <summary>
/// ���ο� ����ϴ�
/// </summary>
/// <returns></returns>
int UseVector() {
	int x, y;
	cout << "���� ������ �� ���� �Է��Ͻÿ� : " << endl;
	cin >> x >> y;
	OddNumPrt(x+1, y);
	for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}

void OddNumPrtUseArr(int x, int y, int i = 0) {
	if (x >= y) return;
	if (x % 2 == 1) {
		iArr[i++] = x;
	}
	OddNumPrtUseArr(x + 1, y, i);
}

/// <summary>
/// ���ο� ����ϴ�
/// </summary>
/// <returns></returns>
int UseArr() {
	int x, y;
	cout << "���� ������ �� ���� �Է��Ͻÿ� : " << endl;
	cin >> x >> y;
	int iArrSize = (y - x) / 2;
	iArr = new int[iArrSize];
	OddNumPrtUseArr(x + 1, y);

	for(int i = 0;i < iArrSize - 1; i++) {
		cout << iArr[i] << " ";
	}
	
	return 0;
}

// 2�� ������ ����������
int main() {
	//UseVector();
	UseArr();
	return 0;
}