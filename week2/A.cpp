/*
Problem: A - Hard Problem
Source: Vjudge (https://vjudge.net/contest/700636#problem/A)

Approach:
  - First, assign as many `a` monkeys as possible to the first row (limited by `m` or `a`).
  - Then, assign as many `b` as possible to the second row (limited by `m` or `b`).
  - If the first row isn't fully filled, attempt to fill it using the `c` monkeys.
  - Similarly, if the second row isn't full, use the remaining `c` monkeys to fill it.
  - The final result is the sum of the monkeys in both rows.

Time Complexity: O(1) per test case
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;

    // monkeys at
    int first_row = min(a, m), second_row = min(b, m);
     
    if (first_row < m) {
        int c_monkeys = min(c, m-first_row);
        first_row += c_monkeys;
        c-=c_monkeys;
    }

    if (second_row < m) {
        second_row += min(c, m-second_row);
    }

    return first_row + second_row;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int max_monkeys = solve();
        cout << max_monkeys << endl;
    }

    return 0;
}