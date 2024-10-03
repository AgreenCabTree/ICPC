#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

char str[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		cin >> str;
		
		int cnt[26] = {0};
		
		for (int i = 0; i < n; i++) {
			++ cnt[str[i] - 'a'];
		}
		
		int id = 0;
		int tot = 0;
		
		while (tot < n) {
			while (cnt[id] == 0) id = (id + 1) % 26;
			-- cnt[id];
			str[tot++] = id + 'a';
			id = (id + 1) % 26;
		}
		
		cout << str << "\n";
	}
	return 0;
}
