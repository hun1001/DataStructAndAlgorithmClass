#include <iostream>

using namespace std;

struct node
{
	int id;
	node* head;

	const bool operator == (const node& n)
	{
		return this->id == n.id;
	}
};

node nodes[1000001];

node* Find(node& n);
void Union(node& a, node& b);

node* Find(node& n)
{
	return n.head == &n ? &n : Find(*n.head);
}

void Union(node& a, node& b)
{
	node* headA = Find(a);
	node* headB = Find(b);

	headA->head = headA == headB ? headA : headB;
}

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i <= n; ++i)
	{
		nodes[i].id = i;
		nodes[i].head = &nodes[i];
	}

	for (int i = 0; i < m; ++i)
	{
		int op, v1, v2;
		cin >> op >> v1 >> v2;
		
		if (!op)
		{
			Union(nodes[v1], nodes[v2]);
		}
		else
		{
			if (Find(nodes[v1]) == Find(nodes[v2]))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	
	return 0;
}