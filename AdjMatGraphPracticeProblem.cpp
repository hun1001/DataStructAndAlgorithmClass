#include <iostream>
#include <vector>

using namespace std;

#define MAX_VTXS 256

namespace NOVECTOR
{
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
}

namespace USEVECTOR
{
	class AdjMatGraph
	{
	protected:
		int size;
		vector<char> vertices;
		vector<vector<int>> adj;
	public:
		AdjMatGraph() { reset(); }
		AdjMatGraph(int n) { reset(n); }

		char getVertex(int i) { return vertices[i]; }
		int getEdge(int i, int j) { return adj[i][j]; }
		
		void setEdge(int i, int j, int val) 
		{
			/*vector<int>* temp = &adj[i];
			(*temp)[j] = val;*/
			adj[i][j] = val;
		}
		
		bool isEmpty() { return size == 0; }
		bool isFull() { return size >= MAX_VTXS; }
		
		void reset()
		{
			size = 0;
			for (int i = 0; i < MAX_VTXS; i++)
				for (int j = 0; j < MAX_VTXS; j++)
					setEdge(i, j, 0);
		}

		void reset(int n)
		{
			size = 0;
			vertices.resize(n);
			adj.resize(n);
			for (int i = 0; i < n; i++)
				adj[i].resize(n);

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
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
}

int main()
{
	
	USEVECTOR::AdjMatGraph g(4);
	
	for (int i = 0; i < 4; i++)
	{
		g.insertVertex('A' + i);
	}
	
	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);

	cout << "인접 행렬로 표현한 그래프" << endl;
	g.display();
	
	return 0;
}