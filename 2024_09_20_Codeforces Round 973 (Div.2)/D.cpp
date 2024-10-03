#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

long long a[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		int n; cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		long long minh = -1;
		long long maxh = -1;
		
		long long tots = 0;
		for (int i = 0; i < n; i++) {
			tots += a[i];
			long long curh = (tots) / (i + 1);
			if (minh == -1 || minh > curh) minh = curh;
		}
		
		tots = 0;
		for (int i = n - 1; i >= 0; i--) {
			tots += a[i];
			int cnt = n - i;
			long long curh = (tots + cnt - 1) / cnt;
			if (maxh == -1 || maxh < curh) maxh = curh;
		}
		
		cout << maxh - minh << "\n";
	}
	return 0;
}
