// OTIMIZAÇÃO DE MEMÓRIA
// O(N²)
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    
    vector<int> col_gcd(N+1);
    vector<int> dp(N+1, INF);
    
    for (int j = 1; j <= N; j++) {
        col_gcd[j] = gcd(j, B);
    }
    
    // Primeira posição sem custo acumulado => força começo em (1,1)
    dp[1] = 0;
    for (int i = 1; i <= N; i++) {
        int row_gcd = gcd(i, A);
        for (int j = 1; j <= N; j++) {
            // Preciso da coluna anterior atual e do valor anterior da posição!
            dp[j] = min(dp[j-1], dp[j]) + row_gcd + col_gcd[j];
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}