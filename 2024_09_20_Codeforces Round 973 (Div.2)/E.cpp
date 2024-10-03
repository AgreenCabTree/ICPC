#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int a[N];
bool vis[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		
		for (int i = 0; i < n; i++) 
			vis[i] = false;
		
		sort (a, a + n);
		int gg = 0;
		
		for (int i = 0; i < n; i++)
			gg = __gcd(a[i], gg);
		
		long long sum = 0;
		
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (cur == gg) {
				sum += cur;
				continue;
			}
			int ming = -1;
			int minj = -1;
			for (int j = 0; j < n; j++) if (!vis[j]) {
				int g = __gcd(cur, a[j]);
				if (ming == -1 || ming > g) {
					ming = g;
					minj = j;
				}
			}
			
			assert (minj != -1);
			
			vis[minj] = true;
			sum += ming;
			cur = ming;
		}
		
		cout << sum << "\n";
	}
	return 0;
}
