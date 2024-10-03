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
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		int pos = -1;
		for (int i = n; i >= 1; i--) if (a[i] != i) {
			pos = i; break;
		}
		
		cout << pos + 1 << "\n";
	}
	return 0;
}
