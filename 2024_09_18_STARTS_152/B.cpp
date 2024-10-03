#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int cnt[3][N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		int n, Q; cin >> n >> Q;
	
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < 3; k++) {
				cnt[k][i] = cnt[k][i-1];
			}
			
			int t; cin >> t;
			
			++ cnt[t - 1][i];
		}
		
		while (Q--) {
			int L, R; cin >> L >> R;
			int len = R - L + 1;
			if ((R - L + 1) % 2 == 1) {
				cout << "No\n";
			} else {
				int ret[3];
				
				for (int v = 0; v < 3; v++) {
					int x = cnt[v][R] - cnt[v][L - 1];
					ret[v] = x;					
				}
				
				sort (ret, ret + 3);
				
				if (ret[2] == len / 2)
					cout << "Yes\n";
				else
					cout << "No\n";
			}
		}
	}
	return 0;
}
