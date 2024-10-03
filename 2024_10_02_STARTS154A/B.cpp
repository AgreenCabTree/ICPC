#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

vector<int> adj[N];
int fa[20][N];
int dep[N];
int minv[20][N];
int maxv[20][N];

void dfs(int u, int p, int depth) {
	dep[u] = depth;
	
	fa[0][u] = p;
	minv[0][u] = u;
	maxv[0][u] = u;
	
	for (int i = 1; (1 << i) <= depth; i++) {
		fa[i][u] = fa[i-1][fa[i-1][u]];
	}
	
	for (int i = 1; (1 << i) <= depth + 1; i++) {
		minv[i][u] = min(minv[i-1][u], minv[i-1][fa[i-1][u]]);
		maxv[i][u] = max(maxv[i-1][u], maxv[i-1][fa[i-1][u]]);
	}
		
	for (auto v : adj[u]) if (v != p)
		dfs(v, u, depth + 1);
}

struct node {
	int minv, maxv;
	node (int minv = 0, int maxv = 0)
		:minv(minv), maxv(maxv) {}
};

const int inf = 1e9;

node get_info(int u, int v) {
	int mnv = inf;
	int mxv = -inf;
	
	for (int i = 20; i >= 0; i--) if (dep[u] - (1 << i) >= dep[v]) {
		mnv = min(mnv, minv[i][u]);
		mxv = max(mxv, maxv[i][u]);
		u = fa[i][u];
	}
	
	for (int i = 20; i >= 0; i--) if (dep[v] - (1 << i) >= dep[u]) {
		mnv = min(mnv, minv[i][v]);
		mxv = max(mxv, maxv[i][v]);
		v = fa[i][v];
	}
	
	if (u == v) {
		mnv = min(mnv, u);
		mxv = max(mxv, v);
		
		return node(mnv, mxv);
	}
	
	for (int i = 20; i >= 0; i--) if (dep[u] >= (1 << i)){
		int fu = fa[i][u];
		int fv = fa[i][v];
		
		if (fu == fv) continue;
		
		mnv = min(mnv, minv[i][u]);
		mnv = min(mnv, minv[i][v]);
		
		mxv = max(mxv, maxv[i][u]);
		mxv = max(mxv, maxv[i][v]);
		
		u = fu;
		v = fv;
	}
	
	mnv = min(mnv, fa[0][u]);
	mxv = max(mxv, fa[0][v]);
	
	assert (fa[0][u] == fa[0][v]);
	
	return node(mnv, mxv);
}

vector<pair<int, int>> vadj[N];

struct pnode {
	int u, dis;
	pnode(int u = 0, int dis = 0)
		:u(u), dis(dis) {}
		
	bool operator<(const pnode &rhs) const {
		return dis > rhs.dis;
	}
};

bool vis[N];
int dis[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, S; cin >> n >> S;
		
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			vadj[i].clear();
			vis[i] = false;
			dis[i] = inf;
		}
		
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs(1, -1, 0);
		
		for (int i = 1; i <= n; i++) {
			int r = min(n, 2 * n / i);
			for (int j = 1; j <= r; j++) {
				node pi = get_info(i, j);
				if (1LL * pi.minv * pi.maxv > 4 * n) continue;
				vadj[i].emplace_back(j, pi.minv * pi.maxv);
				vadj[j].emplace_back(i, pi.minv * pi.maxv);
			}
		}
		
		priority_queue<pnode> pq;
		
		pq.push(pnode(S, 0));
		
		while (!pq.empty()) {
			pnode cur = pq.top(); pq.pop();
			if (vis[cur.u]) continue;
			
			vis[cur.u] = true;
			dis[cur.u] = cur.dis;
			
			for (auto pi : vadj[cur.u]) {
				int v = pi.first;
				int d = pi.second;
				
				if (vis[v]) continue;
				
				if (d + cur.dis > 2 * n) continue;
				
				pq.push(pnode(v, d + cur.dis));
			}
		}
		
		for (int i = 1; i <= n; i++) {
			cout << dis[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
