#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int b[N], a[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		int n; cin >> n;
		for (int i = 1; i < n; i++) cin >> b[i];
		for (int i = 2; i < n; i++) {
			a[i] = b[i-1] | b[i];
		}
		a[1] = b[1];
		a[n] = b[n - 1];
		
		bool find = true;
		for (int i = 1; i < n; i++) {
			if (b[i] != (a[i] & a[i+1])) {
				find = false;
				break;
			}
		}
		
		if (find == false) {
			cout << -1 << "\n";
			continue;
		}
		
		for (int i = 1; i <= n; i++) {
			if (i > 1) cout << " ";
			cout << a[i];
		}
		cout << "\n";
	}
	return 0;
}
