/**
Problem: A - Hotels Along the Croatian Coast
Source: Vjudge (https://vjudge.net/contest/711092#problem/A)

Approach: Sliding Window (Two Pointers)
    - Store the hotel values in a vector.
    - Use a sliding window technique with two pointers (`i` and `j`) to represent the current segment of consecutive hotels.
    - Expand the window by moving the right pointer (`j`) and adding the value of the current hotel to the sum.
    - If the sum exceeds the limit `M`, shrink the window by moving the left pointer (`i`) and subtracting the value of the hotel at `i` from the sum.
    - Track the maximum sum of any valid segment (sum ≤ M) during this process.

Time Complexity: O(N) - Each pointer traverses the array at most once.
Space Complexity: O(N) - To store the hotel values.
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> hotels(N);
    for (int i = 0; i < N; i++) 
        scanf("%d", &hotels[i]);

    int i = 0, j = 0;
    ll sum = 0, max_sum = 0;
    while (j < N) {
        sum += hotels[j++];
        
        while (sum > M && i <= j) 
            sum -= hotels[i++];
        
        max_sum = max(sum, max_sum);
    }

    printf("%lld\n", max_sum);
}