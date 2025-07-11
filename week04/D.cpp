#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int x, divisors = 0;
        scanf("%d", &x);

        
        for (int i = 1; i*i <= x; i++) {
            if (x % i == 0) {
                if (i == x/i) divisors++;
                else divisors += 2;
            }
        }
        printf("%d\n", divisors);
    }

    return 0;
}