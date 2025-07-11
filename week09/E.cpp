#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

vector<int> depth;
vector<vector<int>> up;
vector<vector<int>> adj;

void dfs(int src, int parent, int d) {
    depth[src] = d;
    up[src][0] = parent;
    for (int i = 1; i < LOG; i++)
        up[src][i] = up[ up[src][i-1] ][i-1];
    
    for (int u : adj[src]) {
        if (u == parent || depth[u] != -1) continue;
        dfs(u, src, d+1);
    }
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a,b);
	int dt = depth[a] - depth[b];

	for (int i = LOG-1; i >= 0; i--)
		if (dt & (1<<i)) a = up[a][i];

	if (a == b) return a;

	for (int i = LOG-1; i >= 0; i--) {
		if (up[a][i] != up[b][i]) {
			a = up[a][i];
			b = up[b][i];
		}
    }

	return up[a][0];
}

int distance_lca(int a, int b) {
    int ancestor = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[ancestor];
}

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M, &K);
    
    // Initialize depth, adjacency list, and up table
    adj.resize(N+1);
    depth.assign(N+1, -1);
    up.assign(N+1, vector<int>(LOG));
    
    // Read edges
    for (int i = 1; i < N; i++) {
        int a, b; scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1, 0);

    for (int q = 0; q < Q; q++) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", distance_lca(a, b));
    }

    return 0;
}