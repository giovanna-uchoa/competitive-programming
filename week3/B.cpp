/*
Problem: B - Interesting Drink
Source: Vjudge (https://vjudge.net/contest/702854#problem/B)

Approach:
  - Sort the drink prices.
  - For each query, perform binary search to find the number of elements ≤ m.
  - Handles edge cases explicitly: when m is smaller than the cheapest drink,
    or greater than or equal to the most expensive.

Time Complexity:
  - Preprocessing: O(n log n) for sorting
  - Each query: O(log n)
  - Total: O(n log n + q log n)
Space Complexity: O(n) for storing drink prices

Error Encountered:
  - The code was also modified to use `scanf` and `printf` for faster input/output.
*/

#include <bits/stdc++.h>
using namespace std;

bool check(int mid, int x){
    return mid > x;
}

int lower_or_equal_m(int m, vector<int> x){
    int lo = 0, hi = x.size(), mid;

    while(lo+1 < hi){
        mid = (lo+hi)/2;
        if (!check(x[mid], m)) lo = mid;
        else hi = mid;
    }

    return lo+1;
}

int main(){
    int n, q, m;
    scanf("%d", &n);

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    
    sort(x.begin(), x.end());
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &m);
        
        int ans;
        if (m < x[0]) ans = 0;
        else if (m >= x[n-1]) ans = n;
        else ans = lower_or_equal_m(m, x);

        printf("%d\n", ans);
    }
    
    return 0;
}