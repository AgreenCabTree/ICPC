#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

long long H[N];

long long a[N];
long long b[N];

long long calc(long long a, int K) {
	long long maxv = 1e18 + 1e9 + 100;
	long long r = maxv / K;
	if (r <= a) 
		return maxv;
	return a * K;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, x, K; 
		cin >> n >> x >> K;
		
		map<long long, int> M;
		
		for (int i = 0; i < n; i++) {
			cin >> H[i];
			++ M[H[i]];
		}
		
		int an, bn;
		
		an = bn = 0;
		
		for (auto u : M) {
			a[an++] = u.first;
			if (u.second == 1)
				b[bn++] = u.first;
		}
		
		int ans = lower_bound(a, a + an, calc(1LL * x, K)) - a;
		
		for (int i = 0; i < n; i++) if (H[i] < x) {
			int cnt1 = lower_bound(a, a + an, x) - lower_bound(a, a + an, H[i]);
			int cnt2 = lower_bound(a, a + an, calc(H[i], K)) - a;
			
			cnt1 = max(cnt1, 0);
			cnt2 = max(cnt2, 0);
			
			int cnt3 = lower_bound(b, b + bn, calc(H[i], K)) - lower_bound(b, b + bn, H[i]);
			cnt3 = max(cnt3, 0);
			
			ans = max(ans, cnt1 + cnt2 - cnt3);
		}
		
		cout << ans << "\n";
	}
	return 0;
}
