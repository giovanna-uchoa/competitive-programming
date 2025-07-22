#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int u, v;
    ll weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        return true;
    }
};

ll kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll mst_weight = 0;
    int edges_used = 0;

    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.weight;
            edges_used++;
            if (edges_used == n - 1) break;
        }
    }

    if (edges_used == n - 1) return mst_weight;
    return -1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %lld", &edges[i].u, &edges[i].v, &edges[i].weight);
        edges[i].u--;
        edges[i].v--;
    }

    ll result = kruskal(N, edges);
    if (result == -1) printf("IMPOSSIBLE\n");
    else printf("%lld\n", result);

    return 0;
}
