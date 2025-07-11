#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;

const ll inf = 0x3f3f3f3f3f3f3f3f;

int main() { 
    int m, n, t;
    cin >> n >> m >> t;

    vector<vector<tiii>> graph(n+1); // Adjacency list (vertex, x, y)
    vector<ll> dist(n+1, inf); // Distances (time) from vertex 1

    for (int i = 0; i < m; i++) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        graph[a].emplace_back(b, x, y);
        graph[b].emplace_back(a, x, y);
    }

    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[1] = t;

    q.emplace(dist[1], 1);
    while (!q.empty()) {
	    auto [t, u] = q.top();
        q.pop();
	
	    if (dist[u] < t) continue;
	    for (auto [v, x, y] : graph[u]) {
            ll incycle = t % (x + y);
            ll cost = incycle < x ? 0 : y - incycle + x;
            if (dist[v] <= t + cost) continue;
		    dist[v] = t + cost;
		    q.emplace(dist[v], v);
        }
    }

    cout << dist[n] << endl;
    return 0;
}