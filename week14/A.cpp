#include <bits/stdc++.h>
using namespace std;

class Point {
    double x = 0, y = 0;
public:
    Point(double x, double y) : x(x), y(y) {}

    double GetX() { return x; }
    double GetY() { return y; }

    double GetDistance(const Point& other)  {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

class Triangle {
    Point a, b, c;
public:  
    Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {}

    double GetPerimeter() {
        return a.GetDistance(b) + b.GetDistance(c) + c.GetDistance(a);
    }

    double GetArea() {
        double s = GetPerimeter() / 2;
        return sqrt(s * (s - a.GetDistance(b)) * (s - b.GetDistance(c)) * (s - c.GetDistance(a)));
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(4) << fixed;

    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    Point a(x1, y1);
    Point b(x2, y2);
    Point c(x3, y3);
    Triangle triangle(a, b, c);

    cout << triangle.GetPerimeter() << " ";
    cout << triangle.GetArea() << endl;

    return 0;
}