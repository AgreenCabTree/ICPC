#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

vector<int> adj[N];
int fa[N];

void dfs1(int u, int p) {
	fa[u] = p;
	for (auto v: adj[u]) {
		if (v != p) {
			dfs1(v, u);
		}
	}
}

bool special_one[N];

int max_dep[N];

int dfs2(int u, int p) {
	int ret = 0;
	for (auto v : adj[u]) if (v != p) {
		int dep = dfs2(v, u);
		if (special_one[v] == false) {
			ret = max(ret, dep + 1);
		}
	}
	max_dep[u] = ret;
	return ret;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		int n; cin >> n;
		
		for (int i = 1; i <= n; i++) 
			adj[i].clear();
			
		for (int i = 1; i <= n; i++) special_one[i] = false;
		
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs1(1, -1);
		
		int qu, qv; cin >> qu >> qv;
		
		vector<int> path;
		
		for (int i = qu; i != 1; i = fa[i]) {
			special_one[i] = true;
			path.push_back(i);
		}
		
		special_one[1] = true;
		
		dfs2(1, -1);
		
		path.push_back(1);
		
		reverse (path.begin(), path.end());
		
		bool aliceWin = false;
		
		vector<int> bobWays;
		bobWays.resize(path.size());
		
		for (int i = (int)path.size() - 1; i >= 0; i--) {
			bobWays[i] = ((int)path.size() - 1 - i) + max_dep[path[i]];
			if (i != (int)path.size() - 1) {
				bobWays[i] = max(bobWays[i], bobWays[i+1]);
			}
		}
		
		for (int i = 0; i < ((int)path.size() + 1) / 2; i++) {
			int aliceWay = i + max_dep[path[i]];
			int bobWay = bobWays[i + 1];
			
			if (aliceWay > bobWay) {
				aliceWin = true;
				break;
			}
		}
		
		if (aliceWin) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
	
	return 0;
}
