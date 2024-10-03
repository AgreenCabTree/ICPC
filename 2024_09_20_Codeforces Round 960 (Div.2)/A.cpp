#include <bits/stdc++.h>
using namespace std;

const int N = 55;

bool dp[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		
		vector<int> vec;
		
		for (int i = 0; i < n; i++) {
			int v; cin >> v;
			vec.push_back(v);
		}		
		
		sort (vec.begin(), vec.end());
		
		dp[n] = false;
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = false;
			for (int j = i; j < n; j++) {
				if ((j == i || j == 0 || vec[j-1] != vec[j]) && dp[j+1] == false) {
					dp[i] = true;
				}
			}
		}
		
		if (dp[0])
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
