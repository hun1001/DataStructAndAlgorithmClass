#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	const string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int answer = 0;
	
	for (int i = 0; i < 10; ++i)
	{
		while (s.find(numbers[i]) != string::npos)
		{
			s.replace(s.find(numbers[i]), numbers[i].length(), to_string(i));
		}
	}
	
	answer = stoi(s);
	
    return answer;
}

int main()
{
	cout << solution("one4seveneight") << endl;
}