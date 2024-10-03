#include <bits/stdc++.h>
using namespace std;

const int N = 1024;

int fa[N];

int dfs(int u) {
	if (fa[u] == u)
		return u;
	return fa[u] = dfs(fa[u]);
}

void join(int u, int v) {
	int fu = dfs(u);
	int fv = dfs(v);
	fa[fu] = fv;
}

int query(int u, int v) {
	cout << "? " << u << " " << v << endl;
	cout.flush();
	int t;
	cin >> t;
	return t;	
}

pair<int, int> find(int u, int v) {
	int t = query(u, v);
	int ft = dfs(t);
	int fu = dfs(u);
	int fv = dfs(v);
	assert (fu != fv);
	
	if (t == u || t == v) {
		return make_pair(u, v);
	}
	
	if (ft != fu) {
		return find(u, t);
	} else {
		return find(v, t);
	}
}

int main() {
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) fa[i] = i;
		
		vector<pair<int, int>> vec;
		for (int loop = 1; loop < n; loop ++) {
			int p[2], pcnt = 0;
			
			for (int i = 1; i <= n; i++) if (fa[i] == i) {
				p[pcnt++] = i;
				if (pcnt == 2) break;	
			}
			
			pair<int, int> edge = find(p[0], p[1]);
			join(edge.first, edge.second);
			
			vec.push_back(edge);
		}
		
		cout << "!";
		for (int i = 0; i < (int)vec.size(); i++) {
			cout << " " << vec[i].first << " " << vec[i].second;
		}
		cout << endl;
		cout.flush();
	}	
	return 0;
}
