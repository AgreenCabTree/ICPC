#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 100;

int last[N];
int a[N];
bool used[N];
int ans[N], anssp;

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	
	freopen("in.big.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	
	while (ntcs--) {
		int n; cin >> n;
		
		
		for (int i = 1; i <= n; i++) {
			last[i] = -1;
			used[i] = false;
		}

		for (int i = 0; i < n; i++) cin >> a[i];

		set<int> minPos;
		for (int i = 0; i < n; i++) last[a[i]] = i;
		
		for (int i = 1; i <= n; i++) {
			if (last[i] >= 0) {
				minPos.insert(last[i]);
			}
		}
		
		int last_pos = -1;
		int pop_pos = -1;
		
		set<pair<int, int>> S;
		
		anssp = 0;
		
		int turn = 0;
		
		while (minPos.size() > 0) {
			int pos = *minPos.begin();
			
			cout << "pos:" << pos << endl;
			
			assert (pos >= 0 && pos < n);
			
			for (int i = last_pos + 1; i <= pos; i++) {
				assert (i >= 0 && i < n);
				S.insert(make_pair(a[i], i));
			}
			
			pair<int, int> v;
			
			int sizeS = S.size();
			
			while(S.size() > 0) {
//				cout << "ok1\n";
				if (turn % 2 == 0) {
					v = *S.rbegin();
				} else {
					v = *S.begin();
				}
				S.erase(v);
				
//				cout << "ok4\n";
				
				if (turn % 2 == 0) {
					while (S.size() > 0) {
						if (S.rbegin()->first == v.first) {
							v = *S.rbegin();
							S.erase(v);
						} else {
							break;
						}
					}
				} else {
					while (S.size() > 0) {
						if (S.begin()->first == v.first) {
							S.erase(S.begin());							
						} else {
							break;
						}
					}
				}
				
//				cout << "ok2\n";
				
				assert (v.first >= 1 && v.first <= n);
				
				if (used[v.first]) continue;
				if (v.second <= pop_pos) continue;
				
//				cout << "ok3\n";
				break;
			}
			
			if (v.first < 1 || v.first > n) {
				cout << anssp << endl;
				cout << sizeS << endl;
				cout << v.first << "," << v.second << endl;
				cout << S.size() << endl;
				cout << last_pos << "," << pos << endl;
			}
			
			assert (v.first >= 1 && v.first <= n);
			assert (anssp >= 0 && anssp < n);
			
			cout << "ans:" << v.first << endl;
			
			used[v.first] = true;
			ans[anssp++] = v.first;
			minPos.erase(last[v.first]);
			
			++ turn;
			last_pos = pos;
			pop_pos = v.second;
		}

		cout << anssp << "\n";		
		for (int i = 0; i < anssp; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}
