#include <bits/stdc++.h>
using namespace std;

#define INFTY 1000000000

vector<vector<int>> adj;
vector<int> value;

int dfs(int u, int d, int min_accum) {
    if (adj[u].empty()) {
        return min_accum + max(((value[u] - min_accum) / d), 0);;
    }

    int max_ops = INFTY;
    for (int v : adj[u]) {
        max_ops = min(max_ops, dfs(v, d+1, min(min_accum, value[v])));
    }

    return max_ops;
}

int solve() {
    int N;
    cin >> N;
    adj.resize(N+1);
    value.assign(N+1, -1);

    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        value[i] = x;
    }
    
    for (int v = 2; v <= N; v++) {
        int parent; cin >> parent;
        adj[parent].push_back(v);
    }

    int max_ops = INFTY;
    for (auto u : adj[1]) {
        max_ops = min(max_ops, dfs(u, 1, value[u]));
    }

    for (int i = 0; i <= N; i++) {
        adj[i].clear();
    }

    return value[1] + max_ops;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}