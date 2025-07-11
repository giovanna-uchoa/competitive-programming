/* This code implements a Disjoint Set Union (DSU) or Union-Find data structure.
 * It supports efficient union and find operations with path compression and union by rank.
 * The complexity of the find operation is nearly constant, O(α(n)), where α is the inverse Ackermann function.
 * The union operation is also efficient, making this structure suitable for problems involving connectivity in graphs.
 */
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n+1), rank(n+1, 0) {
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
        return true;
    }
};