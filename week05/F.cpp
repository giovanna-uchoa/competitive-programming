// Aqui precisamos otimizar memória (W = 10^9)
// Como não é necessário retrieve items podemos armazenar em 1D
// Espaço O(V_MAX) e Tempo O(N*W)
// Soma máxima 10^3 * 100 cabe em int.
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weights, vector<int> values, int N, int W) {
    int max_value = 0;
    for (int i =  0; i < N; i++) max_value += values[i];

    const long long INF = 1e12;
    vector<long long> dp(max_value+1, INF); // menor peso para valor V

    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int v = max_value; v >= values[i]; v--) {
            dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
        }
    }

    int ans = 0;
    for (int v = 0; v <= max_value; v++) if (dp[v] <= W) ans = v;
    return ans;
}

int main() {
    int N, W;
    scanf("%d %d", &N, &W);

    vector<int> w(N), v(N);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &w[i], &v[i]);

    int max_sum = knapsack(w, v, N, W);
    printf("%d\n", max_sum);

    return 0;
}