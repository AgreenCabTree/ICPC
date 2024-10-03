#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 100;

int a[N], g[19][N];

int main() {
//	freopen("in.txt", "r", stdin);
	
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n - 1; i++) g[0][i] = abs(a[i+1] - a[i]);
		for (int b = 1; (1 << b) <= (n - 1); b++) {
			for (int i = 0; i + (1 << b) <= (n - 1); i++) {
				g[b][i] = __gcd(g[b-1][i], g[b-1][i+(1<<(b-1))]);
			}
		}
		
		auto range_gcd = [&](int l, int r) {
			if (l == r) 
				return 0;
			-- r;
			int b = __lg(r - l + 1);			
			int v = __gcd(g[b][l], g[b][r - (1 << b) + 1]);
			return v;
		};
		
		auto query = [&](int l, int r) {
			int v = range_gcd(l, r);
			return (v & (-v)) - v;
		};
		
		long long ans = 0;
		
		int j;
		for (int i = 0; i < n; i = j) {
			for (j = i + 1; j < n; j++) if (a[i] != a[j]) break;
			
			int st = j;
			int en = n - 1;
			int ret = -1;
			while (st <= en) {
				int mid = (st + en) / 2;
				if (query(i, mid) == 0) {
					en = mid - 1;
				} else {
					ret = mid;
					st = mid + 1;
				}
			}
			
			
			
			if (ret == -1) {
				for (int k = i; k < j; k++) 
					ans += (n - j) + (j - k);
			} else {
				for (int k = i; k < j; k++) {
					ans += (n - 1 - ret) + (j - k);
				}
			}
		}
				
		cout << ans << "\n";
	}
	return 0;
}
