// Ideia: Each element initially points to artificial set node;
// Each artificial set node is its own parent
// https://codeforces.com/blog/entry/130521

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    vector<long long> sum;

    DSU(int n) : parent(2 * n), size(2 * n, 0), sum(2 * n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = n+i;
            parent[n+i] = n+i;
            size[n+i] = 1;
            sum[n+i] = i+1; // 1-based
        }
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        // Union by size
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        sum[u] += sum[v];
    }

    void move(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) return;

        // Update sizes and sums
        size[ru]--;
        sum[ru] -= (u + 1);

        // Move u to set of v
        parent[u] = rv;
        size[rv]++;
        sum[rv] += (u + 1);
    }

    int get_component_size(int u) {
        return size[find(u)];
    }

    long long get_component_sum(int u) {
        return sum[find(u)];
    }
};

int main() {
    int N, M;
    // Tests are input until EOF
    while (scanf("%d %d", &N, &M) == 2) {
        DSU dsu(N);

        for (int i = 0; i < M; ++i) {
            int op;
            scanf("%d", &op);

            if (op == 1) {
                int p, q;
                scanf("%d %d", &p, &q);
                dsu.unite(--p, --q);
            } else if (op == 2) {
                int p, q;
                scanf("%d %d", &p, &q);
                dsu.move(--p, --q);
            } else if (op == 3) {
                int p;
                scanf("%d", &p); --p;
                printf("%d %lld\n", dsu.get_component_size(p), dsu.get_component_sum(p));
            }
        }
    }
    return 0;
}