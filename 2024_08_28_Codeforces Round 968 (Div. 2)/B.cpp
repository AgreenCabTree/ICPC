#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int a[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		
		sort (a, a + n);
		cout << a[n / 2] << "\n";
	}
	return 0;
}
