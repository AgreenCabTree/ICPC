#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

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
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		int cnt[2] = {0};
		for (int i = 1; i <= n; i++)
			++ cnt[a[i] % 2];
		
		if (cnt[0] && cnt[1]) {
			cout << -1 << endl;
		} else {
			vector<int> ans;
			
			while (true) {
				int minv, maxv;
				
				minv = maxv = -1;
				
				for (int i = 1; i <= n; i++) {
					if (minv == -1 || minv > a[i]) minv = a[i];
					if (maxv == -1 || maxv < a[i]) maxv = a[i];
				}
				
				if (minv == 0 && maxv == 0) {
					break;
				}
				
				int x = (maxv + minv) / 2;
				ans.push_back(x);
				
				for (int i = 1; i <= n; i++) {
					a[i] = abs(a[i] - x);
				}
			}
			
			cout << ans.size() << endl;
			for (auto u : ans) cout << u << " ";
			cout << endl;
		}
	}
	return 0;
}
