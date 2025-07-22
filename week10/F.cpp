#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> up;
vector<vector<int>> adj;
vector<int> depth;

// in[u] and out[u] are used to determine the subtree of u
// level[k] contains the nodes at depth k in the DFS tree
vector<int> in, out;
vector<vector<int>> level;

// Timer for DFS to assign in and out times
int timer = 0;

// DFS to calculate in, out, depth and up tables (Euler Tour Technique)
void dfs(int src, int parent, int d = 0) {
    depth[src] = d;
    if (level.size() <= d) level.resize(d + 1);
    level[d].push_back(in[src] = timer++); // Store the in time for the node

    up[src][0] = parent;
    for (int i = 1; i < LOG; i++) {
        if (up[src][i - 1] == -1) break;
        up[src][i] = up[ up[src][i-1 ]][i-1];
    }

    for (int u : adj[src]) {
        if (u == parent) continue;
        dfs(u, src, d + 1);
    }

    out[src] = timer;
}

int binary_lifting(int u, int k) {
    int v = u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (k & (1 << i)) v = up[v][i];
        if (v == -1) break;
    }
    return v;
}

int query(int v, int p) {
    int ancestor = binary_lifting(v, p);
    if (ancestor == -1) return 0;

    int k = depth[ancestor] + p;
    if (k < 0 || k >= level.size()) return 0;

    auto& lvl = level[k];
    auto lb = lower_bound(lvl.begin(), lvl.end(), in[ancestor]);
    auto ub = upper_bound(lvl.begin(), lvl.end(), out[ancestor]-1);

    return distance(lb, ub) - 1;  // Excludes v
}

int main() {
    int N;
    scanf("%d", &N);

    in.resize(N + 1);
    out.resize(N + 1);
    adj.resize(N + 1);
    depth.resize(N + 1, -1);
    up.assign(N + 1, vector<int>(LOG, -1));
    level.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int r; scanf("%d", &r);
        if (r == 0) continue;

        adj[r].push_back(i);
        adj[i].push_back(r);
    }

    for (int i = 1; i <= N; i++)
        if (depth[i] == -1) dfs(i, -1);

    // Sort levels for binary search
    for (auto& v : level)
        sort(v.begin(), v.end());

    int M; scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int v, p; scanf("%d %d", &v, &p);
        printf("%d ", query(v, p));
    }
    printf("\n");

    return 0;
}
