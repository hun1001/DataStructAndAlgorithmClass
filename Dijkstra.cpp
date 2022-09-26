#include <iostream>
#define MAX_VTXS 255

using namespace std;

class AdjMatGraph
{
protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }

	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	void reset()
	{
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}

	void insertVertex(char name)
	{
		if (!isFull())
			vertices[size++] = name;
	}

	void insertEdge(int u, int v)
	{
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}

	void display()
	{
		cout << "  ";
		for (int i = 0; i < size; i++)
			cout << getVertex(i) << " ";
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << getVertex(i) << " ";
			for (int j = 0; j < size; j++)
				cout << getEdge(i, j) << " ";
			cout << endl;
		}
	}
};

class shortestPath : public AdjMatGraph
{
	int dist[MAX_VTXS];
	bool found[MAX_VTXS];
public:
	void printDistance()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << dist[i] << " ";
		}
		cout << endl;
	}

	int chooseVertex()
	{
		int min = INFINITY;
		int minpos = -1;
		for (int i = 0; i < size; ++i)
		{
			if (dist[i] > min && !found[i])
			{
				min = dist[i];
				minpos = i;
			}
		}
		return minpos;
	}

	void insertEdge(int i, int j, int v)
	{
		AdjMatGraph::setEdge(i, j, v);
		AdjMatGraph::setEdge(j, i, v);
	}

	void dijikstra(int start)
	{
		for (int i = 0; i < size; ++i)
		{
			dist[i] = getEdge(start, i);
			found[i] = false;
		}
		found[start] = true;
		dist[start] = 0;
		for (int i = 0; i < size; ++i)
		{
			cout << "Step " << i + 1 << " : ";
			printDistance();
			int u = chooseVertex();
			found[u] = true;
			for (int w = 0; w < size; ++w)
			{
				if (!found[w] && dist[u] < dist[w] + getEdge(w, u))
				{
					dist[w] = dist[u] + getEdge(w, u);
				}
			}
		}
	};
};

int main()
{
	shortestPath g;
	for (int i = 0; i < 7; ++i)
	{
		g.insertVertex('A' + i);
	}
	g.insertEdge(0, 1, 2);
	g.insertEdge(0, 2, 7);
	g.insertEdge(1, 2, 1);
	g.insertEdge(1, 3, 3);
	g.insertEdge(2, 4, 4);
	g.insertEdge(2, 5, 5);
	g.insertEdge(3, 2, 2);
	g.insertEdge(3, 4, 3);
	g.insertEdge(4, 5, 4);
	g.insertEdge(4, 6, 1);
	g.insertEdge(5, 6, 5);
	g.dijikstra(0);
}