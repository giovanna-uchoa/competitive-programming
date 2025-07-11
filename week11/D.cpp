#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Interval {
    int l, r, idx;
};

void solve() {
    int n, k;
    cin >> n >> k;

    vector<Interval> intervals;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        intervals.emplace_back(l, r, i);
    }

    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        if (a.l != b.l) return a.l < b.l;
        return a.r > b.r;
    });
   
    int curr = 0;
    ll ans = 0;

    for (auto [t, type] : events) {
        if (type == +1) {
            curr++;
        } else {
            curr--;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}
