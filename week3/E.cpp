/*
Problem: E - Subarray Sum II
Source: Vjudge (https://vjudge.net/contest/702854#problem/E)

Approach:
  - Use a prefix sum strategy.
  - Maintain a map `prefix_sums` to count how many times each prefix sum has occurred.
  - For each new element, compute the current prefix sum and:
      * If sum == X, increment count (to handle subarrays starting from index 0).
      * If (sum - X) has been seen before, add its frequency to the count (those are valid subarrays).
  - Use `std::map` instead of `unordered_map` to avoid worst-case TLE (O(n log n) vs potential O(n²)).

Time Complexity: O(n log n) — due to map insertions and lookups.
Space Complexity: O(n) — for storing prefix sums.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    ll a;
    ll count = 0, sum = 0;
    map<ll, ll> prefix_sums;

    for (int i = 0; i < N; i++) {
        scanf("%lld", &a);
        sum += a;

        // Count if current prefix sum == X (subarray starting at index 0)
        if (sum == X) count++;

        // Count how many times (sum - X) has occurred — those are valid subarrays ending here
        count += prefix_sums[sum - X];

        // Store the frequency of this prefix sum
        prefix_sums[sum]++;
    }

    printf("%lld\n", count);
}