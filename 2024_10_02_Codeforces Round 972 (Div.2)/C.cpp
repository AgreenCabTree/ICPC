#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1000;

const int N = 2e5 + 100;
const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;


int f[N];

vector<int> adj[N];

struct node {
	int d[3];
	
	node (int r = 0, int g = 0, int b = 0) {
		d[0] = r;
		d[1] = g;
		d[2] = b;
	}
};

int ans2 = 1;

node dfs(int u, int p, int dr, int dg, int db) {
	if (dr >= LIMIT) dr = LIMIT;
	if (dg >= LIMIT) dg = LIMIT;
	if (db >= LIMIT) db = LIMIT;
	
	int maxv = max(dr, dg);
	maxv = max(maxv, db);
	
	int max_cnt = 0;
	if (dr == maxv) ++ max_cnt;
	if (dg == maxv) ++ max_cnt;
	if (db == maxv) ++ max_cnt;
	
//	cerr << u << "," << dr << "," << dg << "," << db << endl;
	if (dr >= dg && dr >= db) {
		f[u] = RED;
		dr = 0;
	} else if (dg >= dr && dg >= db) {
		f[u] = GREEN;
		dg = 0;
	} else {
		f[u] = BLUE;
		db = 0;
	}
	
	ans2 *= max_cnt;
	
	for (auto v : adj[u]) if (v != p) {
		node ret = dfs(v, u, dr + 1, dg + 1, db + 1);
		dr = min(dr, ret.d[RED] + 1);
		dg = min(dg, ret.d[GREEN] + 1);
		db = min(db, ret.d[BLUE] + 1);
	}
	
	return node(dr, dg, db);
}

int dis[N];
int vis[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		
		for (int i = 1; i <= n; i++) adj[i].clear();
		
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs(1, -1, LIMIT, LIMIT, LIMIT);
		
		long long ans = 0;
		
//		for (int i = 1; i <= n; i++) {
//			cerr << "#" << i << "," << f[i] << endl;
//		}
		
		for (int c = 0; c < 3; c++) {
			memset (vis, 0, sizeof vis);
			
			queue<int> Q;
			
			for (int i = 1; i <= n; i++) if (f[i] == c) {
				vis[i] = true;
				dis[i] = 0;
				Q.push(i);
			}
			
			while (!Q.empty()) {
				int u = Q.front(); Q.pop();
				for (auto v: adj[u]) if (!vis[v]) {
					vis[v] = true;
					dis[v] = dis[u] + 1;
					Q.push(v);
				}
			}
			
			for (int i = 1; i <= n; i++) {
				assert (vis[i]);
				ans += dis[i];
			}
		}
		
		cout << ans2 << "\n";
	}
	return 0;
}
