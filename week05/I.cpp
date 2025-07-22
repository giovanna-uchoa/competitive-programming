/*
Problem: I - Matching
Source: Vjudge (https://vjudge.net/contest/708019#problem/I)

Approach: Use dynamic programming to solve the matching problem in a bipartite graph (BITMASKING).
  - Maintain a dp array where dp[mask] represents available matches for the nodes in 'mask'.
  - Iterate over all woman looking for matches and update the dp array based on the current mask.
  - The answer will be the number of ways to match all men with women.

Time Complexity: O(N * 2^N)
Space Complexity: O(2^N)
*/

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