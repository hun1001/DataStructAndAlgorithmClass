#include <iostream>
#include <queue>
using namespace std;

struct edge
{
	unsigned int v1;
	unsigned int v2;
};

struct vertex
{
	unsigned int id;
	bool visited;
};

edge e[100000];
vertex v[1000];

int N, M, V;
int n1, n2;

bool isLinked(int v1, int v2)
{
	for (int i = 0; i < M; ++i)
	{		
		if ((e[i].v1 == v[v1].id && e[i].v2 == v[v2].id)|| (e[i].v1 == v[v2].id && e[i].v2 == v[v1].id))
		{
			return true;
		}
	}
	return false;
}

void DFS(int sv)
{
	v[sv].visited = true;
	cout << v[sv].id << " ";
	for (int i = 0; i < M; ++i)
	{
		if (isLinked(sv, i) && v[i].visited == false)
		{
			DFS(i);
		}
	}
}

void BFS(int sv)
{
	
}

int main()
{
	cin >> N >> M >> V;
	
	for (int i = 0; i < N; ++i)
	{
		v[i].id = i + 1;
		v[i].visited = false;
	}
	
	for (int i = 0; i < M; ++i)
	{
		cin >> n1 >> n2;
		e[i].v1 = n1;
		e[i].v2 = n2;
	}
	
	DFS(0);
	BFS(0);
	
	return 0;
}