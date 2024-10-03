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
		for (int i = 0; i < n; i++) cin >> a[i];
		
		int ans = 0;
		
		bool flow1 = false;
		bool flow2 = false;
		for (int i = 0; i < n; i++) {
			if (a[i] > 4) {
				++ ans;
				flow1 = flow2 = false;
			} else if (a[i] == 0) {
				flow1 = flow2 = false;
			} else {
				bool black[4] = { false };
				for (int j = 0; j < a[i]; j++) {
					black[j] = true;
				}
				if (flow1) {
					black[0] = black[1] = false;
				}
				if (flow2) {
					black[2] = black[3] = false;
				}
				
				int st = -1;
				int en = -1;
				for (int j = 0; j < a[i]; j++) if (black[j] == true) {
					if (st == -1 || st > j) st = j;
					if (en == -1 || en < j) en = j;
				}
				
				if (st == -1) {
					flow1 = flow2 = false;
					continue;
				}
				
				if (en - st + 1 > 2) {
					++ ans;
					flow1 = flow2 = false;
				} else {
					assert (st == 0 || st == 2);
					if (st == 0) {
						++ ans;
						flow1 = true;
						flow2 = false;
					} else {
						++ ans;
						flow1 = false;
						flow2 = true;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
