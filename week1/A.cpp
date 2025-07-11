/*
Problem: A+B (Trial Problem)
Source: Codeforces (https://codeforces.com/problemset/problem/1351/A)

Approach:
  - For each test case, read two integers a and b.
  - Compute their sum and print the result.

Time Complexity: O(1) per test case
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << a + b << endl;
    }
}