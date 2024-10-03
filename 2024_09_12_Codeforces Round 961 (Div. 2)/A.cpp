#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, K; cin >> n >> K;
		
		vector<int> vec;
		for (int i = 1; i <= n; i++) vec.push_back(i);
		for (int i = n - 1; i >= 1; i--) vec.push_back(i);
		
		sort (vec.begin(), vec.end());
		reverse (vec.begin(), vec.end());
		
		int ans = 0;
		for (; K > 0; ans++) {
			K -= vec[ans];
		}
		
		cout << ans << "\n";
	}
	return 0;
}
