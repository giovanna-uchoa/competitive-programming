/*
Problem: A - Frog 2
Source: Vjudge (https://vjudge.net/contest/708019#problem/A)

Approach: Use dynamic programming to find the minimum cost to reach the last stone.
  - Maintain a dp array where dp[i] represents the minimum cost to reach stone i.
  - For each stone, calculate the cost to jump from the previous stone or the one before that.
  - Update the dp array with the minimum costs found.

Error Encountered: Maximum definition was not set correctly, leading to incorrect results. 

Time Complexity: O(N * K)
Space Complexity: O(N)
*/

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