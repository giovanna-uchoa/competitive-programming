#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int solve() {
    int n, m;
    cin >> n >> m;

    vector<int> slowness(n+1);
    vector<vector<pii>> graph(n+1); // Adjacency list (vertex, weight)

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    for (int i = 1; i <= n; i++) cin >> slowness[i];


    // Dijkstra's algorithm
    // h[i] = minimum distance to reach vertex N from i    
    priority_queue<pii, vector<pii>, greater<pii>> qh;
    vector<int> h(n+1, INT_MAX);
    h[n] = 0;

    qh.emplace(h[n], n);
    while (!qh.empty()) {
        auto [d, u] = qh.top();
        qh.pop();

        for (auto [v, w] : graph[u]) {
            if (h[v] <= d + w) continue;
            h[v] = d + w;
            qh.emplace(h[v], v);
        }
    }


    // We'll use A* to find the minimum distance from 1 to N
    // f(i) = h[i]*min_bike + d[i]
    vector<int> d(n+1, INT_MAX);
    vector<int> f(n+1, INT_MAX);

    priority_queue<tiii, vector<tiii>, greater<tiii>> qf;
    d[1] = 0;
    f[1] = h[1] * slowness[1];

    qf.emplace(f[1], slowness[1], 1); // (f(i), min_bike, vertex)
    while (!qf.empty()) {
        auto [fi, bike_slowness, u] = qf.top();
        qf.pop();

        if (f[u] < fi) continue;
        for (auto [v, w] : graph[u]) {
            int cost = w * bike_slowness;
            int new_d = d[u] + cost;
            int min_slowness = min(bike_slowness, slowness[v]);
            int new_f = new_d + h[v] * min_slowness;

            if (f[v] <= new_f) continue;
            d[v] = new_d;
            f[v] = new_f;
            qf.emplace(f[v], min_slowness, v);
        }
    }
    
    cout << d[n] << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--)
        solve();
}