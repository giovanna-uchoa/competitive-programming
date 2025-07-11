/*
Problem: Rectangles
Source: Codeforces (https://codeforces.com/problemset/problem/844/B)

Approach:
  - Consider each row and each column separately.
  - For each row/column, count the subsets of 0s and 1s using bitwise shifts.
  - Compute the total number of valid subsets and subtract single-element sets counted twice.

Error Encountered:
    - The initial implementation used pow(2, count_0) to calculate subsets.
    - However, pow returns an int, which overflows for large values (e.g., count_0 can reach 50, exceeding the
    int limit of 2^{32} - 1).
Solution:
    - Use bitwise shifting: 1LL << count_0, which efficiently computes powers of two without overflow.

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> table(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> table[i][j];

    long long sets_count = 0;

    // Counting subsets in rows
    for (int i = 0; i < n; i++) {
        long long sets_0 = 1, sets_1 = 1;
        for (int j = 0; j < m; j++) {
            if (table[i][j] == 0) sets_0 <<= 1;
            else sets_1 <<= 1;
        }

        sets_count += sets_0 - 1;
        sets_count += sets_1 - 1;
    }

    // Counting subsets in columns
    for (int j = 0; j < m; j++) {
        long long sets_0 = 1, sets_1 = 1;
        for (int i = 0; i < n; i++) {
            if (table[i][j] == 0) sets_0 <<= 1;
            else sets_1 <<= 1;
        }

        sets_count += sets_0 - 1;
        sets_count += sets_1 - 1;
    }

    // Removing single-element sets counted twice
    sets_count -= (1LL * n * m);

    cout << sets_count << endl;
    return 0;
}
