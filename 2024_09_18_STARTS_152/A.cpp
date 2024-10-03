#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 100;

char s[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		int n, m; cin >> n >> m;
		
		vector<int> cnt;
		vector<int> count;
		
		count.resize(n);
		cnt.resize(n);
		
		for (int i = 0; i < m; i++) {
			cin >> s;
			for (int j = 0; j < n; j++) {
				if (s[j] == '1') {
					++ count[j];
					++ cnt[j];
				} else if (s[j] == '0') {
					++ count[j];
				}
			}
		}
		
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			int a = cnt[i];
			int b = count[i] - a;
			int c = m - count[i];
			
			int minv = min(a, b);
			int maxv = max(a, b);
			
			if (maxv - minv > c) {
				minv += c;
				sum += 1LL * maxv * minv;
			} else {
				c -= (maxv - minv);
				minv = maxv;
				minv += c / 2;
				maxv += (c + 1) / 2;
				sum += 1LL * maxv * minv;
			}
		}
		
		cout << sum << "\n";
	}
	return 0;
}
