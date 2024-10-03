#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int a[N], b[N];

long long m;

long long solve(long long v, long long cnt1, long long cnt2) {
	long long ans1 = min(1LL * cnt1, m / v) * v;
	ans1 = min(1LL * cnt2, (m - ans1) / (v + 1)) * (v + 1) + ans1;
	
	long long ans2 = min(1LL * cnt2, m / (v + 1)) * (v + 1);
	ans2 = min(1LL * cnt1, (m - ans2) / v) * v + ans2;
	
	long long r1 = -m;
	long long r2 = +m;
	
	bool find = true;

	do {
		long long st1 = 0;
		long long en1 = 0;
		
		st1 = m / (v + 1);
		if (m % (v + 1))
			++ st1;
		if (r1 + st1 * (v + 1) > cnt1) {
			find = false;
			break;
		}
		
		long long a = r1 + st1 * (v + 1);
		assert (a >= 0 && a <= cnt1);
		
		en1 = st1 + (cnt1 - a) / (v + 1);
		
		
		long long st2 = 0;
		long long en2 = 0;
		
		en2 = r2 / v;
		st2 = (r2 - cnt2) / v;
		
		if (v * st2 < r2 - cnt2) ++ st2;
		if (max(st1, st2) > min(en1, en2)) {
			find = false;
		}
	} while (false);
	
	if (find)
		return m;
	
	return max(ans1, ans2);
}

int main() {	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		
		sort (a, a + n);
		
		vector<pair<int, int>> vec;
		
		int j;
		for (int i = 0; i < n; i = j) {
			for (j = i + 1; j < n; j++) {
				if (a[i] != a[j]) break;
			}
			vec.emplace_back(a[i], j - i);
		}
		
		sort (vec.begin(), vec.end(), [&](const pair<int, int> &u, const pair<int, int> &v) {
			return u.first < v.first;	
		});
		
		long long ans = 0;
		
		for (int i = 0; i < (int)vec.size(); i++) {
			int v1 = vec[i].first;
			int cnt1 = vec[i].second;
			
			int cnt2 = 0;
			
			if (i + 1 < (int)vec.size() && vec[i].first + 1 == vec[i+1].first) {
				cnt2 = vec[i+1].second;
			}
			
			ans = max(ans, solve(v1, cnt1, cnt2));
		}
		
		cout << ans << "\n";
	}
	return 0;
}
