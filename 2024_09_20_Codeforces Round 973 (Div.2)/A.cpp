#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, x, y; cin >> n >> x >> y;
		
		int t1 = (n + x - 1) / x;
		int t2 = (n + y - 1) / y;
		
		cout << max(t1, t2) << "\n";
	}
	return 0;
}
