/*
Problem: H - Library of Magic
Status: Solved during upsolving
Source: Vjudge (https://vjudge.net/contest/702854#problem/H)

Approach:
  - First, query the total XOR of [1..n] → xor_abc.
  - Use binary search to find the position of one of the elements (say a) based on the property:
      - If left_xor == 0 and right_xor == xor_abc → a is in the right half.
      - Otherwise, a is in the left half.
  - Once a is located, find the other two values by XORing appropriately and applying
    the same search recursively.

Time Complexity: O(log n) queries per search
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct SearchResult {
    ll left_query;
    ll lo;
    ll hi;
    ll mid;
};

ll query(ll l, ll r) {
    printf("xor %lld %lld\n", l, r);
    fflush(stdout);
    
    ll response;
    scanf("%lld", &response);
    
    if (response == -1) exit(0);
    return response;
}

SearchResult binary_search(ll lo, ll hi, ll query_ans) {
    ll all_xor = query_ans;
    ll left_xor, right_xor;
    ll mid;

    while (lo < hi) {
        mid = (hi + lo) / 2;
        left_xor = query(lo, mid);
        right_xor = all_xor ^ left_xor;
        
        if (left_xor == 0 && right_xor == query_ans) lo = mid + 1;
        else if (right_xor == 0 && left_xor == query_ans) hi = mid;
        else break;
    }

    return {left_xor, lo, hi, mid}; // pos == lo
}

void solve() {
    ll n;
    scanf("%lld", &n);

    ll lo, hi;
    ll a = 0, b = 0, c = 0;

    // (a xor b xor c)
    ll xor_abc = query(1, n);
    if (xor_abc != 0) {
        auto ans = binary_search(1, n, xor_abc);
        ll lxor = ans.left_query;
        
        if (lxor < n && query(lxor, lxor)) {
            a = lxor;
            lo = ans.mid + 1;
            hi = ans.hi;
        } else {
            a = xor_abc ^ lxor;
            lo = ans.lo;
            hi = ans.mid;
        }
    } else {
        hi = 2;
        while (hi-1 < n) {
            a = query(1, hi-1);
            if (a != 0) break;
            else hi *= 2;
        }
        
        lo = hi;
        hi = n;
    }
    
    auto ans2 = binary_search(lo, hi, xor_abc^a);
    b = ans2.left_query;
    c = a ^ b ^ xor_abc;

    printf("ans %lld %lld %lld\n", a, b, c);
    fflush(stdout);
}
int main () {
    int t;
    scanf("%d", &t);

    while(t--)
        solve();
}