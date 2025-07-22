#include <bits/stdc++.h>
using namespace std;

#define maxn 1005
#define maxm 1005

int n, m;
char grid[maxn][maxm];
bool vis[maxn][maxm];

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

void dfs(int i, int j) {
	vis[i][j] = true; 
	for (int k = 0; k < 4; k++) {
		int ni = i + dx[k], nj = j + dy[k];
		if (ni < 1 or ni > n or nj < 1 or nj > m) continue;
		if (grid[ni][nj] == '#' or vis[ni][nj]) continue;
		dfs(ni, nj);
	}
}

int main() {   
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
        }
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == '.' && !vis[i][j]) {
				ans++;
				dfs(i, j);
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}