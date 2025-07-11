#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N, M;
int team[MAXN];
vector<int> friendships[MAXN]; // Lista de adjacência

// Cada nó é visitado por no máximo 2 times
// 1 e 2, se o time for diferente, o grafo não é bipartido
// Se o time for 0, o nó não foi visitado
void dfs(int n, int current_team) {
    if (team[n] > 0 && team[n] != current_team) {
        printf("IMPOSSIBLE\n");
        exit(0);
    } else if (team[n] > 0) {
        return;
    }

    team[n] = current_team;
    int next_team = current_team == 1 ? 2 : 1;

    for (int adj : friendships[n]) {
        dfs(adj, next_team);
    }
}

int main() {
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        friendships[a].push_back(b);
        friendships[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {
        if (team[i] == 0) {
            dfs(i, 1);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << team[i] << " ";
    }
    cout << endl;

    return 0;
}