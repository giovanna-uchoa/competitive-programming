// no melhor dos casos: lcm(a, b) = max(a, b)
// considere a < b, lcm(a, b) = b sse b % a == 0
// ou seja, resposta ótima tem b mod a = 0
// com isso, como n = a + b, (n - a) mod a = 0 => n mod a = 0
// ou seja, resposta ótima tem a como divisor de n
// além disso, preciso maximizar a para minimizar b (a < b)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);


        int a = 1;
        for (int d = 2; d*d <= n; d++) {
            if (n % d == 0) { 
                a = n / d; break; 
            }
        }
        
        printf("%d %d\n", a, n-a);
    }
    return 0;
}