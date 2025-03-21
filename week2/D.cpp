/*
Problem: D - El Classificador
Source: Vjudge (https://vjudge.net/contest/700636#problem/D)
Constraints:
    - 1 ≤ n, q ≤ 2.10^5
    - 1 ≤ li, x ≤ 10^9
Approach:
    - Use a **map** to store sneaker sizes and their frequencies.
    - For each query, use `lower_bound(x)` to find the smallest available size (greedy).
    - If found, decrement the frequency; if exhausted, remove from inventory.
Time Complexity: O(n+q log k)
    - Insertion: O(n log k) (worst case O(n lg n): all unique sizes)
    - Query Processing: O(q log k).
Space Complexity: O(k) (where k is the number of unique sizes)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // it can't be unordered -> we'll use lower bound
    map<int, int> inventory;

    // Read and store sneaker sizes
    for (int i = 0; i < n; i++) {
        int sneaker_size;
        cin >> sneaker_size;

        auto it = inventory.find(sneaker_size); // O(lg k)

        if (it == inventory.end()) {
            inventory.insert({sneaker_size, 1}); // O(lg k)
        } else {
            it->second++;
        }
    }

    // Process customer queries
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        // Find smallest available size ≥ x (O(log k))
        auto it = inventory.lower_bound(x);

        if (it == inventory.end()) {
            cout << -1 << "\n";  // No available sneaker
        } else {
            cout << it->first << "\n"; // Sell the sneaker
            it->second--;

            if (it->second == 0)
                inventory.erase(it);
        }
    }


}