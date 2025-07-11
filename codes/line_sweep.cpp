/* Line Sweep Algorithm to find the maximum number of overlapping intervals
 * This code reads a set of intervals, compresses their coordinates, and then uses a line sweep technique to find the maximum number of overlapping intervals at any point.
 * The algorithm works by sorting the start and end points of the intervals, and then sweeping through these points while maintaining a count of active intervals.
 *
 * Problem: https://codeforces.com/problemset/gymProblem/102961/E
 * Complexity of the algorithm is O(n log n) due to sorting, where n is the number of intervals.
 * The space complexity is O(n) for storing the events.
 */
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define int ll
#define pb push_back
#define all(v) (v).begin(), (v).end()
 
void dbg_out() { cerr << endl; }
template<typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) // { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
 
vector<pair<int, int>> comprimir_coordenada(vector<pair<int, int>> a) {
	vector<int> pos;
	for(auto [l, r] : a) {
		pos.pb(l);
		pos.pb(r);
	}
	sort(all(pos));
	
	for(auto &[l, r] : a) {
		l = lower_bound(all(pos), l) - pos.begin();
		r = lower_bound(all(pos), r) - pos.begin();
	}
	return a;
}
 
void solve() {
	int n; cin >> n;
	
	vector<pair<int, int>> a(n);
	for(auto &[l, r] : a) cin >> l >> r;
	a = comprimir_coordenada(a);
	
	vector<int> events[2 * n];
	for(auto [l, r] : a) {
		events[l].push_back(0);
		events[r].push_back(1);
	}
		
	int ans = 0, ativos = 0;
	for(int i = 0; i < 2 * n; i++) {
		auto events_x = events[i];
		for(auto event : events_x) if(event == 0) {
			dbg(x, 0);
			ativos++;
		}
		ans = max(ans, ativos);
		for(auto event : events_x) if(event == 1) {
			ativos--;
			dbg(x, 1);
		}
	}
	cout << ans << endl;
}
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}