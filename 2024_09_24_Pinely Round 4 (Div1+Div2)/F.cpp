#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int a[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; ntcs = 1;
	while (ntcs--) {
		int n; cin >> n;
		int q; cin >> q;
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		while (q--) {
			int l, r; cin >> l >> r;
			int len = r - l + 1;
			if (len >= 100) {
				cout << "Yes\n";
			} else {
				vector<int> vec;
				for (int i = l; i <= r; i++) {
					vec.push_back(a[i]);
				}
				
				sort (vec.begin(), vec.end());
				
				int vn = (int)vec.size();
				
				int mini, maxi;
				
				mini = maxi = -1;
				
				for (int i = 2; i < vn; i++) {
					if (vec[i-2] + vec[i-1] > vec[i]) {
						mini = i;
						break;
					}
				}
				
				for (int i = vn - 1; i >= 2; i--) {
					if (vec[i-2] + vec[i-1] > vec[i]) {
						maxi = i;
						break;
					}
				}
				
				bool find = false;
				
				if (mini != -1 && mini + 3 <= maxi) {
					find = true;	
				}
				
				if (!find) {
					for (int i = 5; i < (int)vec.size(); i++) {
						int b[6];
						for (int j = 0; j < 6; j++) b[j] = vec[i-5+j];
					
						for (int k1 = 0; k1 < 6; k1++) {
							for (int k2 = k1 + 1; k2 < 6; k2++) {
								for (int k3 = k2 + 1; k3 < 6; k3++) if (b[k1] + b[k2] > b[k3]) {
									int c[6], csp;
									
									csp = 0;
									for (int t = 0; t < 6; t++) if (t != k1 && t != k2 && t != k3) {
										c[csp++] = b[t];
									}
									
									if (c[0] + c[1] > c[2]) {
										find = true;
										break;
									}
								}
								if (find) break;
							}
							if (find) break;
						}
						if (find) break;
					}
				}
				
				if (find)
					cout << "Yes\n";
				else
					cout << "No\n";
			}
		}
	}
	return 0;
}
