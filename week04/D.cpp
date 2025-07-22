/*
Problem: D - Count Divisors
Source: Vjudge (https://vjudge.net/contest/704739#problem/D)

Approach:
  - Iterate from 1 to sqrt(x) and count divisors.
    - For each divisor i, if x is divisible by i, count both i and x/i.

Time Complexity: O(sqrt(n))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int x, divisors = 0;
        scanf("%d", &x);

        
        for (int i = 1; i*i <= x; i++) {
            if (x % i == 0) {
                if (i == x/i) divisors++;
                else divisors += 2;
            }
        }
        printf("%d\n", divisors);
    }

    return 0;
}