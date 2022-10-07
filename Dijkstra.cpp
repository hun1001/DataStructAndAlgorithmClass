using namespace std;

#include <iostream>
#include <vector>
#include <queue>

#define MAX_VTXS	256	
//const int INF = 987654321;
#define INF 99999
int V, E, start, u, v, w;
vector<pair<int, int>> weight[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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
		{
			for (int j = 0; j < MAX_VTXS; j++)
			{
				setEdge(i, j, INF);
			}
		}
	}

	void insertVertex(char value)
	{
		vertices[size++] = value;
	}

	void insertEdge(int i, int j, int weight)
	{
		setEdge(i, j, weight);
		setEdge(j, i, weight);
	}

	void display()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << vertices[i] << "  ";
			for (int j = 0; j < size; ++j)
			{
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}
};

class shortestPath : public AdjMatGraph
{
	int dist[MAX_VTXS];
	bool found[MAX_VTXS];

	int parent[MAX_VTXS];

public:
	void PrintDistance()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << dist[i] << " ";
		}
		cout << endl;
	}

	int ChooseVertex()
	{
		int min = INF;
		int minpos = -1;
		for (int i = 0; i < size; ++i)
		{
			if (dist[i] < min && !found[i])
			{
				min = dist[i];
				minpos = i;
			}
		}
		return minpos;
	}

	void reset(int start)
	{
		for (int i = 0; i < size; ++i)
		{
			dist[i] = getEdge(start, i);
			found[i] = false;
		}
		fill_n(parent, size, -1);
		found[start] = true;
		dist[start] = 0;
		parent[start] = start;
	}
	
	void dijikstra(int start)
	{
		reset(start);
		for (int i = 0; i < size; ++i)
		{
			cout << "Step " << i + 1 << " : ";
			PrintDistance();
			int u = ChooseVertex();
			found[u] = true;

			for (int w = 0; w < size; ++w)
			{
				if (!found[w] && dist[w] > dist[u] + getEdge(w, u))
				{
					dist[w] = dist[u] + getEdge(w, u);
				}
			}
		}
	}

	void dijikstra(int start, int end)
	{
		reset(start);
		int next = -1;
		cout << start << " 정점에서 시작!" << endl;
		for (int i = 0; i < size; ++i)
		{
			if (next == end)
			{
				cout << "목적 정점 " << end << "에 도착" << endl;
				break;
			}
			cout << "Step " << i + 1 << " : ";
			PrintDistance();
			next = ChooseVertex();
			if (i == 0)
			{
				parent[next] = start;
			}
			cout << next << " 정점 최단경로 확정!" << endl;
			found[next] = true;

			for (int w = 0; w < size; ++w)
			{
				if (found[w] == false)
				{
					if (dist[next] + getEdge(next, w) < dist[w])
					{
						dist[w] = dist[next] + getEdge(next, w);
						parent[w] = next;
					}
				}
			}
		}

	}

	void printPath(int start, int target)
	{
		if (start == target)
		{
			cout << "최단 경로는 " << start;
			return;
		}
		printPath(start, parent[target]);
		cout << " " << target;
	}
};

vector<int> dijkstra(int start, int vertex)
{
	vector<int> dist(vertex, INF);
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (!pq.empty())
	{
		int now = pq.top().second;
		int sToNow = pq.top().first;
		pq.pop();

		if (dist[now] != sToNow)continue;
		
		for (auto n : weight[now])
		{
			int neighbor = n.second;
			int NowToNeighbor = n.first;
			if (dist[neighbor] > sToNow + NowToNeighbor)
			{
				dist[neighbor] = sToNow + NowToNeighbor;
				pq.push(make_pair(dist[neighbor], neighbor));
			}
		}
	}
	return dist;
}


int main()
{
#pragma region 주석
	/*shortestPath g;
	for (int i = 0; i < 4; ++i)
	{
		g.insertVertex('A' + 1);
	}*/

	/*g.insertEdge(0, 1, 2);
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

	g.dijikstra(0);*/
	
	
	/*g.insertEdge(0, 1, 2);
	g.insertEdge(0, 2, 7);
	g.insertEdge(1, 2, 1);
	g.insertEdge(1, 3, 3);
	g.insertEdge(3, 2, 2);

	g.dijikstra(0, 2);	
	g.printPath(0, 2);*/
#pragma endregion
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> start;

	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v >> w;
		weight[u].emplace_back(w, v);
	}

	//cout << "\n";
	vector<int> result = dijkstra(start, V + 1);

	for (int i = 1; i <= V; ++i)
	{
		if (result[i] == INF)cout << "INF\n";
		else cout << result[i] << "\n";
	}
	return 0;
}