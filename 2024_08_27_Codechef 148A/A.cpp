#include <iostream>
#include <vector>

using namespace std;

const int maxn = 200010;

int n;
vector<int> adj[maxn];
int subtree_size[maxn];

int get_subtree_size(int node, int parent = -1) {
	int &res = subtree_size[node];
	res = 1;
	for (int i : adj[node]) {
		if (i == parent) { continue; }
		res += get_subtree_size(i, node);
	}
	return res;
}

int get_centroid(int node, int parent = -1) {
	for (int i : adj[node]) {
		if (i == parent) { continue; }
		if (subtree_size[i] * 2 > n) { return get_centroid(i, node); }
	}
	return node;
}

int solve(int u, int p = -1) {
	
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int a, b;
		cin >> a;
		b = i;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	get_subtree_size(1);
	
	solve(1);	
	cout << get_centroid(1) + 1 << endl;
	
	dfs(0)
}
