#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<vector<int>> monster_dist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> player_dist(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m));
    
    pair<int, int> start;
    queue<pair<int, int>> mq, pq;

    // Lê o grid e inicializa as distâncias
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                mq.emplace(i, j);
                monster_dist[i][j] = 0;
            }
            else if (grid[i][j] == 'A') {
                start = {i, j};
                pq.emplace(i, j);
                player_dist[i][j] = 0;
            }
        }
    }

    // BFS para os monstros
    while (!mq.empty()) {
        auto [x, y] = mq.front();
        mq.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') continue;
            if (monster_dist[nx][ny] != INT_MAX) continue;
            
            monster_dist[nx][ny] = monster_dist[x][y] + 1;
            mq.emplace(nx, ny);
        }
    }

    // BFS para o jogador
    while (!pq.empty()) {
        auto [x, y] = pq.front();
        pq.pop();

        // Checa se alcançamos alguma borda
        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            vector<char> path;
            pair<int, int> current = {x, y};
            
            while (current != start) {
                auto [px, py] = prev[current.first][current.second];
                if (current.first > px) path.push_back('D');
                else if (current.first < px) path.push_back('U');
                else if (current.second > py) path.push_back('R');
                else path.push_back('L');
                current = {px, py};
            }

            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << '\n';
            for (char c : path) cout << c;
            cout << '\n';
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') continue;
            if (player_dist[nx][ny] != INT_MAX) continue;
            
            int next_dist = player_dist[x][y] + 1;
            if (next_dist >= monster_dist[nx][ny]) continue;

            player_dist[nx][ny] = next_dist;
            prev[nx][ny] = {x, y};
            pq.emplace(nx, ny);
        }
    }

    cout << "NO\n";

    return 0;
}