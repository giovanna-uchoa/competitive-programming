/*
Problem: C - Minimum LCM
Source: Vjudge (https://vjudge.net/contest/704739#problem/C)

Approach:
  - Find two numbers a and b such that a + b = n and lcm(a, b) is minimized.
  - Best scenario is when lcm(a, b) = max(a, b). Consider a < b, then lcm(a, b) = b if b % a == 0.
  - With this, we know that the optimal solution has a as a divisor of n 
        n = a + b, (n - a) mod a = 0 => n mod a = 0.
  - Maximize a to minimize b (a < b).

Time Complexity: O(sqrt(n))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);


        int a = 1;
        for (int d = 2; d*d <= n; d++) {
            if (n % d == 0) { 
                a = n / d; break; 
            }
        }
        
        printf("%d %d\n", a, n-a);
    }
    return 0;
}