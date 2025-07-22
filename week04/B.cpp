/*
Problem: B - Almost Prime
Source: Vjudge (https://vjudge.net/contest/704739#problem/B)

Approach:
  - Count numbers that have exactly two distinct prime factors.
    - Use a sieve-like approach to mark the number of distinct prime factors for each number.
  - Return the count of almost prime numbers.

Time Complexity: O(n log log n)
Space Complexity: O(n)
*/

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