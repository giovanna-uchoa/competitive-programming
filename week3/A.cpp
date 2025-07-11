/*
Problem: A - Ruler (easy version)
Source: Vjudge (https://vjudge.net/contest/702854#problem/A)

Approach:
  - Perform a binary search in the range [2, 999].
  - In each iteration, query the judge with a pair (lo, mid).
  - If the check passes (i.e., `a * b == response`), move the lower bound up.
  - Otherwise, shrink the upper bound.
  - When the search converges, print the final result.

Time Complexity: O(log(upper_bound))

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int value) {
    if (a*b == value) return 1; // a, b > x;
    else return 0;
}

int query(int a, int b) {
    printf("? %d %d\n", a, b);
    fflush(stdout);
    
    int response;
    scanf("%d", &response);
    
    if (response == -1) exit(0);
    return response;
}

void solve() {
    int lo = 2, hi = 999;

    while (lo < hi) {
        int mid = (hi+lo)/2;
        int response = query(lo, mid);
      
        if (check(lo, mid, response) == 1) lo = mid+1;
        else hi = mid;
    }

    printf("! %d\n", lo);
    fflush(stdout);
}

int main () {
    int t;
    scanf("%d", &t);

    while(t--)
        solve();
}