/**
Problem: E - Vasya and String
Source: Vjudge (https://vjudge.net/contest/711092#problem/E)

Approach: Sliding Window (Two Pointers)
    - Use a sliding window technique with two pointers (`i` and `j`) to represent the current segment of the string.
    - The goal is to find the maximum length of a substring where at most `K` characters can be replaced to make all characters in the substring the same.
    - Perform the process twice:
        1. First, consider replacing 'b' characters with 'a'.
        2. Then, consider replacing 'a' characters with 'b'.
    - For each case:
        - Expand the window by moving the right pointer (`j`).
        - If the character at `j` requires a replacement and replacements are available, decrement the replacement counter.
        - If no replacements are available, shrink the window by moving the left pointer (`i`) until a replacement becomes available.
        - Update the maximum length of the valid substring during each iteration.

Time Complexity: O(N) - Each pointer traverses the string at most once.
Space Complexity: O(N) - To store the input string.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;
    
    int replaces = K;
    int max_len = 0;
    // Iterate through the string
    int i = 0, j = 0;
    while (j < N) {
        if (s[j] == 'b') {
            if (replaces) replaces--;
            else while (s[i++] == 'a');
        }

        if (i <= j) max_len = max(max_len, j - i + 1);
        j++;
    }

    replaces = K;
    i = 0, j = 0;
    while (j < N) {
        if (s[j] == 'a') {
            if (replaces) replaces--;
            else while (s[i++] == 'b');
        }

        if (i <= j) max_len = max(max_len, j - i + 1);
        j++;
    }

    cout << max_len << "\n";
}