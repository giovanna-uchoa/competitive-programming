#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Segtree {
    vector<ll> tree;
    ll size = 1;

    Segtree(vector<ll>& arr) {
        while (size < arr.size()) size *= 2;
        tree.assign(size*2, 0);

        for (int i = 0; i < arr.size(); i++) tree[size+i] = arr[i];
        for (int i = size - 1; i > 0; i--) tree[i] = merge(tree[i*2], tree[i*2 + 1]);
    }

    ll merge(ll a, ll b) {
        return max(a, b);
    }

    // Update the value at index idx by subtracting val
    void update(int idx, ll val) {
        idx += size;
        tree[idx] -= val;
        // Recalculate the tree upwards
        while (idx > 1) {
            idx /= 2;
            tree[idx] = merge(tree[idx*2], tree[idx*2 + 1]);
        }
    }

    // Binary search for the first index with value >= min
    int query(ll min) {
        int node = 1; // Start from the root
        while (node < size) { // While not at a leaf node
            if (min > tree[node]) return -1; // No such index exists

            node *= 2; // Move to the left child
            if (tree[node] < min) node++; // Move to the right child if left child is not sufficient
        }

        // Now node is a leaf node, we need to find the original index
        if (tree[node] < min) return -1; // If the leaf node value is still less than min, return -1
        return node - size; // Convert to original index
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    Segtree segtree(h);
    
    while (m--) {
        int r;
        cin >> r;

        int hotel = segtree.query(r);
        if (hotel == -1) {
            cout << "0" << " "; // No hotel can accommodate this request
        } else {
            cout << hotel + 1 << " "; // Convert to 1-based index
            segtree.update(hotel, r); // Mark this hotel as used
        }
    }

    cout << "\n";
    return 0;
}