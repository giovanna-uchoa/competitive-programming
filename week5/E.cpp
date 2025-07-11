#include <bits/stdc++.h>
using namespace std;

int solve() {
    int K, N, M;
    scanf("%d %d %d", &N, &M, &K);
    
    char A[N+1];
    scanf("%s", &A);

    vector<int> dp(N+2, -1);
    dp[0] = K;
    A[N] = 'B';
    
    for (int n = 0; n <= N; n++) {
        if (A[n] == 'C') {
            dp[n+1] = -1;
            continue;
        }
        
        if (n-1 == 0 || A[n-1] == 'W')
            dp[n+1] = max(dp[n+1], dp[n]);
        
        for (int m = 1; m <= M && n-m + 1 >= 0; m++)
            if (n-m == -1 || A[n-m] == 'L')
                dp[n+1] = max(dp[n+1], dp[n-m+1]);

        if (A[n] == 'W') dp[n+1] -= 1;
    }

    return dp[N+1] >= 0;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--)
        if(solve())
            printf("YES\n");
        else
            printf("NO\n");

    return 0;
}