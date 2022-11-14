#include <iostream>
#include <map>
#include <string>


using namespace std;

namespace BestSeller
{
	int N;
	string str;
	string bestSeller;

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		map<string, int> m;

		cin >> N;

		for (int i = 0; i < N; ++i)
		{
			cin >> str;
			m[str]++;
		}

		for (const auto& it : m)
		{
			if (it.second > m[bestSeller])
			{
				bestSeller = it.first;
			}
		}

		cout << bestSeller << "\n";

		return 0;
	}
}

int N;
int M;
map<string, string> m;
map<string, string> m2;
string temp = "";

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> temp;
		m[to_string(i)] = temp;
		m2[temp] = to_string(i);
	}

	for (int i = 1; i <= M; ++i)
	{
		cin >> temp;
		if (m.find(temp) == m.end())
		{
			cout << m2[temp] << "\n";
			
		}
		else
		{
			cout << m[temp] << "\n";
		}
	}
}