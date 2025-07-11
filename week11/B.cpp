#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAXN = 3e5 + 5;

ll fact[MAXN], invFact[MAXN];

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        events.emplace_back(l, +1);     // Lamp turns on
        events.emplace_back(r + 1, -1); // Lamp turns off after r
    }

    sort(events.begin(), events.end());

    precompute();

    int curr = 0;
    ll ans = 0;

    for (auto [t, type] : events) {
        if (type == +1) {
            if (curr >= k - 1) {
                ans += C(curr, k-1); // This new lamp makes groups with (k-1) already on
                ans %= MOD;
            }
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
