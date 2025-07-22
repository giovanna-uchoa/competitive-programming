#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LOG = 20;

vector<int> depth;
vector<vector<int>> up;
vector<vector<ll>> max_edge;
vector<vector<pair<int, ll>>> mst;

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

void preprocess_dfs(int v, int p, ll w) {
    up[v][0] = p;
    max_edge[v][0] = w;
    for (int i = 1; i < LOG; i++) {
        up[v][i] = up[ up[v][i-1] ][i-1];
        max_edge[v][i] = max(max_edge[v][i-1], max_edge[ up[v][i-1] ][i-1]);
    }
    for (auto [to, weight] : mst[v]) {
        if (to != p) {
            depth[to] = depth[v] + 1;
            preprocess_dfs(to, v, weight);
        }
    }
}

ll query_lca(int u, int v) {
    ll res = 0;
    if (depth[u] < depth[v]) swap(u, v);
	int dt = depth[u] - depth[v];

	for (int i = LOG-1; i >= 0; i--) {
		if (dt & (1<<i)) {
            res = max(res, max_edge[u][i]);
            u = up[u][i];
        }
    }

    if (u == v) return res;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            res = max({res, max_edge[u][i], max_edge[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }

    return max({res, max_edge[u][0], max_edge[v][0]});
}

void construct_kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst[e.u].emplace_back(e.v, e.weight);
            mst[e.v].emplace_back(e.u, e.weight);
        }
    }
}

void solve(int ncase) {
    int N, R;
    scanf("%d %d", &N, &R);

    vector<Edge> roads(R);
    for (int i = 0; i < R; i++) {
        scanf("%d %d %lld", &roads[i].u, &roads[i].v, &roads[i].weight);
        roads[i].u--;
        roads[i].v--;
    }

    mst.assign(N, {});
    depth.assign(N, 0);
    up.assign(N, vector<int>(LOG));
    max_edge.assign(N, vector<ll>(LOG));

    construct_kruskal(N, roads);
    preprocess_dfs(0, 0, 0);

    int Q;
    scanf("%d", &Q);

    printf("Case %d\n", ncase);
    for (int i = 0; i < Q; i++) {
        int k, t;
        scanf("%d %d", &k, &t);
        ll ans = query_lca(--k, --t);
        printf("%lld\n", ans);
    }

    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
    return 0;
}