#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target ("sse,sse2,mmx")
#pragma GCC optimize ("-ffloat-store")

const int N = 2e5 + 100;

int a[N];
int g[20][N];

inline int get_max(int l, int r) {
	int n = r - l + 1;
	int b = __lg(n);
	return max(g[b][l], g[b][r-(1<<b)+1]);
}

long long sum[N];
int cnt[N];
long long vsum[N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.big.txt", "r", stdin);
	freopen("me.out", "w", stdout);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, x;
		
		cin >> n >> x;
		
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) g[0][i] = a[i];
		for (int b = 1; (1 << b) <= n; b++) {
			for (int i = 1; i + (1 << b) - 1 <= n; i++) {
				g[b][i] = max(g[b-1][i], g[b-1][i + (1 << (b - 1))]);
			}
		}
		
		for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		
		vector<int> idPos;
		for (int i = 2; i <= n; i++) 
			if (a[i] > sum[i-1]) 
				idPos.push_back(i);
		
		int last_f = -1;
		
		for (int i = 1; i <= n; i++) {
			int firstr = -1;
			
			if (i > 1 && a[i-1] <= a[i] && last_f >= i) {
				firstr = last_f;
			} else {
				int str = (last_f == -1 ? i : max(i, last_f));
				int enr = n;
				
				while (str <= enr) {
					int midr = (str + enr) / 2;
				
					int l = i;
					int r = i;
					long long v = a[i];
					
					while (true) {
						if (l == 1) {
							break;
						}
						
						int st, en, ansl, ansr;
						
						ansl = ansr = -1;
						
						st = 1;
						en = l - 1;
						while (st <= en) {
							int mid = (st + en) / 2;
							if (get_max(mid, l - 1) <= v) {
								ansl = mid;
								en = mid - 1;
							} else {
								st = mid + 1;
							}
						}
						
						if (ansl == -1) {
							st = r + 1;
							en = midr;
							while (st <= en) {
								int mid = (st + en) / 2;
								if (get_max(r + 1, mid) <= v) {
									ansr = mid;
									st = mid + 1;
								} else {
									en = mid - 1;
								}
							}
						}
						
						if (ansl == -1 && ansr == -1) {
							break;
						}
						
						if (ansl != -1) {
							l = ansl;
							v = sum[r] - sum[l - 1];
						}
						
						if (ansr != -1) {
							r = ansr;
							v = sum[r] - sum[l - 1];
						}
					}
					
					if (l == 1) {
						firstr = midr;
						enr = midr - 1;
					} else {
						str = midr + 1;
					}
				}
			}
			
			last_f = firstr;
			
//			cout << "#" << firstr << endl;
			
			if (firstr == -1) {
				continue;
			}
			
			int pos = lower_bound(idPos.begin(), idPos.end(), firstr + 1) - idPos.begin();
			
			if (pos == (int)idPos.size()) {
				++ cnt[firstr];
				-- cnt[n+1];
			} else {
				++ cnt[firstr];
				-- cnt[idPos[pos]];
			}
		}
		
		int s = 0;
		for (int i = 1; i <= n; i++) {
			s += cnt[i];
			cout << s << " ";
		}
		
		cout << "\n";
	}
	return 0;
}
