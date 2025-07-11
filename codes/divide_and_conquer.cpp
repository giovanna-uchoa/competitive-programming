/* This code implements a divide and conquer algorithm to find the maximum subarray sum in an array.
 * The function `dec` recursively divides the array into two halves, calculates the maximum subarray sum for each half,
 * and combines the results by finding the maximum sum that crosses the midpoint.
 * The complexity of this algorithm is O(n log n) due to the recursive nature of the divide and conquer approach.
 * The space complexity is O(n) for storing the array and auxiliary variables.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;

int a[maxn];
int p[maxn];

ll dec(int l, int r){
    if(l == r) return max(0, a[l]);
    if(l > r) return 0;
    int mid = (l+r)/2;
    ll op1 = dec(l, mid), op2 = dec(mid+1, r);
    ll maxl = 0;
    ll cur = 0;
    for(int i = mid; i >= l; i--){
        cur+=a[i];
        maxl = max(maxl, cur);
    }
    ll maxr = 0;
    cur = 0;
    for(int i = mid+1; i <= r; i++){
        cur+=a[i];
        maxr = max(maxr, cur);
    }
    return max({op1, op2, maxl+maxr});
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << dec(1,n) << '\n';
}

int main(){
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}