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
		int n, K; cin >> n >> K;
		
		bool issame = true;
		
		bool allsame = true;
		bool allKmultiple = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] != K) issame = false;
			if (i > 1 && a[i-1] != a[i]) allsame = false;
			if (a[i] % K != 0) allKmultiple = false;
		}
		
		if (issame) {
			cout << 0 << "\n";
			continue;
		}
		
		if (allsame == true) {
			cout << 1 << "\n";
			continue;
		}
		
		if (allKmultiple == true) {
			cout << 1 << "\n";
			continue;
		}
		
		int group_cnt = 0;
		int j;
		for (int i = 1; i <= n; i = j) {
			for (j = i + 1; j <= n; j++) if (a[i] != a[j]) break;
			
			if (a[i] == K) continue;
			++ group_cnt;
		}
		
		if (group_cnt <= 1) {
			cout << 1 << "\n";
			continue;
		}
		
		cout << 2 << "\n";
	}
	return 0;
}
