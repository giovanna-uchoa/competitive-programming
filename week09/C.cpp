#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> plli;
const ll INFTY = 100000000000000000;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<plli>> graph(n+1);
	vector<ll> dist(n+1, INFTY);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
	}

	priority_queue<plli, vector<plli>, greater<plli>> q;
	dist[1] = 0;

	q.emplace(dist[1], 1);
	while (!q.empty()) {
		auto [d, u] = q.top();
		q.pop();
		
		if (dist[u] < d) continue;
		for (auto [v, w] : graph[u]) {
			if (v == u) continue; // self-loop
			if (dist[v] <= d + w) continue;
			dist[v] = d + w;
			q.emplace(dist[v], v);
		}
	}

    for (int c = 1; c <= n; c++)
        cout << dist[c] << " ";
    cout << endl;
}