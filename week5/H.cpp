#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<int>> flight(N, vector<int>(N, 0));
    // # de caminhos que visitam nós em mask e terminam em u
    vector<vector<int>> dp(1<<N, vector<int>(N));

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        flight[--a][--b] += 1;
    }

    dp[1][0] = 1;
    for (int mask = 1; mask < (1<<N); mask++) {
        for (int u = 0; u < N; u++) {
            if (!(mask & (1<<u))) continue;
                
            for (int v = 0; v < N; v++)
                if (!(mask & (1<<v)))
                    dp[mask | (1<<v)][v] = (dp[mask | (1<<v)][v] + (long long)dp[mask][u]*flight[u][v]) % MOD;
        }
    }

    printf("%d\n", dp[(1<<N) - 1][N-1]);
    return 0;
}