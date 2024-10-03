#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int visid = 0;
int vis[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, m; cin >> n >> m;
		
		vector<pair<int, int>> bridge;
		
		multiset<int> S;
		
		for (int i = 0; i < n; i++) {
			++ visid;
			
			int L; cin >> L;
			for (int j = 0; j < L; j++) {
				int v; cin >> v;
				if (v >= N) continue;
				vis[v] = visid;
			}
			
			int num[2], numsp = 0;
			for (int j = 0; j < N; j++) {
				if (vis[j] != visid) {
					num[numsp++] = j;
					if (numsp == 2) break;
				}
			}
			
			bridge.emplace_back(num[1] - 1, num[1]);
			S.insert(num[1]);
		}
		
		sort (bridge.begin(), bridge.end());
		
		long long ans = 0;
		
		int pos = 0;
		
		for (int d = 0; d <= m; d++) {
			if (S.size() == 0) {
				ans += 1LL * (m + d) * (m - d + 1) / 2;
				break;
			}
			
			ans += *S.rbegin();
			
//			cout << "f[" << d << "]=" << *S.rbegin() << endl;
			while (pos < (int)bridge.size() && bridge[pos].first <= d) {
				S.erase(S.find(bridge[pos].second));
				pos++;
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}
