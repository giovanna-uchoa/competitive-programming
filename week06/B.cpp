/*
Problem: B - Hacking the random number generator
Source: Vjudge (https://vjudge.net/contest/711092#problem/B)

Approach: Two Pointers with Frequency Map
    - Use a map to store the frequency of each unique number in the input.
    - The map ensures the numbers are stored in sorted order.
    - Use two pointers to traverse the map and find pairs of numbers with a difference equal to K.
    - For each valid pair, calculate the number of combinations based on their frequencies.

Time Complexity: O(N log N) - due to map operations (insertion and traversal).
Space Complexity: O(N) - for storing the frequency map.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    map<int, int> numbers;
    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);

        auto it = numbers.find(n);
        if (it == numbers.end()) numbers[n] = 1;
        else it->second++; 
    }

    int count = 0; 
    auto i = numbers.begin();
    auto j = numbers.begin()++;
    while (j != numbers.end()) {
        int diff = j->first - i->first;
        
        if (diff == K) {
            count += i->second * j->second;
            i++; j++;
        } 
        else if (diff > K) i++;
        else j++;
        
    }

    printf("%d\n", count);
}