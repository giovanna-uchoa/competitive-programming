// Erro: Definição do Máximo
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> h(N);
    vector<int> dp(N, INT_MAX);
    for (int i = 0; i < N; i++)
        scanf("%d", &h[i]);

    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int k = 1; k <= K && i-k >= 0; k++)
            dp[i] = min(dp[i], dp[i-k] + abs(h[i] - h[i-k]));
    }

    printf("%d\n", dp[N-1]);
    return 0;
}