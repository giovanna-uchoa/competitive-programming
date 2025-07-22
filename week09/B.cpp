#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n  >> m;

    vector<int> id(n+1, 0);
    vector<int> color(n+1, -1);
    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;

        id[i] = -1;
        color[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();            
            for (int v : graph[u]) {
                if (color[v] != -1) {
                    if (color[v] != color[u]) continue;
                    else {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
                
                color[v] = (color[u] + 1) % 2;
                id[v] = u;
                q.push(v);
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        if (color[v] != -1) continue;

        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int v = 1; v <= n; v++) {
        cout << color[v] + 1 << " ";
    }
    cout << endl;

    return 0;
}