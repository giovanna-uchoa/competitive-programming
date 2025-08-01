/*
Problem: F - Knapsack 2
Source: Vjudge (https://vjudge.net/contest/708019#problem/F)

Approach: Use dynamic programming to solve the 0/1 knapsack problem. We need to optimize the memory usage (W = 10^9).
  - Maintain a dp array where dp[i] represents the minimum weight that can be obtained with value i (Vmax = 100 * 10^3).
  - For each item, update the dp array from end to front to avoid overwriting values.
  - The answer will be the maximum value that can be obtained with the given weight limit.

Time Complexity: O(N*V_MAX)
Space Complexity: O(V_MAX)
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weights, vector<int> values, int N, int W) {
    int max_value = 0;
    for (int i =  0; i < N; i++) max_value += values[i];

    const long long INF = 1e12;
    vector<long long> dp(max_value+1, INF); // minum weight for each value

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