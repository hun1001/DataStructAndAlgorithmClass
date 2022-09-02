#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec(100);

	for (int i = 0; i < vec.capacity(); ++i)
	{
		vec.at(i) = i + 1;
	}

	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		
		cout << *i << " ";
	}

	cout << endl;
	
	for (auto i = vec.rbegin(); i != vec.rend(); ++i)
	{
		cout << *i << " ";
	}
	
	cout << endl;
	
	for(auto i : vec)
	{
		cout << i << " ";
	}
	
	return 0;
}