/*
Problem: F - Skibidus and Fanum Tax (hard version) 
Source: Vjudge (https://vjudge.net/contest/702854#problem/F)

Approach: Greedy + Binary Search
  - Sort array B (target values).
  - Maintain a variable `prev` for the minimum possible value at current position.
  - For each element A[i], use binary search on B to find the smallest B[j] ≥ A[i] + prev.
  - Update A[i] accordingly to satisfy constraints.
  - If no suitable B[j] is found, output "NO".
  - If the loop completes, output "YES".

Time Complexity: O(N log M) per test case
Space Complexity: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> A(N);
    vector<int> B(M);

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < M; i++) scanf("%d", &B[i]);

    sort(B.begin(), B.end());

    int prev = min(B[0] - A[0], A[0]);
    for (int i = 1; i < N; i++) {
        auto b = lower_bound(B.begin(), B.end(), A[i]+prev);
   
        if (A[i] < prev) {
            if (b == B.end()) return -1;
            A[i] = *b - A[i];
        } else if (b != B.end()) {
            A[i] = min(A[i], *b - A[i]);
        }

        prev = A[i];
    }

    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--)
        printf(solve() == -1 ? "NO\n" : "YES\n");

    return 0;
}