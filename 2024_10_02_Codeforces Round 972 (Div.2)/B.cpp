#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

char str[N];

inline int get_pos(char ch) {
	char pp[6] = "narek";	
	for (int i = 0; i < 5; i++) if (pp[i] == ch)
		return i;
	return -1;
}

int main() {
	freopen("in.txt", "r", stdin);
	

	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, m; cin >> n >> m;
		
		int cur[5] = {0};
		int cur_vis[5] = {0};
		
		cur_vis[0] = 1;

		for (int i = 1; i <= n; i++) {
			int nxt[5];
			int nxt_vis[5];
			
			for (int j = 0; j < 5; j++) {
				nxt[j] = cur[j];
				nxt_vis[j] = cur_vis[j];
			}
			
			cin >> str;
			
			for (int j = 0; j < 5; j++) if (cur_vis[j]) {
				int nj = j;
				int scr = cur[j];
				
				for (int k = 0; k < m; k++) {
					char ch = str[k];
					
					int pos = get_pos(ch);
					if (pos == -1) continue;
					
					-- scr;
					if (nj == pos) {
						++ nj;
						if (nj == 5) {
							scr += 10;
							nj = 0;
						}
					}
				}
				
				if (nxt_vis[nj] == 0 || nxt[nj] < scr) {
					nxt[nj] = scr;
					nxt_vis[nj] = 1;
				}
			}
			
			for (int j = 0; j < 5; j++) {
				cur[j] = nxt[j];
				cur_vis[j] = nxt_vis[j];
			}
		}
		
		int ans = 0;
		
		for (int i = 0; i < 5; i++)
			ans = max(ans, cur[i]);
			
		cout << ans << "\n";
	}
	return 0;
}
