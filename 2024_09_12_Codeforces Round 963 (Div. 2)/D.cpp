#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100;

int a[N], f[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		int K; cin >> K;
		
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		int cnt = n % K;
		if (cnt == 0) 
			cnt += K;
			
		int lcnt = (cnt + 1) / 2;
		int rcnt = cnt - lcnt + 1;
		
		int st = 1, en = 1e9;
		
		int ans = -1;
		
		while (st <= en) {
			int mid = (st + en) / 2;
			
			int max_ans = -1;
			
			for (int i = 1; i <= n; i++) {
				f[i] = 0;
				
				int r = i % K;
				if (r > 0)
					f[i] = max(f[i], f[i-1] + (a[i] >= mid));
				if (i >= K)
					f[i] = max(f[i], f[i - K]);
					
				if ((n - i) % K == 0) {
					int v = max(f[i-1] + (a[i] >= mid), i >= K ? f[i-K] : 0);
					max_ans = max(max_ans, v);
				}
			}
			
			if (max_ans >= rcnt) {
				ans = mid;
				st = mid + 1;
			} else {
				en = mid - 1;
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}
