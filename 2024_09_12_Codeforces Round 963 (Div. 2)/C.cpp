#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int a[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		int K; cin >> K;
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		vector<pair<int, int>> cur;
		cur.emplace_back(0, 2 * K - 1);
		
		for (int i = 0; i < n; i++) {
			int r = a[i] % (K * 2);
			int q = a[i] - r;
			vector<pair<int, int>> v;
			if (r > K) {
				v.emplace_back(q + r, q + 2 * K - 1);
				v.emplace_back(q + 2 * K + 0, q + 2 * K + r - K - 1);
			} else {
				v.emplace_back(q + r, q + r + K - 1);
			}
			
			vector<pair<int, int>> nxt;
			
			for (auto u1 : cur) {
				for (auto u2 : v) {
					int a = u1.first % (K + K);
					int b = u1.second % (K + K);
					
					int q1 = u1.first - a;
					
					assert (a <= b);
					
					int c = u2.first % (K + K);
					int d = u2.second % (K + K);
					int q2 = u2.first - c;
					
					assert (c <= d);
					
					int st = max(a, c);
					int en = min(b, d);
					
					if (st <= en) {
						nxt.emplace_back(st + max(q1, q2), en + max(q1, q2));
					}
				}
			}
			
			cur = nxt;
		}
		
		if (cur.size() == 0) {
			cout << -1 << "\n";
		} else {
			int ans = -1;
			for (auto u : cur) {
				if (ans == -1 || ans > u.first)
					ans = u.first;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
