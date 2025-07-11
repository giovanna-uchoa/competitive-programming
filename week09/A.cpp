#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> up;
vector<vector<int>> adj;

void dfs(int src, int parent) {
    up[src][0] = parent;
    for (int i = 1; i < LOG; i++)
        if (up[src][i-1] == -1)
            break; // If parent doesn't exist, break the loop
        else
            up[src][i] = up[ up[src][i-1] ][i-1];
    
    for (int u : adj[src]) {
        if (u == parent) continue;
        dfs(u, src);
    }
}

int binary_lifting(int u, int k) {
    int v = u;
	for (int i = LOG-1; i>= 0; i--) {
		if (k & (1<<i)) v = up[v][i];
        if (v == -1) break; // If we reach a node that doesn't exist       
    }

	return v;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    adj.resize(N+1);
    up.assign(N+1, vector<int>(LOG, -1));
    
    for (int i = 2; i <= N; i++) {
        int e; scanf("%d", &e);
        adj[e].push_back(i);
        adj[i].push_back(e);
    }

    dfs(1, -1);

    for (int q = 0; q < Q; q++) {
        int x, k; scanf("%d %d", &x, &k);
        printf("%d\n", binary_lifting(x, k));
    }

    return 0;
}