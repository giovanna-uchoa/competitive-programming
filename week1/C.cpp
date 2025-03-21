/*
Problem: Maximum Subset Sum
Source: SPOJ (https://www.spoj.com/problems/MAXSUMSU/en/)
Constraints: All input fits in the integer size.
Approach:
    - Use Kadane's algorithm to find the maximum subarray sum in O(n) time:
        - Iterate through the array while keeping track of the maximum sum encountered so far.
Time Complexity: O(n) per test case
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    int t_size;
    long t_current_int, max_subset_sum, current_subset_sum;
    for (int i = 0; i < t; i++) {
        cin >> t_size;
        
        current_subset_sum = 0;
        max_subset_sum = t_size == 0 ? 0 : INT_MIN;
        for (int j = 0; j < t_size; j++) {
            cin >> t_current_int;
            current_subset_sum = max(current_subset_sum + t_current_int, t_current_int);
            max_subset_sum = max(current_subset_sum, max_subset_sum);
        }
        cout << max_subset_sum << endl;
    }
}