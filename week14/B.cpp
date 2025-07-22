#include <bits/stdc++.h>
using namespace std;

class Point {
    int x = 0, y = 0;
public:
    Point(int x, int y) : x(x), y(y) {}

    int GetX() const { return x; }
    int GetY() const { return y; }
};

class Line {
    Point p1, p2;
public:
    Line(const Point& a, const Point& b) : p1(a), p2(b) {}

    int relativePosition(const Point& p3) const {
        // Dot product to determine the relative position of point p3
        // vectors (p1 -> p2) = (x2 - x1, y2 - y1) and (p1 -> p3) = (x3 - x1, y3 - y1)
        long long cross = 1LL * (p2.GetX() - p1.GetX()) * (p3.GetY() - p1.GetY()) -
                          1LL * (p2.GetY() - p1.GetY()) * (p3.GetX() - p1.GetX());

        if (cross > 0) return 1;     // LEFT
        if (cross < 0) return -1;    // RIGHT
        return 0;                    // TOUCH
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Point a(x1, y1);
        Point b(x2, y2);
        Point c(x3, y3);

        Line line(a, b);

        switch (line.relativePosition(c)) {
            case 1:
                cout << "LEFT\n";
                break;
            case -1:
                cout << "RIGHT\n";
                break;
            case 0:
                cout << "TOUCH\n";
                break;
        }
    }

    return 0;
}
