#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int a[N];

int st[N], en[N], ans[N];

int cnt1[N], cnt2[N];

int main() {	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, Q, K; cin >> n >> Q >> K;
		
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		for (int i = 0; i < Q; i++) {
			cin >> st[i] >> en[i];
			ans[i] = 0;
		}
		
		int R = sqrt(K);
		
		cnt1[0] = cnt2[0] = 0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= n; j++) {
				cnt1[j] = cnt1[j-1] + (a[j] <= i);
				
				int b = K / (i + 1) + 1;
				
				cnt2[j] = cnt2[j-1] + (a[j] >= b);
			}
			
			for (int j = 0; j < Q; j++) {
				int r1 = cnt1[en[j]] - cnt1[st[j] - 1];
				int r2 = cnt2[en[j]] - cnt2[st[j] - 1];
				int l = en[j] - st[j] + 1;
				
				if (r2 > r1) {
					if (r2 <= l / 2) {
						ans[j] = max(ans[j], (r2 - r1 + 1) / 2);
					} else if (r1 >= l / 2) {
					} else {
						if (l / 2 - r1 <= r2 - l / 2) {
							ans[j] = max(ans[j], l / 2 - r1);
						} else {
							ans[j] = max(ans[j], (r2 - r1 + 1) / 2);
						}					
					}
				}
			}
		}
		
		for (int i = 0; i < Q; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
