/*
Problem: B - Coin Combinations
Source: Vjudge (https://vjudge.net/contest/708019#problem/B)

Approach: Use dynamic programming to find the number of ways to make change for a given amount.
  - Maintain a dp array where dp[i] represents the number of ways to make change for amount i.
  - For each coin, update the dp array for all amounts that can be formed using that coin.

Error Encountered: Modulo % calc was not set correctly, being calculated before addition.

Time Complexity: O(X * N)
Space Complexity: O(X)
*/

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