#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
const int mod = 1e9 + 7;

char str[N];

int f[N], g[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
//	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		cin >> str;
		
		f[1] = 0;
		g[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			if (str[i-2] == str[i-1]) {
				f[i] = ((1LL * f[i-1] + 1LL * g[i-1] - 1LL * (i - 1)) % mod + mod) % mod;
				g[i] = g[i-1] + 1;
			} else {
				f[i] = (f[i-1] + 1LL * (i - 2) * (i - 1) / 2 % mod) % mod;
				g[i] = (g[i-1] + i) % mod;
			}
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = (ans + f[i]) % mod;
		}
		
		cout << ans << "\n";
	}
	return 0;
}
