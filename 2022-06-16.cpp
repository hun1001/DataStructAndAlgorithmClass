#include <iostream>
#include <vector>

using namespace std;

class PriorithyQueue
{
private:
	vector<int> m_heap;
public:
	int top()
	{
		return m_heap[0];
	}

	bool empty()
	{
		return m_heap.empty();
	}

	void push(int data)
	{
		m_heap.push_back(data);
		int now = m_heap.size() - 1;
		while (now > 0)
		{
			int next = (now - 1) / 2;
			if (m_heap[now] < m_heap[next]) break;
			swap(m_heap[now], m_heap[next]);
			now = next;
		}
	}

	void pop()
	{
		m_heap[0] = m_heap.back();
		m_heap.pop_back();
		int parent = 0;
		int child = 1;
		if (m_heap.size() == 0)	return;
		while (child <= m_heap.size() - 1) {
			if(child < m_heap.size() - 1) 
				if(m_heap[child] < m_heap[child + 1])
					child++;
			if (m_heap[parent] > m_heap[child]) break;
			swap(m_heap[parent], m_heap[child]);
			parent = child;
			child = 2 * parent + 1;
		}
	}
};

int main()
{
	PriorithyQueue pq;
	pq.push(100);
	pq.push(300);
	pq.push(200);
	pq.push(500);
	pq.push(400);

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}