#include <bits/stdc++.h>
using namespace std;

inline int query(string s) {
	cout << "? " << s << "\n";
	cout.flush();
	
	int ret;
	cin >> ret;
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
//	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		
		// left expansion
		string s = "";
		string str0 = "0";
		string str1 = "1";
		
		while ((int)s.length() < n) {
			string s0 = s + str0;
			int exist = query(s0);
			
			if (exist) {
				s = s0;
				continue;
			}
			
			string s1 = s + str1;
			exist = query(s1);
			
			if (exist) {
				s = s1;
				continue;
			}
			
			break;
		}
		
		while ((int)s.length() < n) {
			string s0 = str0 + s;
			int exist = query(s0);
			
			if (exist) {
				s = s0;
				continue;
			} else {
				s = str1 + s;
				continue;
			}
		}
		
		cout << "! " << s << "\n";
		cout.flush();
	}
	return 0;
}
