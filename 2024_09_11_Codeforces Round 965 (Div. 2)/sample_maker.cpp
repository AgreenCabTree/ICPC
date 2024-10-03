#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	freopen("in.big.txt", "w", stdout);
	
	cout << 1 << "\n";
	
	int n = 2e5, x = 1;
	cout << n << " " << x << "\n";
	
	const int mod = 1e9;
	for (int i = 1; i <= n; i++) {
		cout << rng() % mod + 1 << " ";
	}
	
	cout << endl;
	return 0;
}
