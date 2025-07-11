#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n  >> m;

    vector<int> id(n+1, 0);
    vector<int> depth(n+1, -1);
    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    queue<int> q;
    id[1] = -1;
    depth[1] = 0;

    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (depth[v] != -1) continue;
            depth[v] = depth[u]+1;
            id[v] = u;
            q.push(v);
        }
    }

    if (depth[n] == -1)
        cout << "IMPOSSIBLE" << endl;
    else {
        
        vector<int> path = {n};
        
        int v = n;
        while (id[v] != -1) {    
            path.push_back(id[v]);
            v = id[v];
        }

        cout << depth[n] + 1 << endl;
        for (int i = depth[n]; i > 0; i--)
            cout << path[i] << " ";
        cout << path[0] << endl;
    }

    return 0;
}