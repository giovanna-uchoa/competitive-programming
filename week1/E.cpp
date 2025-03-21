/*
Problem: Remove Duplicates
Source: Codeforces (https://codeforces.com/problemset/problem/978/A)
Constraints:
    - 1 ≤ n ≤ 50
    - 1 ≤ ai ≤ 1000
Approach:
    - Iterate through the array from right to left, maintaining a `set<int>` to track unique elements.
    - If an element hasn't been seen before, add it to the result vector and mark it as seen.
    - Finally, print the count of unique elements and their values in reverse order.
Time Complexity: O(n lg n) — Each element is processed once, and set operations (insert & find) are O(lg n
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> elements;
    vector<int> parr(n);

    for (int i = 0; i < n; i++)
        cin >> parr[i];
    
    vector<int> without_dups;
    for (int i = n-1; i >= 0; i--) {
        if (elements.find(parr[i]) == elements.end()) {
            without_dups.push_back(parr[i]);
            elements.insert(parr[i]);
        }
    }

    int x = elements.size();
    cout << x << endl;
    for (int i = x-1; i >= 0; i--) {
        cout << without_dups[i] << " ";
    }
    cout << endl;
}