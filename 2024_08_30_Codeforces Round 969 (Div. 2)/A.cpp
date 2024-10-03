#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

vector<int> adj[N];

char str[N];

int dp[N][2][2];

void dfs(int u, int p) {
	memset(dp[u], 0, sizeof dp[u]);
	for (auto v : adj[u]) if (v != p) dfs(v, u);
	
	for (int b = 0; b < 2; b++) {
		if (str[u - 1] != '?' && str[u-1] != b + '0') continue;
		if (u != 1) {
			for (int f = 0; f < 2; f++) {
				chkmax(dp[u][f][], dp[v][b][])
			}
		}

	}
}

int main() {		
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		
		for (int i = 1; i <= n; i++) adj[i].clear();
		
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		cin >> str;
		
		dfs(1, -1);
	}
	return 0;
}
