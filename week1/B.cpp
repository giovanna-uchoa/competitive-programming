/*
Problem: Doors and Keys
Source: Codeforces (https://codeforces.com/problemset/problem/1644/A)
Constraints:
    - 1 <= t <= 720
Approach:
    - Track if the lowercase letters ('r', 'b', 'g') (keys) have been encountered with booleans.
    - If an uppercase letter ('R', 'B', 'G') (door) is found before its corresponding boolean (key) is true, stop processing.
    - If all keys are found print "YES". Otherwise, print "NO".
Time Complexity: O(|s|) per test case
Space Complexity: O(|s|)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    string map_hallway;
    bool r_key, b_key, g_key;
    for (int i = 0; i < t; i++) {
        cin >> map_hallway;

        r_key = b_key = g_key = 0;
        for (auto c : map_hallway) {
            if (c == 'r') r_key = 1;
            else if (c == 'b') b_key = 1;
            else if (c == 'g') g_key = 1;
            else if (c == 'R' && !r_key) break;
            else if (c == 'B' && !b_key) break;
            else if (c == 'G' && !g_key) break;
        }

        cout << ((r_key && b_key && g_key) ? "YES" : "NO") << endl;
    }
}