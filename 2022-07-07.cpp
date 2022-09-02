#include<iostream>

using namespace std;

namespace ¿Ø±‚≥ÛπË√ﬂ
{
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };
    int m, n, k, y, x, ret, ny, nx, t;
    int a[51][51];
    bool visited[51][51];
    void dfs(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i)
        {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (a[nx][ny] == 1 && !visited[nx][ny]) dfs(nx, ny);
        }
        return;
    }

    int main() {
        cin >> t;
        while (t--) {
            fill(&a[0][0], &a[0][0] + 51 * 51, 0);
            fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
            ret = 0;
            cin >> m >> n >> k;
            for (int i = 0; i < k; i++) {
                cin >> x >> y;
                a[x][y] = 1;
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 1 && !visited[i][j]) {
                        dfs(i, j);
                        ret++;
                    }
                }
            }
            cout << "result: " << ret << endl;
        }
        return 0;
    }
}



namespace ¡÷∏˘
{
    int main()
    {
        int n, m;
        int* num;
        int cnt(0);

        cin >> n >> m;

        num = new int[n];

        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (num[i] + num[j] == m)
                {
                    ++cnt;
                }
            }
        }

        cout << cnt << endl;

        return 0;
    }
}

int main()
{
    return ¿Ø±‚≥ÛπË√ﬂ::main();
}
