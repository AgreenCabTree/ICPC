#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 100;

int a[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		if (n % 2 == 0) {
			cout << -1 << "\n";
			continue;
		}
		int st = N / 2 - 1;
		int en = N / 2;
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				a[st--] = i;
			} else {
				a[en++] = i;
			}
		}
		for (int i = st + 1; i < en; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
