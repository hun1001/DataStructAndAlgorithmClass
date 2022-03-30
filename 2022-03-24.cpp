#include <iostream>
using namespace std;

int FindLast(char* c);

int main() {
	char str[3][100] = { '\0', };
	int cnt = 1;
	int r = 0;
	int length(0);

	cin >> str[0];
	cin >> str[1];
	cin >> str[2];

	for (int i = 0; i < 3; i++) {
		length = FindLast(str[i]);
		r = length;
		for (int j = 0; j < length/2; i++)
		{
			swap(str[i][j], str[i][r]);
			r--;
			if (r < 0) {
				break;
			}
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		cout << str[i] << endl;
	}
}

int FindLast(char* c) {
	for (int i = 0; i < 100; i++) {
		if (c[i] == NULL) {
			return i;
		}
	}
	exit(-1);
}