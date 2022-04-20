#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
	T* stackArr;
	int topIndex;
public:
	Stack()
	{
		topIndex = -1;
		stackArr = new T[0];
	}
	
	void Push(T value) {
		topIndex += 1;
		T* newStackArr = new T[topIndex + 1];
		newStackArr = stackArr;
		newStackArr[topIndex] = value;
	}

	T Pop() {
		return stackArr[topIndex--];
	}
};

int main() {
	Stack<char> A;
	A.Push('a');
	A.Push('b');
	A.Push('c');
	A.Push('d');
	
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
}

// ¹Ì¿Ï¼º