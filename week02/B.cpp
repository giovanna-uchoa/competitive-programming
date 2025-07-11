/*
Problem: B - Normal Problem
Source: Vjudge (https://vjudge.net/contest/700636#problem/B)

Approach:
  - Iterate over the input string and construct a mirrored version:
    - 'p' becomes 'q', 'q' becomes 'p', and other characters remain the same.
    - The mirrored character is prepended to the result string.

Time Complexity: O(|a|)
Space Complexity: O(|a|)
*/

#include <bits/stdc++.h>
using namespace std;

string solve() {
    string a;
    cin >> a;

    string mirrored_a = "";

    for (auto c : a ) {
        if (c == 'p') mirrored_a = 'q' + mirrored_a;
        else if (c == 'q') mirrored_a = 'p' + mirrored_a;
        else mirrored_a = c + mirrored_a;
    }
    return mirrored_a;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}