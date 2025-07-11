/*
Problem: D - Factory Machines
Source: Vjudge (https://vjudge.net/contest/702854#problem/D)

Approach:
  - Binary search on time `t` in the range [1, min(k) * P]
  - For each mid time, compute total items produced by all machines: sum(t / k[i])
  - If the production is ≥ P, try to lower the upper bound.
  - Else, move the lower bound up.
  - Final answer is the minimum time where the production goal is met.

Time Complexity: O(n log(min(k) * P))
Space Complexity: O(n)

Error Encountered:
  - The binary search was adjusted to avoid overflow by using long long for time calculations.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX 1000000001

bool check(vector<int> k, ll time, int target){
    ll produced = 0;
    for (auto ki : k) produced += time/ki;
    return produced >= target;
}

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    vector<int> k(N);
    int kmin = MAX;

    for (int i = 0; i < N; i++) {
        scanf("%d", &k[i]);
        kmin = min(kmin, k[i]);
    }

    ll lo_t = 1, hi_t = (ll) kmin*P, mid_t;
    while (lo_t < hi_t) {
        mid_t = lo_t + (hi_t - lo_t)/2;

        if (check(k, mid_t, P)) hi_t = mid_t;
        else lo_t = mid_t+1;
    }

    printf("%lld\n", lo_t);

}