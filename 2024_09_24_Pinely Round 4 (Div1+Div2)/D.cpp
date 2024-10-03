#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		
		if (n == 3) {
			cout << "2\n";
			cout << "1 2 2\n";
			continue;
		}
		
		if (n == 4) {
			cout << "3\n";
			cout << "1 2 2 3\n";
			continue;
		}
		
		if (n == 5) {
			cout << "3\n";
			cout << "1 2 2 3 3\n";
			continue;
		}
		
		vector<int> colors;
		
		int mxc = 0;
		
		colors.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			int c = i % 4;
			if (c == 0) c = 4;
			mxc = max(c, mxc);
			colors[i] = c;
		}
		
		
		cout << mxc << "\n";
		
		for (int i = 1; i <= n; i++) {
			cout << colors[i] << " ";
		}		
		cout << endl;
	}
	return 0;
}
