/*
Problem: E - Exponentiation II
Source: Vjudge (https://vjudge.net/contest/704739#problem/E)

Approach:
  - Use modular exponentiation to compute (a^(b^c)) % mod.
  - Since b^c can be very large, compute it modulo (mod - 1) using Fermat's Little Theorem.

Time Complexity: O(log(c))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define modulo 1000000007

ll fast_exp(ll a, ll x, ll mod) {
    if (x == 0) return 1;
    
    ll p = fast_exp(a, x / 2, mod);
    p = (p * p) % mod;
    return (x % 2 == 1) ? (p * a) % mod : p;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        ll b_exp_c = fast_exp(b, c, modulo - 1);
        ll ans = fast_exp(a, b_exp_c, modulo);
        
        printf("%lld\n", ans);
    }

    return 0;
}
