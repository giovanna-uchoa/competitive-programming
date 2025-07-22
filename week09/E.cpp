#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int even_dx[] = {0, 0, 1, 1, -1, -1};
const int even_dy[] = {-1, 1, -1, 0, -1, 0};

const int odd_dx[] = {0, 0, 1, 1, -1, -1};
const int odd_dy[] = {-1, 1, 0, 1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<vector<int>> dist(n, vector<int>(m, 1000));
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

	priority_queue<pii, vector<pii>, greater<pii>> q;

    // Inicializando distância da linha superior
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == '.') dist[0][j] = 1;
        else dist[0][j] = 0;
        q.emplace(dist[0][j], j); // (distância, (linha*m + coluna))
    }

    // Usa dijkstra para calcular a distância
    while (!q.empty()) {
        auto [d, u] = q.top();
        int x = u / m, y = u % m;
        q.pop();
        

        if (dist[x][y] < d) continue;
        
        const int *dx, *dy;
        if (x % 2 == 0) {
            dx = even_dx;
            dy = even_dy;
        } else {
            dx = odd_dx;
            dy = odd_dy;
        }

        for (int k = 0; k < 6; k++) {
            int nx = x + dx[k], ny = y + dy[k];            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int w = grid[nx][ny] == '.' ? 1 : 0;
            if (dist[nx][ny] <= d + w) continue;
            dist[nx][ny] = d + w;
            q.emplace(dist[nx][ny], nx*m + ny);
        }
    }

    // Encontra a menor distância na última linha
    int ans = 1000;
    for (int j = 0; j < m; j++) {
        ans = min(ans, dist[n-1][j]);
    }
    cout << ans << endl;
    return 0;
}