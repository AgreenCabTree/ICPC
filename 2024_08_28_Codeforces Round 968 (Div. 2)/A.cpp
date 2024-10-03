#include <bits/stdc++.h>
using namespace std;

const int N = 111;

char str[N];

int main() {
//	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		cin >> str;
		
		if (str[0] != str[n-1]) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
