#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
const long double eps = 1e-15;

int a[N];
int b[N];

int main() {	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		long long ans = 0;		
		for (int i = 1; i < n; i++) {			
			long long u = a[i-1];
			long long v = a[i];
			
			if (u == 1) {
				b[i] = 0;
				continue;
			}
			
			if (v == 1) {
				if (a[i-1] > 1) {
					ans = -1;
					break;					
				}
				b[i] = 0;
				continue;
			}
			
			int d = 0;
			
			while (u <= v) {
				u = u * u;
				++ d;
			}
			
			while (u > v) {
				v = v * v;
				-- d;
			}
			
			int step = max(0, b[i-1] - d);
			ans += step;
			b[i] = step;
		}
		
		cout << ans << "\n";
	}	
	return 0;
}
