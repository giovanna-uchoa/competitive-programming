#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll L, U;
ll a[200005];
ll tmp[200005]; // Global temporary buffer for reuse

ll count_and_merge(int s, int m, int e) {
    ll count = 0;

    int lower_bound = e, upper_bound = e;
    for (int k = s; k <= m; k++) {
        while (lower_bound > m && a[k] + a[lower_bound] >= L) lower_bound--; // first that doesn't
        while (upper_bound > m+1 && a[k] + a[upper_bound] > U) upper_bound--; // first that does

        if (upper_bound < lower_bound) break;
        if (a[k] + a[upper_bound] <= U && a[k] + a[lower_bound+1] >= L)
            count += (upper_bound - lower_bound); // (lower_bound, upper_bound]
    }

    for (int k = s; k <= e; k++) tmp[k] = a[k];

    int i = s, j = m + 1;
    for (int k = s; k <= e; k++) { 
        if (i > m) a[k] = tmp[j++];
        else if (j > e) a[k] = tmp[i++];
        else if (tmp[i] <= tmp[j]) a[k] = tmp[i++];
        else a[k] = tmp[j++];
    }

    return count;
}

ll mergesort(int s, int e) {
    if (s >= e) return 0;
    int mid =  (s + e) / 2;

    ll r = mergesort(s, mid);
    ll l = mergesort(mid+1, e);

    return r + l + count_and_merge(s, mid, e);
}

ll solve() {
    int N;
    ll X, Y;
    scanf("%d %lld %lld", &N, &X, &Y);

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }  

    // X <= sum - a[i] - a[j] <= Y
    // sum - Y <= a[i] + a[j] <= sum - X
    L = sum - Y;
    U = sum - X; 

    return mergesort(0, N-1);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--)
        printf("%lld\n", solve());
}