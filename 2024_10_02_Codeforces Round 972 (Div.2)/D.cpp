#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int a[N], b[N];
int fa[20][N], fb[20][N];
int n; 

void buildA() {
	for (int i = 1; i <= n; i++) {
		fa[0][i] = a[i];
	}	
	
	for (int b = 1; (1 << b) <= n; b++) {
		for (int i = 1; (1 << b) + i - 1 <= n; i++) {
			fa[b][i] = __gcd(fa[b-1][i], fa[b-1][i+(1<<(b-1))]);
		}
	}
}

void buildB() {
	for (int i = 1; i <= n; i++) {
		fb[0][i] = b[i];
	}	
	
	for (int b = 1; (1 << b) <= n; b++) {
		for (int i = 1; (1 << b) + i - 1 <= n; i++) {
			fb[b][i] = __gcd(fb[b-1][i], fb[b-1][i+(1<<(b-1))]);
		}
	}
}

int tailA[N];
int tailB[N];

inline int queryA(int l, int r) {
	int len = r - l + 1;
	if (len <= 0) return 0;
	
	if (r == n) {
		return tailA[l];
	}
	
	int b = __lg(len);
	
	return __gcd(fa[b][l], fa[b][r-(1<<b)+1]);
}



inline int queryB(int l, int r) {
	int len = r - l + 1;
	if (len <= 0) return 0;
	
	if (r == n) {
		return tailB[l];
	}
	
	int b = __lg(len);
	
	return __gcd(fb[b][l], fb[b][r-(1<<b)+1]);
}

int posList[N];
int sp;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		cin >> n;
		
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		
		
		for (int i = n; i >= 1; i--) {
			tailA[i] = a[i];
			tailB[i] = b[i];
			if (i < n) {
				tailA[i] = __gcd(tailA[i], tailA[i+1]);
				tailB[i] = __gcd(tailB[i], tailB[i+1]);
			}
		}
		
		buildA();
		buildB();
		
		long long ans = 0;
		int ansv = 0;
		
		int gcdA = 0;
		int gcdB = 0;
		
		for (int l = 1; l <= n; l++) {
			if (l > 1) {
				gcdA = __gcd(gcdA, a[l - 1]);
				gcdB = __gcd(gcdB, b[l - 1]);
				
				if (gcdA + gcdB < ansv) {
					break;
				}
			}
			
			sp = 0;
			
			{
				int ga = a[l];
				int pos = l;
							
				while (pos <= n) {
					int st = pos + 1;
					int en = n;
					int ans = -1;
					
					while (st <= en) {
						int mid = (st + en) / 2;
						if (queryA(l, mid) != ga) {
							en = mid - 1;
							ans = mid;
						} else {
							st = mid + 1;
						}
					}
					
					if (ans == -1) {
						// till the end
						posList[sp++] = n;
						break;
					} else {
						posList[sp++] = ans - 1;
						pos = ans;
						ga = queryA(l, pos);
					}
				}
			}
			
			{
				int ga = queryA(l + 1, n);
				int pos = l;
							
				while (pos <= n) {
					int st = pos + 1;
					int en = n;
					int ans = -1;
					
					while (st <= en) {
						int mid = (st + en) / 2;
						if (queryA(mid + 1, n) != ga) {
							en = mid - 1;
							ans = mid;
						} else {
							st = mid + 1;
						}
					}
					
					if (ans == -1) {
						// till the end
						posList[sp++] = n;
						break;
					} else {
						posList[sp++] = ans - 1;
						pos = ans;
						ga = queryA(pos + 1, n);
					}
				}
			}
			
			{
				int gb = b[l];
				int pos = l;
							
				while (pos <= n) {
					int st = pos + 1;
					int en = n;
					int ans = -1;
					
					while (st <= en) {
						int mid = (st + en) / 2;
						if (queryB(l, mid) != gb) {
							en = mid - 1;
							ans = mid;
						} else {
							st = mid + 1;
						}
					}
					
					if (ans == -1) {
						// till the end
						posList[sp++] = n;
						break;
					} else {
						posList[sp++] = ans - 1;
						pos = ans;
						gb = queryB(l, pos);
					}
				}
			}
			
			{
				int gb = queryB(l + 1, n);
				int pos = l;
							
				while (pos <= n) {
					int st = pos + 1;
					int en = n;
					int ans = -1;
					
					while (st <= en) {
						int mid = (st + en) / 2;
						if (queryB(mid + 1, n) != gb) {
							en = mid - 1;
							ans = mid;
						} else {
							st = mid + 1;
						}
					}
					
					if (ans == -1) {
						// till the end
						posList[sp++] = n;
						break;
					} else {
						posList[sp++] = ans - 1;
						pos = ans;
						gb = queryB(pos + 1, n);
					}
				}
			}

			sort (posList, posList + sp);
			
			sp = unique(posList, posList + sp) - posList;
			
			assert (sp <= 200);
			
			int before_r = l - 1;
			
			for (int tt = 0; tt < sp; tt++) {
				int r = posList[tt];
				
				int ga = 0;
				ga = __gcd(ga, gcdA);
				ga = __gcd(ga, queryB(l, r));
				ga = __gcd(ga, queryA(r + 1, n));
				
				int gb = 0;
				gb = __gcd(gb, gcdB);
				gb = __gcd(gb, queryA(l, r));
				gb = __gcd(gb, queryB(r + 1, n));
				
				if (ansv < ga + gb) {
					ansv = ga + gb;
					ans = (r - before_r);
				} else if (ansv == ga + gb) {
					ansv = ga + gb;
					ans += (r - before_r);
				}
				
				before_r = r;
			}
		}
		
		cout << ansv << " " << ans << "\n";
	}
	return 0;
}
