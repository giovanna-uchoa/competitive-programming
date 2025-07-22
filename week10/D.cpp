#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

vector<int> depth;
vector<int> npath;
vector<vector<int>> up;
vector<vector<int>> adj;

void dfs(int src, int parent, int d) {
    depth[src] = d;
    up[src][0] = parent;

    for (int i = 1; i < LOG; i++)
        up[src][i] = up[ up[src][i-1] ][i-1];

    for (int u : adj[src]) {
        if (u == parent) continue;
        dfs(u, src, d + 1);
    }
}

int get_lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int dt = depth[a] - depth[b];

    for (int i = LOG - 1; i >= 0; i--)
        if (dt & (1 << i)) a = up[a][i];

    if (a == b) return a;

    for (int i = LOG-1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

void paths_lca(int a, int b) {
    int lca = get_lca(a, b);
    npath[a] += 1;
    npath[b] += 1;
 
    npath[lca] -= 1;
    // If lca is not the root, we need to adjust the parent path count
    if (up[lca][0] != lca) npath[up[lca][0]] -= 1;
}

void accumulate(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        accumulate(v, u);
        npath[u] += npath[v];
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    adj.resize(N + 1);
    depth.assign(N + 1, -1);
    npath.assign(N + 1, 0);
    up.assign(N + 1, vector<int>(LOG));

    for (int i = 1; i < N; i++) {
        int a, b; 
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1, 0);

    for (int m = 0; m < M; m++) {
        int a, b;
        scanf("%d %d", &a, &b);
        paths_lca(a, b);
    }

    accumulate(1, 0);

    for (int n = 1; n <= N; n++) {
        printf("%d ", npath[n]);
    }
    printf("\n");

    return 0;
}