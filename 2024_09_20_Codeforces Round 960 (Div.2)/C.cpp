#include <bits/stdc++.h>
using namespace std;

vector<int> calcMad(vector<int> &vec) {
	vector<int> ret;
	
	set<int> S;
	
	int cur = 0;
	for (int i = 0; i < (int)vec.size(); i++) {
		if (S.count(vec[i])) {
			if (cur < vec[i])
				cur = vec[i];
		}
		S.insert(vec[i]);
		ret.push_back(cur);
	}
	
	return ret;
}

long long getSum(vector<int> &cur) {
	long long ret = 0;
	
	for (auto u : cur) ret += u;
	
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	freopen("in.txt", "r", stdin);
	
	int ntcs; cin >> ntcs;
	while (ntcs--) {
		int n; cin >> n;
		
		long long sum = 0;
		
		vector<int> A;
		
		for (int i = 0; i < n; i++) {
			int v; cin >> v;
			A.push_back(v);
		}
		
		sum += getSum(A);
		
		vector<int> B = calcMad(A);
		vector<int> C = calcMad(B);
		
		sum += getSum(B);
		sum += getSum(C);
		
		long long csum = getSum(C);
		
		for (int i = 0; i < (int)C.size(); i++) {
			csum -= C[n - i - 1];
			sum += csum;
		}
		
		cout << sum << "\n";
	}
	return 0;
}
