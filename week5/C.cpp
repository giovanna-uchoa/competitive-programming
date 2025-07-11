#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    vector<int> dp(N+1);
    dp[0] = 0;

    for (int n = 1; n <= N; n++) { 
        dp[n] = INT_MAX;

        // Itera sobre os dígitos
        for (int num = n; num > 0; num /= 10) {
            if (num%10 > 0)
                dp[n] = min(dp[n], 1 + dp[n - num%10]);
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}