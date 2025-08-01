/*
Problem: D - Grid 1
Source: Vjudge (https://vjudge.net/contest/708019#problem/D)

Approach: Use dynamic programming to find the number of ways to reach the bottom-right corner of a grid.
  - Maintain a dp array where dp[i][j] represents the number of ways to reach cell (i, j).
  - For each cell, update the dp array based on the cells above and to the left.

Time Complexity: O(H*W)
Space Complexity: O(H*W)
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define mod 1000000007

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<ll>> dp(H+1, vector<ll>(W+1, 0));

    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            char square;
            cin >> square;
        
            if (square == '.')
                if (h == 1 && w == 1) dp[h][w] = 1;
                else dp[h][w] = (dp[h-1][w] + dp[h][w-1]) % mod;
        }
    }

    printf("%d\n", dp[H][W]);
    return 0;
}