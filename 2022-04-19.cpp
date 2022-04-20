#include <iostream>
#include <stack>
using namespace std;

void P1();
void P2();
void P3();

int main() {
	P3();
	return 0;
}

void P1() {
	string str;
	stack<char> st;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		st.push(str[i]);
	}

	for (int i = 0; i < str.length(); i++) {
		cout << st.top();
		st.pop();
	}

	cout << endl;
}

void P2() {
	stack<stack<char>> st;
	string str[3];
	cin >> str[0] >> str[1] >> str[2];

	stack<char> temp;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < str[i].size(); j++) {
			temp.push(str[i][j]);
		}
		st.push(temp);
		while (!temp.empty())
		{
			temp.pop();
		}
	}

	while (!st.empty()) {
		while (!st.top().empty()) {
			cout << st.top().top();
			st.top().pop();
		}
		cout << endl;
		st.pop();
	}
}

void P3() {
	stack<char> s;
	string num;

	cin >> num;

	for (int i = num.length() - 1, cnt = 1; i >= 0; i--, cnt++) {
		s.push(num[i]);
		if (cnt % 3 == 0) {
			if (i == 0) {
				break;
			}
			s.push(',');
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}