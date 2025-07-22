#include <bits/stdc++.h>
using namespace std;

#define maxn 105
#define maxm 105

int n, m;
int grid[maxn][maxm];
int max_gcd = -1;

vector<int> dx = {1, 0};
vector<int> dy = {0, 1};

// Memo[x][y][g]: já visitei a posição (x,y) com GCD atual igual a g
unordered_map<int, bool> memo[maxn][maxm];

int calculate_gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (b % a == 0) return a;

    return gcd(b % a, a);
}

void dfs(int x, int y, int prev_gcd) {
    if (memo[x][y].count(prev_gcd)) return;
    memo[x][y][prev_gcd] = true;

	if (x == n - 1 && y == m - 1) {
        int current_gcd = calculate_gcd(prev_gcd, grid[x][y]);
        max_gcd = max(max_gcd, current_gcd);
        return;
    }

    for (int k = 0; k < 2; k++) {
		int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;

        int current_gcd = calculate_gcd(prev_gcd, grid[nx][ny]);
        dfs(nx, ny, current_gcd);
	}
}

int solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	
    max_gcd = -1;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            memo[i][j].clear();

    dfs(0, 0, grid[0][0]);

    return max_gcd;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}