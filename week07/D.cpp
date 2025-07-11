#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> id; // id[v] = número da componente

bool isClique(vector<int>& vertices) {
    int edge_count = 0;
    for (int u : vertices) {
        for (int v : adj[u]) {
            if (id[v] == id[u]) // estão no mesmo componente
                edge_count++;
        }
    }
    
    int k = vertices.size();
    return edge_count / 2 == k * (k - 1) / 2;
}

void dfs(int u, int comp_id, vector<int>& component_vertices) {
    id[u] = comp_id;
    component_vertices.push_back(u);
    for (int v : adj[u]) {
        if (id[v] != -1) continue;
        dfs(v, comp_id, component_vertices);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    adj.resize(N+1);
    id.assign(N+1, -1);

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (adj[i].size() == N-1) id[i] = 0; 
    }

    int comp_id = 1;
    vector<vector<int>> components;
    for (int i = 1; i <= N; i++) {
        if (id[i] == -1) {
            vector<int> component_vertices;
            dfs(i, comp_id, component_vertices);
            components.push_back(component_vertices);
            comp_id++;
        }
    }

    if (comp_id > 3) {
        cout << "No\n";
        return 0;
    }

    for (auto& comp : components) {
        if (!isClique(comp)) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int i = 1; i <= N; i++) {
        cout << (id[i] == 0 ? 'b' : id[i] == 1 ? 'a' : 'c');
    }
    cout << endl;

    return 0;
}