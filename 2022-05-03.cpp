#include "CircleQueue.h"
using namespace std;

// 여기서 링커 오류 CircleQueue 헤더파일 불러올때 문제생기는듯

int main()
{
	CircleQueue<int> q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);

	cout << q.get_count() << endl;
}