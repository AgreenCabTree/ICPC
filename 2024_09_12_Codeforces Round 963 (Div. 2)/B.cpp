#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
const long long V = 1e9 + 1;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		
		multiset<long long> S[2];
		for (int i = 0; i < n; i++) {
			int v; cin >> v;
			S[v % 2].insert(v);
		}
		
		if (S[0].size() == 0 || S[1].size() == 0) {
			cout << 0 << "\n";
		} else {
			int ans = 0;
			while (S[0].size() > 0) {
				long long a = *S[0].begin(); 
				long long b = *S[1].rbegin();
				
				if (a < b) {
					// good
				} else {
					// bad, b will be changed
					a = *S[0].rbegin();
				}
				
				S[0].erase(S[0].find(a));
				S[1].erase(S[1].find(b));
				
				S[max(a, b) % 2].insert(max(a, b));
				
				if (a + b > V) {
					S[1].insert(V);
				} else {
					S[1].insert(a + b);	
				}
				
				++ ans;
			}
			
			cout << ans << "\n";
		}
	}
	return 0;
}
