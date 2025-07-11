/*  This code implements a segment tree in C++ for range queries and point updates.
 *  The segment tree supports a merge function that can be customized for different operations (e.g., sum, min, max).
 *  The example provided uses a sum operation.
 *  The code includes methods for building the tree, updating a value, and querying a range.
 *  Complexity: O(log n) for updates and queries, O(n) for building the tree.
 */
#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    vector<int> tree;
    int size = 1;

    Segtree(vector<int>& arr) {
        while (size < arr.size()) size *= 2;
        tree.assign(size*2, 0);

        for (int i = 0; i < arr.size(); i++) tree[size+i] = arr[i];
        for (int i = size - 1; i > 0; i--) tree[i] = merge(tree[i*2], tree[i*2 + 1]);
    
    }

    int merge(int a, int b) {
        return a + b; // Example merge function for sum
    }

    void update(int idx, int val) {
        idx += size;
        tree[idx] = val;
        // Recalculate the tree upwards
        while (idx > 1) {
            idx /= 2;
            tree[idx] = merge(tree[idx*2], tree[idx*2 + 1]);
        }
    }

    int query(int left, int right) {
        int out = 0; // Initial value for sum

        left += size;
        right += size;
        while (left < right) {
            if (left % 2 == 1) out = merge(out, tree[left++]);
            if (right % 2 == 1) out = merge(out, tree[--right]);
            
            left /= 2;
            right /= 2;
        }
        return out;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Segtree segtree(arr);

    // Example usage
    cout << "Sum of range [1, 4): " << segtree.query(1, 4) << endl; // Adjust indices as needed
    segtree.update(2, 10); // Update index 2 to value 10
    cout << "Sum of range [1, 4) after update: " << segtree.query(1, 4) << endl;

    return 0;
}