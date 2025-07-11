#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    ll ans;
    scanf("%lld %lld", &n, &k);

    vector<ll> front = {1}; 
    vector<ll> back = {n}; 

    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            front.push_back(i);
            back.push_back(n/i);
        }
    }

    if (front.back() == back.back()) back.pop_back();

    if (front.size() >= k) ans = front[k-1];
    else if (back.size() >= k-front.size()) ans = back[back.size() - k + front.size()];
    else ans = -1;

    printf("%lld\n", ans);
    return 0;
}