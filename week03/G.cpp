/*
Problem: G - Ruler (hard version)
Source: Vjudge (https://vjudge.net/contest/702854#problem/G)

Approach:
  - Perform a ternary search in the range [2, 999].
  - Use custom check() to interpret the response:
      * 2 → x > a, x > b
      * 1 → a < x ≤ b
      * 0 → x ≤ a, x ≤ b
  - Based on the return value, adjust search boundaries.
  - When the search converges, print the final value of x.

Time Complexity: O(log n) (ternary search)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int measured_value) {
    int value = a*b;

    if (value == measured_value) return 2; // ab -> a, b < x
    else if (value+a == measured_value) return 1; // a(b+1) -> a < x <= b
    else return 0; // (a+1)(b+1) -> a, b >= x;
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
        int t = (hi - lo)/3;
        int t1 = lo + t;
        int t2 = t1 + t;

        int response = query(t1, t2);
        int partition = check(t1, t2, response);

        if (partition == 2) {
          lo = t2+1;
        } else if (partition == 1) {
          lo = t1+1;
          hi = t2;
        } else hi = t1;
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