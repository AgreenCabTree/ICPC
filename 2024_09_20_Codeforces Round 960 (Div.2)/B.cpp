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
		
		for (int i = 1; i < y; i++) {
			cout << (y - 1 - i) % 2 * 2 - 1 << " ";
		}
		
		for (int i = y; i <= x; i++) cout << 1 << " ";
		
		for (int i = x + 1; i <= n; i++) 
			cout << (i - x - 1) % 2 * 2 - 1 << " ";
		cout << endl;
	}
	return 0;
}
