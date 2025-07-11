/*
Problem: C - Balloon Quantum Popping
Source: Vjudge (https://vjudge.net/contest/700636#problem/C)

Approach:
  - Sort the balloon sizes in **descending order**.
  - At each second, Mori looks at the most inflated balloon and deflates it by half.
  - The process repeats until total inflated volume ≤ S.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    long long S;
    cin >> N >> S;

    long long inflated = 0;
    priority_queue<long long> b;

    // Read balloon inflation values
    for (int i = 0; i < N; i++) {
        long long bi;
        cin >> bi;

        inflated += bi;
        b.push(bi); // O(lg N)
    }

    int seconds = 0;
    // Deflate balloons until the total volume is within the allowed limit
    while (inflated > S) {
        long long ballons = b.top(); b.pop(); // O(1)
        long long deflated = ballons - ballons/2;
        
        b.push(ballons-deflated); // O(lg N)
        inflated -= deflated;
        
        seconds++;
    }

    cout << seconds << "\n";
    return 0;
}
