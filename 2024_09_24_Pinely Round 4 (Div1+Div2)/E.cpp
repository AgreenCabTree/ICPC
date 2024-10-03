#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 100;

vector<int> adj[N];
int colors[N];

bool dfs(int u, int depth = 0) {
	if (colors[u] == -1)
		colors[u] = depth % 2;
	else {
		if (colors[u] != depth % 2)
			return false;
		return true;
	}
		
	for (auto v : adj[u]) {
		if (!dfs(v, depth + 1))
			return false;
	}
	
	return true;
}

int main() {
//	cin.tie(NULL);
//	cout.tie(NULL);
//	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		int n, m; cin >> n >> m;
		
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 1; i <= n; i++) colors[i] = -1;
		
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		bool ret = dfs(1);
		
		if (ret) {
			cout << "Bob" << endl;
			cout.flush();
			
			set<int> S[3];
			
			for (int i = 1; i <= n; i++) S[colors[i]].insert(i);
			
			for (int round = 0; round < n; round++) {
				int a, b; cin >> a >> b;
				-- a; -- b;
				
				if (a > b) swap(a, b);
				
				if (S[a].size() > 0) {
					int u = *S[a].begin();
					cout << u << " " << a + 1 << endl;
					S[a].erase(u);
				} else if (S[b].size() > 0) {
					int u = *S[b].begin();
					cout << u << " " << b + 1 << endl;
					S[b].erase(u);
				} else {
					if (S[0].size() > 0) {
						int u = *S[0].begin();
						cout << u << " " << b + 1 << endl;
						S[0].erase(u);
					} else if (S[1].size() > 0) {
						int u = *S[1].begin();
						cout << u << " " << b + 1 << endl;
						S[1].erase(u);
					}
				}
				
				cout.flush();
			}
		} else {
			cout << "Alice" << endl;
			cout.flush();
			
			for (int round = 0; round < n; round++) {
				cout << "1 2" << endl;
				cout.flush();
				
				int t1, t2;
				cin >> t1 >> t2;
			}
		}
	}
	return 0;
}
