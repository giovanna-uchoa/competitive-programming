/*
Problem: E - Digital string maximization
Source: Vjudge (https://vjudge.net/contest/700636#problem/E)
Constraints:
    - 1 ≤ t ≤ 10^4
    - 1 ≤ |s| ≤ 2.10^5
Approach:
    - The goal is to maximize the lexicographical order of `s` by rearranging digits dynamically.
    - We maintain a window of at most 9 elements and replace each character optimally.
    - For each position `i`, we choose the best possible character from the window while keeping the order valid.
Time Complexity: O(|s|) per test case
Space Complexity: O(|s|)
*/

#include <bits/stdc++.h>
using namespace std;

int WINDOW_SIZE = 9;

int solve() {
    string s;
    cin >> s;

    int n = s.length();
    
    vector<char> options; // Stores up to 8 candidate digits for replacement

    // Initialize the options window with the first WINDOW_SIZE characters (or less if |s| < WINDOW_SIZE)
    for (int i = 0; i < min(n, WINDOW_SIZE); i++)
        options.push_back(s[i]);

    // Iterate over the string and replace each character with the best available option
    for (int i = 0; i < n; i++) {
        auto max_it = options.begin();
        s[i] = *max_it; // Initially set the current character to the first option

        for (int j = 1; j < options.size(); j++) {
            char adjusted_digit = options[j] - j;
            if (adjusted_digit > s[i]) {
                s[i] = adjusted_digit;
                max_it = options.begin() + j;
            }
        }

        // Remove the chosen character from options
        options.erase(max_it);
        // Add a new character to options, maintaining the sliding window of size ≤ WINDOW_SIZE
        if (i+WINDOW_SIZE < n) options.push_back(s[i+WINDOW_SIZE]);
    }

    cout << s << "\n";
    return 0;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

}