#include <bits/stdc++.h>
using namespace std;

int main() {
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		int a[111];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort (a, a + n);
		
		int ans = n;

		int j = 0;
		for (int i = 0; i < n; i = j) {
			for (j = i + 1; j < n; j++) {
				if (a[i] != a[j]) break;
			}
			ans = min(ans, n - (j - i));
		}
		
		cout << ans << endl;
	}
	return 0;
}
