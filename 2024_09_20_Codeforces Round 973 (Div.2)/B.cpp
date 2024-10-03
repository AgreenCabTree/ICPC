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
		for (int i = 0; i < n; i++) cin >> a[i];
		
		if (n == 2) {
			cout << a[1] - a[0] << "\n";
		} else {
			long long s = a[n - 1];
			s -= a[n - 2];
			for (int i = 0; i < n - 2; i++)
				s += a[i];
			cout << s << "\n";
		}
	}
	
	return 0;
}
