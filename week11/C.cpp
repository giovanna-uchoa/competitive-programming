#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

struct DSU {
    vector<int> parent, rank;
    int component_count;

    DSU(int n) : parent(n+1), rank(n+1, 0), component_count(n) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // Path Compression
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;

        // Union by Rank
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;

        if (rank[u] == rank[v]) rank[u]++;
        component_count--;
        return true;
    }

    int get_component_count() {
        return component_count;
    }
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    DSU dsu(N);
    vector<Edge> edges(M+1);
    
    for (int m = 1; m <= M; m++)
        scanf("%d %d", &edges[m].u, &edges[m].v);

    int Q;
    scanf("%d", &Q);

    unordered_set<int> remove_queries;
    vector<int> remove_order(Q);
    for (int q = Q-1; q >= 0; q--) {
        scanf("%d", &remove_order[q]);
        remove_queries.insert(remove_order[q]);
    }

    for (int m = 1; m <= M; m++) {
        if (!remove_queries.count(m))
            dsu.unite(edges[m].u, edges[m].v);
    }

    vector<int> result(Q);
    for (int q = 0; q < Q; q++) {
        int m = remove_order[q];
        result[q] = dsu.get_component_count();
        dsu.unite(edges[m].u, edges[m].v);
    }

    for (int q = Q-1; q >= 0; q--)
        printf("%d ", result[q]);
    printf("\n");

    return 0;
}
