/*
Problem: G - Fun
Source: Vjudge (https://vjudge.net/contest/704739#problem/G)
UPSOLVING

Approach:
  - Iterate through all possible values of a and b.
  - For each pair (a, b), compute the maximum value of c.
  - Count all valid tuples (a, b, c) that satisfy the given conditions.

Time Complexity: O(N^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, X;
    scanf("%d %d", &N, &X);
    
    
    long long tuples = 0;
    for (int a = 1; a < N; a++) {
        // suppose c = 1; max b <= n / a
        int bmax = N / a;
        for (int b = 1; b < bmax; b++) {
            // we can obtain c
            int c1 = (N - a*b) / (a + b); // ab + ac + bc <= n
            int c2 = (X - a - b); // a + b + c <= x
            tuples += max(min(c1, c2), 0);
        }
    }

    printf("%lld\n", tuples);
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--)
        solve();

    return 0;
}
