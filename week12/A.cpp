#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n; 
    cin >> n;

    vector<pair<int, int>> movies(n); // END, START
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        movies[i] = {r, l};
    }

    sort(movies.begin(), movies.end());

    int ans = 0;
    int last_end = 0; // The end of the last movie that was added to the schedule
    for (const auto& [end, start] : movies) {
        if (start >= last_end) {
            ans++;
            last_end = end; // Update the end of the last added movie
        }
    }

    // Output the maximum number of non-overlapping movies that can be scheduled
    cout << ans << endl;
    return 0;
}