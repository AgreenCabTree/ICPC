#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 100;

int n, m;

struct node {
	long long rsum;
	long long csum;
	int cnt;
	
	node(long long rsum = 0, long long csum = 0, int cnt = 0)
		:rsum(rsum), csum(csum), cnt(cnt) {}
		
	node operator+=(const node &rhs) {
		rsum += rhs.rsum;
		csum += rhs.csum;
		cnt += rhs.cnt;
		return *this;
	}
	
	node operator-(const node &rhs) {
		return node(rsum - rhs.rsum, csum - rhs.csum, cnt - rhs.cnt);
	}
};

inline int lowbit(int x) {
	return x & (-x);
}

struct Tree {
	int L;
	vector<node> a;
	node sum;
	
	void init() {
		L = n + m;
		a.resize(L);
		for (int i = 0; i < L; i++) a[i] = node();
		sum = node();
	}
	
	void insert(int r, int c, int t) {
		int id = r - c + m;
		
		while (id < L) {
			a[id] += node(r * t, c * t, 1 * t);
			id += lowbit(id);
		}
		
		sum += node(r * t, c * t, 1 * t);
	}
	
	node getsum(int id) {
		if (id < 0) 
			return node();
		
		node ret;
		
		while (id > 0) {
			ret += a[id];
			id -= lowbit(id);
		}
		
		return ret;
	}
	
	node getsum(int l, int r) {
		return getsum(r) - getsum(l - 1);
	}
};

Tree bigS, smallS;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
//	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		cin >> n >> m;
		
		bigS.init();
		smallS.init();
		
		vector<vector<int>> m_map;
		
		m_map.resize(n);
		for (int i = 0; i < n; i++) {
			m_map[i].resize(m);
			for (int j = 0; j < m; j++) {
				cin >> m_map[i][j];
				
				if (m_map[i][j] == 1) {
					bigS.insert(i, j, 1);
				} else if (m_map[i][j] == 2) {
					bigS.insert(i, j, -1);
				}
			}
		}
		
		vector<vector<long long>> ans;
		ans.resize(n);
		for (int i = 0; i < n; i++) {
			ans[i].resize(m);
		}
		
		vector<pair<int, int>> vec;
		
		for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) vec.emplace_back(r, c);
		
		sort(vec.begin(), vec.end(), [&](const pair<int, int> &lhs, const pair<int, int> &rhs) {
			return lhs.first + lhs.second < rhs.first + rhs.second;	
		});
		
		for (auto pt : vec) {
			int r = pt.first;
			int c = pt.second;
			
			int d = r - c + m;
			
			ans[r][c] = 0;
			
			node cur;
			
			cur = bigS.getsum(d);
			
			ans[r][c] += cur.csum - 1LL * cur.cnt * c;
			
			cur = bigS.sum - cur;
			ans[r][c] += cur.rsum - 1LL * cur.cnt * r;
			
			cur = smallS.getsum(d);

			ans[r][c] += 1LL * cur.cnt * r - cur.rsum;
			
			cur = smallS.sum - cur;
			ans[r][c] += 1LL * cur.cnt * c - cur.csum;
			
			if (m_map[r][c] == 1) {
				bigS.insert(r, c, -1);
				smallS.insert(r, c, 1);
			} else if (m_map[r][c] == 2) {
				bigS.insert(r, c, 1);
				smallS.insert(r, c, -1);
			}
		}
		
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				cout << abs(ans[r][c]) << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
