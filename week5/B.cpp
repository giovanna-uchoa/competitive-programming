// Erro o % estava calculando primeiro que +
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    
    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &coins[i]);
    }

    vector<long long> dp(X+1, 0);
    dp[0] = 1;

    for (int x = 1; x <= X; x++) {
        for (int c : coins) {
            if (x-c >= 0)
                dp[x] = (dp[x] + dp[x-c]) % MOD;
        }
    }

    printf("%d\n", dp[X]);
    return 0;
}