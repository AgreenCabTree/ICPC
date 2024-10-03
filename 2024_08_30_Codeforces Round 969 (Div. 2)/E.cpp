#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 100;

int dp[N][N];

int dis[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, m; cin >> n >> m;
		
		for (int i = 1; i <= n; i++) 
			dis[i] = 0;
		
		for (int i = 0; i < m; i++) {
			int l, r; cin >> l >> r;
			dis[l] = r;
		}
		
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = -1;
		
		dp[0][0] = 0;
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) if (dp[i][j] >= 0) {
				if (dis[i+1]) {
					for (int k = 1; k < dis[i+1] - i; k++) {
						dp[dis[i+1]][j+k] = max(dp[dis[i+1]][j+k], dp[i][j] + k * (i - j));
					}
				} else {
					dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (i - j));
					dp[i+1][j+0] = max(dp[i+1][j+0], dp[i][j]);
				}
			}
		}
		
		int ans = 0;
		for (int i = 0; i <= n; i++) if (dp[n][i] >= 0) {
			ans = max(ans, dp[n][i] + i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
		}
		
		cout << ans << "\n";
	}
	return 0;
}
