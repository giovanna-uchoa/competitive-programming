/*
Problem: C - Reverse the Rivers
Source: Vjudge (https://vjudge.net/contest/702854#problem/C)

Approach:
  - Input matrix is transposed for easier column-wise operations.
  - Each row is preprocessed using a prefix OR to allow efficient range queries.
  - For each query:
      - Start with full column range [0, n)
      - Narrow the range based on each condition using custom lower_bound or upper_bound.
  - If a valid column remains, output its index (1-based); else output -1.

Time Complexity:
  - Preprocessing: O(n * k)
  - Each query: O(m * log n)
Space Complexity: O(n * k)
*/

#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>& v, int x, int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    
    return lo;
}

int upper_bound(vector<int>& v, int x, int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] <= x) lo = mid + 1;
        else hi = mid;
    }
    
    return lo;
}

int main() {
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);

     // Transpose matrix input and compute prefix OR for each river (row)
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &a[j][i]);
            if (i > 0) a[j][i] = a[j][i-1] | a[j][i];
        }
    }

    int m;
    while (q--) {
        scanf("%d", &m);
        
        int lo_c = 0, hi_c = n;
        for (int i = 0; i < m; i++) {
            int r, c; char o;
            scanf("%d %c %d", &r, &o, &c);

            if (lo_c >= hi_c) continue;
            r--; // 0-based index;
            
            if (o == '<') hi_c = lower_bound(a[r], c, lo_c, hi_c);
            else lo_c = upper_bound(a[r], c, lo_c, hi_c);
        }

        printf("%d\n", (lo_c >= hi_c) ? -1 : (lo_c + 1)); // 1-based index
    }

    return 0;
}