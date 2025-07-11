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
        if (u == parent) continue;
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

int main() {
    int N, Q;
    cin >> N >> Q;
    
    depth = vector<int>(N+1, -1);
    adj = vector<vector<int>>(N+1);
    up = vector<vector<int>>(N+1, vector<int>(LOG));
    
    for (int i = 2; i <= N; i++) {
        int e; cin >> e;
        adj[e].push_back(i);
    }

    dfs(1, 1, 0);

    for (int q = 0; q < Q; q++) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}