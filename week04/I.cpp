#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, X;
    scanf("%d %d", &N, &X);
    
    // ab + ac + bc <= n
    // a + b + c <= x
    
    long long tuples = 0;
    for (int a = 1; a < N; a++) {
        // suponha c = 0; max b = n/a
        int bmax = N / a;
        for (int b = 1; b < bmax; b++) {
            // conseguimos obter c
            int c1 = (N - a*b) / (a + b);
            int c2 = (X - a - b);

            // <= n E <= x
            tuples += max(min(c1, c2), 0);
        }
    }

    printf("%lld\n", tuples);
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--)
        solve();

    return 0;
}
