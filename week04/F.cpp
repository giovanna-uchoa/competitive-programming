// UPSOLVING
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define modulo 1000000007

ll solve() {
    int n;
    scanf("%d", &n);

    int m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m = max(m, a[i]);
    }

    // sabemos que lcm(a,b) >= max(a, b)
    // e lcm(a, b) = max(a, m) sse min(a,b) | max(a, b)



}

int main() {
    int t;
    scanf("%d", &t);

    while(t--)
        solve();

    return 0;
}
