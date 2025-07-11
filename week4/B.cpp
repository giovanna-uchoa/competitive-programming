#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int almost_primes = 0;
    vector<int> numbers(n+1);
    
    for (int i = 2; i <= n; i++) {
        if (numbers[i] == 0) {
            for (int j = i+1; j <= n; j++) {
                if (j % i == 0) numbers[j]++;
            }
        }

        else if (numbers[i] == 2) almost_primes++;
    }

    printf("%d\n", almost_primes);
    return 0;
}