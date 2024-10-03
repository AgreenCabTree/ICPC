#include <bits/stdc++.h>
using namespace std;

const int N = 111;

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
		
		int v = 0;
		for (int i = 0; i < n; i += 2) {
			v = max(v, a[i]);
		}
		cout << v << "\n";
	}
	return 0;
}
