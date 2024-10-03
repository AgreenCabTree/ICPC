#include <bits/stdc++.h>
using namespace std;

const int N = 5555;
const int B = 1 << 20;

int cnt[B];
int a[N];

int main() {
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
			
		sort (a, a + n);
		
		memset (cnt, 0, sizeof cnt);
		
		long long sum = 0;
		
		int ni;		
		for (int i = 0; i < n; i = ni) {
			for (ni = i + 1; ni < n; ni++) if (a[i] != a[ni]) break;
			
			int nj;
			for (int j = ni; j < n; j = nj) {
				for (nj = j + 1; nj < n; nj++) if (a[j] != a[nj]) break;
				
				int x = a[i] ^ a[j];
			
				sum += cnt[x] * 1LL * (ni - i) * (nj - j) * 4;
				
				if (ni > 1 && nj > 1) {
					int cnt1 = (ni - i) * (ni - i - 1) / 2;
					int cnt2 = (nj - j) * (nj - j - 1) / 2;
					
					sum += 8LL * cnt1 * cnt2;
				}
				
				cnt[x] += (ni - i) * (nj - j) * 2;
			}
		}
		
		cout << sum << "\n";
	}
	return 0;
}
