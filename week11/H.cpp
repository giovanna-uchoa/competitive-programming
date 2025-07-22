// UPSOLVING

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v;
    long long w;
};

struct DSU {
    vector<vector<int>> g;
    vector<int> parent, size;
    vector<long long> accum;

    DSU(int n): parent(n), size(n, 1), accum(n), g(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    };

    int find(int u) {
        return parent[u] == u ? u : find(parent[u]);
    }

    void unite(int u, int v, int w) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (size[u] < size[v]) swap(u, v);
        
        accum[u] += 1LL * size[v] * w;
        accum[v] += 1LL * size[u] * w - accum[u];
        
        g[u].push_back(v);
        parent[v] = u;
        size[u] += size[v];
    }

    void propagate() {
        int root = find(0);
        dfs(root);
    }

    void dfs(int u) {
        for (auto v : g[u]) {
            accum[v] += accum[u];
            dfs(v);
        }
    }
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    DSU dsu(N);
    vector<long long> danger(N, 0);
    vector<edge> edges(M);

    for (int i = 0; i < N; i++)
        scanf("%d", &danger[i]);

    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v; // Convert to 0-based index
        edges[i] = {u, v, max(danger[u], danger[v])};
    }

    // Sort edges by weight in ascending order
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.w < b.w;
    });

    // Process edges in sorted order
    for (const auto &e : edges) {
        dsu.unite(e.u, e.v, e.w);
    }

    dsu.propagate();
    
    for (int i = 0; i < N; i++)
        printf("%lld ", dsu.accum[i] + danger[i]);

    printf("\n");
    return 0;
}