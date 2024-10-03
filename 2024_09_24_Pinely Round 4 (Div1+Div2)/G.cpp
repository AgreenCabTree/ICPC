#include <bits/stdc++.h>
using namespace std;

const int N = 1111;

char str[N];

struct node {
	char dir;
	int r, c;
	node (char dir = 'H', int r = 0, int c = 0)
		:dir(dir), r(r), c(c) {}
};

bool vis[N][N];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n, m, K; cin >> n >> m >> K;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				vis[i][j] = false;
			}
		}
		
		int Q; cin >> Q;
		
		vector<node> posList;
		
		for (int i = 1; i <= m; i++) posList.push_back(node('V', 1, i));
		for (int i = 1; i <= n; i++) posList.push_back(node('H', i, 1));
		
		cin >> str;
		
		for (int qi = 0; qi < Q; qi++) {
			char ch = str[qi];
			
			if (ch == 'V') {
				int possiblePos = -1;
				bool removed = false;
				for (int i = 1; i <= m; i++) {
					bool isPossible = true;
					bool canRemove = true;
					
					for (int t = 1; t <= K; t++) {
						if (vis[t][i]) {
							isPossible = false;
							break;
						}
					}
					
					for (int t = K + 1; t <= n; t++) {
						if (vis[t][i] == false) {
							canRemove = false;
							break;
						}
					}
					
					if (isPossible) {
						if (possiblePos == -1 || removed < canRemove) {
							removed = canRemove;
							possiblePos = i;
						}
					}
				}
				
				cout << 1 << " " << possiblePos << "\n";
				
				for (int t = 1; t <= K; t++) {
					vis[t][possiblePos] = true;
				}
			} else {
				int possiblePos = -1;
				bool removed = false;
				for (int i = 1; i <= n; i++) {
					bool isPossible = true;
					bool canRemove = true;
					
					for (int t = 1; t <= K; t++) {
						if (vis[i][t]) {
							isPossible = false;
							break;
						}
					}
					
					for (int t = K + 1; t <= m; t++) {
						if (vis[i][t] == false) {
							canRemove = false;
							break;
						}
					}
					
					if (isPossible) {
						if (possiblePos == -1 || removed < canRemove) {
							removed = canRemove;
							possiblePos = i;
						}
					}
				}
				
				cout << possiblePos << " " << 1 << "\n";
				

				for (int t = 1; t <= K; t++) {
					vis[possiblePos][t] = true;
				}
			}
			
			vector<int> rows;
			vector<int> cols;
			
			for (int i = 1; i <= n; i++) {
				bool filled = true;
				for (int j = 1; j <= m; j++) {
					if (vis[i][j] == false) {
						filled = false;
						break;
					}
				}
				
				if (filled) {
					rows.push_back(i);
				}
			}
			
			for (int i = 1; i <= m; i++) {
				bool filled = true;
				for (int j = 1; j <= n; j++) {
					if (vis[j][i] == false) {
						filled = false;
						break;
					}
				}
				
				if (filled) {
					cols.push_back(i);
				}
			}
			
			for (auto row: rows) {
				for (int i = 1; i <= m; i++) {
					vis[row][i] = false;
				}
			}
			
			for (auto col: cols) {
				for (int i = 1; i <= n; i++) {
					vis[i][col] = false;
				}
			}
			
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= m; j++) {
//					cout << !!vis[i][j];
//				}
//				cout << endl;
//			}
//			
//			cout << endl;
		}
	}
	return 0;
}
