#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int visid = 0;
int vis[N];

int f[N], g[N], L[N], R[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, m; cin >> n >> m;
		
		vector<pair<int, int>> bridge;
		
		int MV = 0;
		
		for (int i = 0; i < n; i++) {
			++ visid;
			
			int L; cin >> L;
			for (int j = 0; j < L; j++) {
				int v; cin >> v;
				if (v >= N) continue;
				vis[v] = visid;
			}
			
			int num[2], numsp = 0;
			for (int j = 0; j < N; j++) {
				if (vis[j] != visid) {
					num[numsp++] = j;
					if (numsp == 2) break;
				}
			}
			
			bridge.emplace_back(num[0], num[1]);
			MV = max(MV, num[1]);
		}
		
		vector<vector<int>> adj;
		adj.resize(MV + 1);
		for (auto u : bridge)
			adj[u.first].push_back(u.second);
		
		memset (f, 0, sizeof (int) * (MV + 1));
		memset (g, 0, sizeof (int) * (MV + 1));
		memset (L, 0, sizeof (int) * (MV + 1));
		memset (R, 0, sizeof (int) * (MV + 1));
		
		for (int i = MV; i >= 0; i--) {
			f[i] = i;
			for (auto v : adj[i]) {
				f[i] = max(f[i], f[v]);
			}
			
			g[i] = 0;
			if (adj[i].size() > 1) {
				g[i] = f[i];
			} else if (adj[i].size() == 1){
				g[i] = i;
			}
		}
		
		for (int i = 0; i < MV; i++) {
			L[i] = g[i];
			if (i > 0) L[i] = max(L[i-1], L[i]);
		}
		
		for (int i = MV; i >= 0; i--) {
			R[i] = g[i];
			if (i < MV) R[i] = max(R[i+1], R[i]);
		}
				
		long long ans = 0;
		
		for (int d = 0; d <= m; d++) {
			if (d > MV) {
				ans += 1LL * (m + d) * (m - d + 1) / 2;
				break;
			}
			
			int max_g = 0;
			if (d) max_g = max(max_g, L[d - 1]);
			if (d < MV) max_g = max(max_g, R[d + 1]);
			
			max_g = max(max_g, f[d]);
			ans += max_g;
		}
		
		cout << ans << "\n";
	}
	return 0;
}
