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

    void update(int idx, int val) {
        idx += size;
        tree[idx] = val;
        // Recalculate the tree upwards
        while (idx > 1) {
            idx /= 2;
            tree[idx] = merge(tree[idx*2], tree[idx*2 + 1]);
        }
    }

    ll query(int left, int right) {
        left += size;
        right += size;

        ll out = 0; // Initial value for sum
        while (left < right) {
            if (left % 2 == 1) out = merge(out, tree[left++]);
            if (right % 2 == 1) out = merge(out, tree[--right]);
            left /= 2;
            right /= 2;
        }
        return out;
    }
};