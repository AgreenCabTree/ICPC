#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 100;

int dp[N][N];

int dis[N], c[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, m; cin >> n >> m;
		
//		cout << n << "," << m << endl;
		
		for (int i = 0; i <= n + 1; i++) 
			dis[i] = 0, c[i] = -1;
			
		vector<pair<int, int>> adj;		
		
		for (int i = 0; i < m; i++) {
			int l, r; cin >> l >> r;
			adj.emplace_back(l, r);
		}
		
		sort (adj.begin(), adj.end());
		
		int mnl = adj[0].first;
		int mxl = mnl;
		int mnr = adj[0].second;
		int mxr = mnr;
		
		bool isError = false;
		
		
		
		for (int i = 1; i <= m; i++) {
			if (i == m || adj[i].first > mxr) {
				if (mxl >= mnr) {
					cout << "-1" << endl;
					isError = true;
					break;
				}
				
				dis[mxl] = mnr;
				for (int j = mnl; j < mxl; j++) 	 c[j] = 0;
				for (int j = mnr + 1; j <= mxr; j++) c[j] = 1;
				
				if (i < m) {
					mnl = mxl = adj[i].first;
					mnr = mxr = adj[i].second;
				}
			} else {
				mxl = max(mxl, adj[i].first);
				mnr = min(mnr, adj[i].second);
				mxr = max(mxr, adj[i].second);
			}
			
//			cout << i << "," << mnl << "," << mxl << ',' << mnr << "," << mxr << endl;
		}		
		
//		cout << "ok1" << endl;
		if (isError)
			continue;
		
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = -1;
		
		dp[0][0] = 0;
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) if (dp[i][j] >= 0) {
				if (dis[i+1]) {
					for (int k = 1; k < dis[i+1] - i; k++) {
						dp[dis[i+1]][j+k] = max(dp[dis[i+1]][j+k], dp[i][j] + k * (i - j));
					}
				} else {
					if (c[i+1] != 1)
						dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (i - j));
					if (c[i+1] != 0)
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
