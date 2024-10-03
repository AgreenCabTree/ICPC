#include <bits/stdc++.h>
using namespace std;

inline int f (int x, int y) {
	if (x == 0 && y == 0)
		return 1;
	return 0;	
}

const int BX = 6;
const int L = 1 << BX;

const int N = 3e5 + 100;

char str[N];

int n;

namespace BRUTE_SOLVE {
	int vis[L];
	
	vector<int> ans;
	int ans_cnt;
	
	void dfs(int u, vector<int> path) {
		if (vis[u])
			return;
			
		vis[u] = true;
		
		cerr << u << "," << n << endl;
		
		int num[BX];
		int ret = 0;
		
		for (int i = 0; i < n; i++) {
			num[i] = !!(u & (1 << i));
			ret += num[i];
			cerr << "##" << num[i] << endl;
		}
		
		if (ans_cnt < ret) {
			ans_cnt = ret;
			ans = path;
		}
		
		cerr << u << "," << n << endl;
		
		for (int i = 1; i < n - 1; i++) {
			int a = num[i-1];
			int b = num[i+1];
			
			num[i-1] = f(num[i-1], num[i]);
			num[i+1] = f(num[i], num[i+1]);
			
			int v = 0;
			for (int j = 0; j < n; j++) {
				cerr << "@@" << num[j] << endl;
				v = v + (num[j] << j);
			}
			
			cerr << "####" << v << endl;
			
			path.push_back(i + 1);
			dfs(v, path);
			path.pop_back();
			
			num[i-1] = a;
			num[i+1] = b;
		}
		
		cerr << u << "," << n << endl;
	}
		
	pair<vector<int>, int> brute_solve() {
		assert (n <= 5);
		
		memset (vis, 0, sizeof vis);
		
		ans_cnt = 0;
		ans.clear();
		
		int d = 0;
		for (int i = 0; i < n; i++) {
			d = d + ((str[i] == '1') << i);
			ans_cnt += (str[i] == '1');
		}
			
		vector<int> cur_path;
		
		cerr << "before_dfs" << "\n";
		dfs(d, cur_path);
		
		cerr << "after_dis" << "\n";
		return make_pair(ans, ans_cnt);
	}
};

namespace TALENT_SOLVE {
	vector<int> adj[L];
	vector<int> path[L];
	int final_vis[L];
	
	void init() {
		for (int d = 0; d < L; d++) {
			int num[BX];
				
			for (int i = 0; i < BX; i++) {
				int b = d & (1 << i);
				num[i] = !!b;
			}
			
			for (int i = 1; i < BX - 1; i++) {
				int a = num[i-1];
				int b = num[i+1];
				
				num[i-1] = f(num[i-1], num[i]);
				num[i+1] = f(num[i], num[i+1]);
				
				int v = 0;
				for (int j = 0; j < BX; j++) {
					v = v + (num[j] << j);
				}
				
				adj[d].push_back(v);
				
				num[i-1] = a;
				num[i+1] = b;
			}
		}
		
		for (int i = 0; i < L; i++) {
			pair<int, int> vis[L];
			memset (vis, -1, sizeof vis);	
			queue<int> Q;
			
			Q.push(i);
			vis[i] = make_pair(0, 0);
			
			while (!Q.empty()) {
				int u = Q.front(); Q.pop();
				for (int i = 0; i < (int)adj[u].size(); i++) {
					int v = adj[u][i];
					if (vis[v].first == -1) {
						vis[v] = make_pair(i + 1, u);
						Q.push(v);
					}
				}
			}
			
			int max_cnt = 0;
			int max_s = 0;
			
			for (int v = 0; v < L; v++) if (vis[v].first != -1) {
				int cnt = 0;
				bool find = false;
				for (int i = 0; i < BX; i++) if (v & (1 << i)) {
					++ cnt;
					if (i == BX - 3) {
						if (cnt == BX - 2) {
							find = true;
						}
					}
				}
				
				if (cnt == 5 && v == 49)
					assert (0);
				
				if (find && max_cnt < cnt) {
					max_cnt = cnt;
					max_s = v;
				}
			}
			
			int tv = max_s;
			while (max_s != i) {
				path[i].push_back(vis[max_s].first);
				max_s = vis[max_s].second;
			}
			
			reverse(path[i].begin(), path[i].end());
			
			final_vis[i] = tv;
			cerr << i << "," << max_cnt << "," << tv << "," << path[i].size() << ",(";
			for (auto t : path[i]) cerr << t << ",";
			cerr << ")\n";
		}
	}
	
	pair<vector<int>, int> solve() {
		vector<int> ans;
		int ans_cnt = 0;
		
		for (int i = 0; i <= n - BX; i++) if (i == n - BX || str[i] == '0'){
			cerr << "before:" << i << endl;
			int d = 0;
			for (int j = 0; j < BX; j++) {
				int b = (str[j + i] == '1');
				d = d + (b << j);
			}
			
			for (int j = 0; j < (int)path[d].size(); j++) {
				ans.push_back(path[d][j] + i + 1);
				
				assert (i + path[d][j] > 0 && i + path[d][j] < n - 1);
				
				int v1, v2, v3;
				v2 = str[i + path[d][j]] - '0';
				v1 = str[i + path[d][j] - 1] - '0';
				v3 = str[i + path[d][j] + 1] - '0';
				
				v1 = f(v1, v2);
				v3 = f(v2, v3);
				
				str[i + path[d][j] - 1] = v1 + '0';
				str[i + path[d][j] + 1] = v3 + '0';
				
//				int fd = 0;
//				for (int j = 0; j < BX; j++) {
//					int b = (str[j + i] == '1');
//					fd = fd + (b << j);
//				}
//				cerr << "#" << fd << "," << endl;
			}
			
			int fd = 0;
			for (int j = 0; j < BX; j++) {
				int b = (str[j + i] == '1');
				fd = fd + (b << j);
			}
			
//			cerr << d << "," << fd << "," << final_vis[d] << endl;
			
//			assert (fd == final_vis[d]);

			cerr << "after:" << i << endl;
		}
		
		for (int i = 0; i < n; i++)
			ans_cnt += (str[i] == '1');
			
		cerr << "ended:";
		return make_pair(ans, ans_cnt);
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	TALENT_SOLVE::init();
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		cin >> n;
		
		cin >> str;
		
		pair<vector<int>, int> ret;
		

		
		if (n < BX) {
			ret = BRUTE_SOLVE::brute_solve();
		} else {
			ret = TALENT_SOLVE::solve();
		}
		
		cout << ret.first.size() << "\n";
		for (int i = 0; i < (int)ret.first.size(); i++) {
			if (i) cout << " ";
			cout << ret.first[i];
		}
		cout << "\n";
	}
	return 0;
}
