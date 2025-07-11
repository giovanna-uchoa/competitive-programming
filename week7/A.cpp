#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

bool visited[MAXN];
vector<int> adj[MAXN];

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node])
        if (!visited[neighbor]) 
            dfs(neighbor);
}

int main() {
    int N, M;
    cin >> N >> M;

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    // se o número de arestas for diferente do número de nós, 
    // M < N, não pode ser um grafo conexo
    // M > N, tem mais que um ciclo simples
    if (N != M) {
        cout << "NO" << endl;
        return 0;
    }

    // precisa ser conexo, ou seja, todos os nós devem ser visitados 
    // a partir de um nó qualquer
    dfs(1);

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "FHTAGN!" << endl;
    return 0;
}