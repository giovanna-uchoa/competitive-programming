/* This code implements a solution to a problem involving counting pairs of indices in an array based on certain conditions.
 * The algorithm uses binary search to efficiently find the required indices and calculates the result based on the conditions given.
 * The complexity of the algorithm is O(m log m) where m is the number of elements in the array.
 * The space complexity is O(n) for storing the prefix sums.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;

int a[maxn];
int p[maxn];

int n, m;

bool check(int mid, int i){
    if(a[mid] >= n-a[i]) return 1;
    else return 0;
}

int find_j(int i){
    int lo = 1, hi = i-1, mid;
    if(check(lo, i) == 1) return lo;
    while(lo+1 < hi){
        mid = (lo+hi)/2;
        if(check(mid, i) == 0) lo = mid;
        else hi = mid;
    }
    return hi;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> a[i];
    sort(a+1, a+m+1);
    for(int i = 1; i <= m; i++){
        if(a[i] == n) a[i]--;
    }
    for(int i = 1; i <= n; i++) p[i] = p[i-1]+a[i];
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int j = find_j(i);
        if(j == 0 or check(j,i) == 0) continue;
        ans += 2LL*((a[i]-n+1)*(i-j) + p[i-1]-p[j-1]);
    }
    cout << ans << '\n';
}

int main(){
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}