// BITMASKING
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    
    vector<vector<int>> matches(N, vector<int>(N, 0));
    vector<int> dp(1<<N);
    
    for (int man = 0; man < N; man++)
        for (int woman = 0; woman < N; woman++)
            scanf("%d", &matches[man][woman]);
    

    dp[0] = 1;
    for (int mask = 1; mask < (1<<N); mask++) {
        int man = __builtin_popcount(mask)-1;
        for (int woman = 0; woman < N; woman++) {
            if ((mask & (1 << woman)) && matches[man][woman])
                (dp[mask] += dp[mask ^ (1<<woman)]) %= MOD;
        }
    }

    printf("%d\n", dp[(1<<N) - 1]);
    return 0;
}