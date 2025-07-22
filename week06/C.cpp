/*
Problem: C - Removing Digits
Source: Vjudge (https://vjudge.net/contest/708019#problem/C)

Approach: Use dynamic programming to find the minimum number of steps to remove all digits from a number.
  - Maintain a dp array where dp[i] represents the minimum number of steps to remove all digits from i.
  - For each number, iterate over its digits and update the dp array accordingly.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/

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