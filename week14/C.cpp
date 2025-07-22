#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
  ll x = 0, y = 0;
};

// |∑(xiyi+1 - xi+1yi)| / 2
ll shoelace_formula(const Point& a, const Point& b)  {
    return a.x * b.y - a.y * b.x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    
    ll doubled_area = 0;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    for (int i = 0; i < n; i++)
        doubled_area += shoelace_formula(points[i], points[(i + 1) % n]);

    cout << abs(doubled_area) << "\n";
    return 0;
}