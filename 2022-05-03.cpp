#include "CircleQueue.h"
using namespace std;

// ���⼭ ��Ŀ ���� CircleQueue ������� �ҷ��ö� ��������µ�

int main()
{
	CircleQueue<int> q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);

	cout << q.get_count() << endl;
}