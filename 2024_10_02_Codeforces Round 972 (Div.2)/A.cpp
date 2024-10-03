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
		
		int cnt[5] = {0};
		
		for (int i = 0; i < 5; i++) cnt[i] = n / 5;
		for (int i = 0; i < n % 5; i++) ++ cnt[i];
		
		char str[6] = "aeiou";
		
		for (int i = 0; i < 5; i++) for (int j = 0; j < cnt[i]; j++)
			cout << str[i];
		cout << "\n";
	}
	return 0;
}
