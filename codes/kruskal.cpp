/* This code implements Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a graph.
 * It uses a Disjoint Set Union (DSU) structure to efficiently manage connected components.
 * The algorithm sorts the edges by weight and adds them to the MST if they connect two previously unconnected components.
 * The complexity of this algorithm is O(E log E), where E is the number of edges, due to the sorting step.
 * The space complexity is O(V + E) for storing the edges and DSU structure, where V is the number of vertices.
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

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