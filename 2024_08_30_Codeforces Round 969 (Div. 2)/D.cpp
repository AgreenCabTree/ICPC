#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int deg[N];
char str[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		
		for (int i = 1; i <= n; i++) deg[i] = 0;
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			++ deg[u];
			++ deg[v];
		}
		
		cin >> str;
		
		int leaf_cnt = 0;
		int zero_cnt = 0;
		int one_cnt = 0;
		int empty_cnt = 0;
		
		int w = 0;
		for (int i = 2; i <= n; i++) {
			char ch = str[i - 1];
			if (deg[i] == 1) {
				++ leaf_cnt;
				if (ch == '0') {
					++ zero_cnt;
				} else if (ch == '1') {
					++ one_cnt;
				} else {
					++ empty_cnt;
				}
			} else if (ch == '?') {
				++ w;
			}
		}
		
		if (str[0] == '?') {
			if (one_cnt > zero_cnt) {
				cout << one_cnt + empty_cnt / 2 << "\n";
			} else if (one_cnt < zero_cnt) {
				cout << zero_cnt + empty_cnt / 2 << "\n";
			} else {
				if (w % 2 == 0) {
					cout << one_cnt + empty_cnt / 2 << "\n";
				} else {
					cout << one_cnt + (empty_cnt + 1) / 2 << "\n";
				}
			}
		} else if (str[0] == '0') {
			cout << one_cnt + (empty_cnt + 1) / 2 << "\n";
		} else if (str[0] == '1') {
			cout << zero_cnt + (empty_cnt + 1) / 2 << "\n";
		}
	}
	return 0;
}
