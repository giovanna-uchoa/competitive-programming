#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, cx, cy; // Radius and Center of the circle
    int x1, y1, x2, y2; // Coordinates of the line segment endpoints
    cin >> R >> cx >> cy >> x1 >> y1 >> x2 >> y2;
 
    // Direção da reta
    double dx = x2 - x1;
    double dy = y2 - y1;

    // Parâmetros da equação quadrática At² + Bt + C = 0
    double A = dx*dx + dy*dy;
    double B = 2 * (dx*(x1 - cx) + dy*(y1 - cy));
    double C = (x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy) - R*R;

    double D = B*B - 4*A*C; // Discriminante
    
    if (D < -EPS) {
        cout << -1 << endl; // Não intersecta
    } else if (fabs(D) < EPS) {
        cout << fixed << setprecision(5) << 0.0 << endl; // Toca o círculo
    } else {
        // Duas interseções
        double sqrtD = sqrt(D);
        double t1 = (-B - sqrtD) / (2*A);
        double t2 = (-B + sqrtD) / (2*A);

        // Clampa os valores de t para limitar ao segmento entre os pontos
        double t_min = max(0.0, min(t1, t2));
        double t_max = min(1.0, max(t1, t2));

        if (t_min > t_max) {
            // O segmento entre os pontos não intercepta a parte dentro do círculo
            cout << -1 << endl;
        } else {
            // Calcula os pontos de interseção reais no segmento
            double x_start = x1 + dx * t_min;
            double y_start = y1 + dy * t_min;
            double x_end = x1 + dx * t_max;
            double y_end = y1 + dy * t_max;

            // Distância entre os pontos de interseção
            double len = sqrt((x_end - x_start)*(x_end - x_start) + (y_end - y_start)*(y_end - y_start));
            cout << fixed << setprecision(5) << len << endl;
        }
    }

    return 0;
}