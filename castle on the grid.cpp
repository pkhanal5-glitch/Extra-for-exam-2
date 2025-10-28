//castle on the grid-medium
#include <bits/stdc++.h>
using namespace std;

static int minimumMoves(const vector<string>& grid, int sx, int sy, int gx, int gy) {
    const int n = (int)grid.size();
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    queue<pair<int,int>> q;

    dist[sx][sy] = 0;
    q.push({sx, sy});

    // Why BFS with sliding: each cell enqueued once; sliding adds one move regardless of squares crossed
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == gx && y == gy) return dist[x][y];

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            // slide in a straight line until blocked
            while (0 <= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] == '.') {
                if (dist[nx][ny] == INF) {            // Why: only push first time to keep O(n^2)
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
                nx += dx[d]; ny += dy[d];
            }
        }
    }
    return -1; // unreachable (shouldn't happen with valid inputs)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    if (sx == gx && sy == gy) {
        cout << 0 << '\n';
        return 0;
    }

    cout << minimumMoves(grid, sx, sy, gx, gy) << '\n';
    return 0;
}
