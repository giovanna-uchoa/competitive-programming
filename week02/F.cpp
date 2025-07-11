/*
Problem: F - Move Back at a Cost
Source: Vjudge (https://vjudge.net/contest/700636#problem/F)

Approach:
  - Identify elements that are out of order and store them in a multiset for later adjustments.
  - Maintain a "front" vector to store values that should initially remain unmodified.
  - Merge both structures to construct the final sequence. To do this, check if any values in the "front"
      are greater than those in the pushed-back set. If so, they are out of order and need to be pushed back.

Error Encountered: The code originally attempted to access the smallest element of `lex_smallest_arr` without checking if it was empty.
 - If `lex_smallest_arr` was empty, dereferencing `lex_smallest_arr.begin()` resulted in **undefined behavior (segfault).**
 - Fix: Added a check to handle empty cases

Time Complexity: O(n log n) per test case
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int min_val = a[n-1];
    vector<int> front = {min_val};
    multiset<int> lex_smallest_arr;
    
    // Step 1: Identify elements that are out of order (O(n log n))
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > min_val) {
            lex_smallest_arr.insert(a[i]+1); // Insert in multiset O(log n)
        } else {
            front.push_back(a[i]); // Maintain order O(1)
            min_val = a[i];
        }
    }

    // Step 2: Adjust values and insert them into the multiset (O(n log n))
    int min_pushed_back = lex_smallest_arr.empty() ? INT_MAX : *lex_smallest_arr.begin();
    bool must_increment = min_pushed_back < front.front(); // check if an increment is required

    for (int& val : front) {
        if (must_increment && val > min_pushed_back) val++;
        lex_smallest_arr.insert(val);
    }

    // Print the final lexicographically smallest sequence
    for (int val : lex_smallest_arr) cout << val << " ";
    cout << "\n";

    return 0;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

}