#include <iostream>

using namespace std;

int t;
int ret;
int a[51][51];
int m, n, k, nx, ny;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool visited[51][51];
int x, y;

void dfs(int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
		{
			continue;
		}
		if (!visited[ny][nx] && a[ny][nx]==1)
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		fill_n(a[0], 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (!visited[i][j] && a[i][j] == 1)
				{
					++ret;
					dfs(i, j);
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}