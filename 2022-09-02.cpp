#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Fac(int n) {
	if (n == 0) {
		return 1;
	}
	return n * Fac(n - 1);
}

int main()
{
	string str;
	string temp = "";
	vector<string> vec;
	
	getline(cin, str);
	
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		temp.push_back(*it);
		if (*it == ' ')
		{
			vec.push_back(temp);
			temp = "";
		}
	}

	if (temp != "")
	{
		vec.push_back(temp);
		temp = "";
	}
	
	for (int i = 0; i < Fac(vec.size()); ++i)
	{
		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			cout << *it;
		}
		vec.push_back(vec.front());
		vec.erase(vec.begin());
		cout << endl;
	}
	
	return 0;
}