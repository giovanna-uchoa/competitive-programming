#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank, size;
    int component_count;
    int max_component_size;

    DSU(int n) : parent(n+1), rank(n+1, 0), size(n+1, 1), component_count(n), max_component_size(1) {
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

        size[u] += size[v];
        max_component_size = max(max_component_size, size[u]);

        if (rank[u] == rank[v]) rank[u]++;
        component_count--;
        return true;
    }

    int get_component_count() {
        return component_count;
    }

    int get_component_size(int u) {
        return size[find(u)];
    }

    int get_max_component_size() {
        return max_component_size;
    }
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    DSU dsu(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        dsu.unite(u, v);

        printf("%d %d\n", dsu.get_component_count(), dsu.get_max_component_size());
    }

    return 0;
}
