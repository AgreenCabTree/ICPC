#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

string to_string(string s) { return s; }
template <typename T> string to_string(T v) {
  bool first = true;
  string res = "[";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "]";
  return res;
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << to_string(H);
  dbg_out(T...);
}

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template<class T> inline void chkmin(T& x, T y) { if (y < x) x = y; }
template<class T> inline void chkmax(T& x, T y) { if (y > x) x = y; }
using i64 = long long;

const i64 INF = 1e18;
const int oo = 1e9;
const int MOD = 1e9 + 7;
const int MX = 200005;


namespace Mod_Jiangly {
	template<class T>
	constexpr T power(T a, i64 b) {
		T res {1};
		for (; b; b /= 2, a *= a) {
			if (b % 2) {
				res *= a;
			}
		}
		return res;
	}
	
	constexpr i64 mul(i64 a, i64 b, i64 p) {
		i64 res = a * b - i64(1.L * a * b / p) * p;
		res %= p;
		if (res < 0) {
			res += p;
		}
		return res;
	}
	
	template<i64 P>
	struct MInt {
		i64 x;
		constexpr MInt() : x {0} {}
		constexpr MInt(i64 x) : x {norm(x % getMod())} {}
		
		static i64 Mod;
		constexpr static i64 getMod() {
			if (P > 0) {
				return P;
			} else {
				return Mod;
			}
		}
		constexpr static void setMod(i64 Mod_) {
			Mod = Mod_;
		}
		constexpr i64 norm(i64 x) const {
			if (x < 0) {
				x += getMod();
			}
			if (x >= getMod()) {
				x -= getMod();
			}
			return x;
		}
		constexpr i64 val() const {
			return x;
		}
		constexpr MInt operator-() const {
			MInt res;
			res.x = norm(getMod() - x);
			return res;
		}
		constexpr MInt inv() const {
			return power(*this, getMod() - 2);
		}
		constexpr MInt &operator*=(MInt rhs) & {
			if (getMod() < (1ULL << 31)) {
				x = x * rhs.x % int(getMod());
			} else {
				x = mul(x, rhs.x, getMod());
			}
			return *this;
		}
		constexpr MInt &operator+=(MInt rhs) & {
			x = norm(x + rhs.x);
			return *this;
		}
		constexpr MInt &operator-=(MInt rhs) & {
			x = norm(x - rhs.x);
			return *this;
		}
		constexpr MInt &operator/=(MInt rhs) & {
			return *this *= rhs.inv();
		}
		friend constexpr MInt operator*(MInt lhs, MInt rhs) {
			MInt res = lhs;
			res *= rhs;
			return res;
		}
		friend constexpr MInt operator+(MInt lhs, MInt rhs) {
			MInt res = lhs;
			res += rhs;
			return res;
		}
		friend constexpr MInt operator-(MInt lhs, MInt rhs) {
			MInt res = lhs;
			res -= rhs;
			return res;
		}
		friend constexpr MInt operator/(MInt lhs, MInt rhs) {
			MInt res = lhs;
			res /= rhs;
			return res;
		}
		friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
			i64 v;
			is >> v;
			a = MInt(v);
			return is;
		}
		friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
			return os << a.val();
		}
		friend constexpr bool operator==(MInt lhs, MInt rhs) {
			return lhs.val() == rhs.val();
		}
		friend constexpr bool operator!=(MInt lhs, MInt rhs) {
			return lhs.val() != rhs.val();
		}
		friend constexpr bool operator<(MInt lhs, MInt rhs) {
			return lhs.val() < rhs.val();
		}
	};
	
	template<>
	i64 MInt<0>::Mod = 998244353;
	
	constexpr int P = 1000000007;
	using Z = MInt<P>;
	
	struct Comb {
		int n;
		std::vector<Z> _fac;
		std::vector<Z> _invfac;
		std::vector<Z> _inv;
	
		Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
		Comb(int n) : Comb() {
			init(n);
		}
	
		void init(int m) {
			m = std::min<i64>(m, Z::getMod() - 1);
			if (m <= n) return;
			_fac.resize(m + 1);
			_invfac.resize(m + 1);
			_inv.resize(m + 1);
	
			for (int i = n + 1; i <= m; i++) {
				_fac[i] = _fac[i - 1] * i;
			}
			_invfac[m] = _fac[m].inv();
			for (int i = m; i > n; i--) {
				_invfac[i - 1] = _invfac[i] * i;
				_inv[i] = _invfac[i] * _fac[i - 1];
			}
			n = m;
		}
	
		Z fac(int m) {
			if (m > n) init(2 * m);
			return _fac[m];
		}
		Z invfac(int m) {
			if (m > n) init(2 * m);
			return _invfac[m];
		}
		Z inv(int m) {
			if (m > n) init(2 * m);
			return _inv[m];
		}
		Z binom(int n, int m) {
			if (n < m || m < 0) return 0;
			return fac(n) * invfac(m) * invfac(n - m);
		}
		Z H(int n, int m) {
			return binom(n + m - 1, m);
		}
	} comb;
}

using namespace Mod_Jiangly;

const int N = 200005;
const int MK = 150;

namespace SEG1 {
	Z v[N * MK];
	int l[N * MK], r[N * MK];
	int rt[N * 4];
	int st, en, sz, rtn;
	
	inline void up (int u) {
		v[u] = v[l[u]] + v[r[u]];
	}
	
	void build(int &u, int s, int e) {
        u = ++ sz;
		if (s == e) {
			v[u] = 0;
			return;
		}
		int md = (s + e) / 2;
		build(l[u], s, md);
		build(r[u], md + 1, e);
		up(u);
	}
	
	inline int update(int u, int st, int en, int s, int e, Z x) {
		int nu = ++ sz;
		l[nu] = l[u], r[nu] = r[u], v[nu] = v[u];
		if (en < s || st > e) return nu;
		if (s <= st && en <= e) {
            v[nu] += x;
			return nu;
		}
		int md = (st + en) / 2;
		if (md < en) l[nu] = update(l[nu], st, md, s, e, x);
		if (md >= st) r[nu] = update(r[nu], md + 1, en, s, e, x);
		up(nu);
		return nu;
	}
	
	inline Z get(int u, int st, int en, int s, int e) {
		if (en < s || st > e) return 0;
		if (s <= st && en <= e) {
			return v[u];
		}
		int md = (st + en) / 2;
		Z rlt = 0;
		if (s <= md) rlt += get(l[u], st, md, s, e);
		if (e > md) rlt += get(r[u], md + 1, en, s, e);
		return rlt;
	}
	
	inline int update(int R, int s, int e, Z x) {
		rt[rtn ++] = update(rt[R], st, en, s, e, x);
		return rtn - 1;
	}
	
	inline Z get(int R, int s, int e) {
		return get(rt[R], st, en, s, e);
	}
	int init(int s, int e) {
		st = s, en = e;
		sz = rtn = 0;
		build(rt[rtn ++], s, e);
		return rtn - 1;
	}
};

namespace SEG2 {
	Z v[N * MK];
	int l[N * MK], r[N * MK];
	int rt[N * 4];
	int st, en, sz, rtn;
	
	inline void up (int u) {
		v[u] = v[l[u]] + v[r[u]];
	}
	
	void build(int &u, int s, int e) {
        u = ++ sz;
		if (s == e) {
			v[u] = 0;
			return;
		}
		int md = (s + e) / 2;
		build(l[u], s, md);
		build(r[u], md + 1, e);
		up(u);
	}
	
	inline int update(int u, int st, int en, int s, int e, Z x) {
		int nu = ++ sz;
		l[nu] = l[u], r[nu] = r[u], v[nu] = v[u];
		if (en < s || st > e) return nu;
		if (s <= st && en <= e) {
            v[nu] += x;
			return nu;
		}
		int md = (st + en) / 2;
		if (md < en) l[nu] = update(l[nu], st, md, s, e, x);
		if (md >= st) r[nu] = update(r[nu], md + 1, en, s, e, x);
		up(nu);
		return nu;
	}
	
	inline Z get(int u, int st, int en, int s, int e) {
		if (en < s || st > e) return 0;
		if (s <= st && en <= e) {
			return v[u];
		}
		int md = (st + en) / 2;
		Z rlt = 0;
		if (s <= md) rlt += get(l[u], st, md, s, e);
		if (e > md) rlt += get(r[u], md + 1, en, s, e);
		return rlt;
	}
	
	inline int update(int R, int s, int e, Z x) {
		rt[rtn ++] = update(rt[R], st, en, s, e, x);
		return rtn - 1;
	}
	
	inline Z get(int R, int s, int e) {
		return get(rt[R], st, en, s, e);
	}
	int init(int s, int e) {
		st = s, en = e;
		sz = rtn = 0;
		build(rt[rtn ++], s, e);
		return rtn - 1;
	}
};

int siz[MX];
int a[MX];
vector<int> g[MX];
set<int> chd[MX];
int last[5][MX];
int n;
Z ans;

void dfs(int u, int p) {
	siz[u] = 1;
	int mx = 0, bigchild = -1;
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		siz[u] += siz[v];
		if (siz[v] >= mx) {
			mx = siz[v], bigchild = v;
		}
	}
	Z zig = 0, zag = 0;
	if (bigchild != -1) {
		swap(chd[u], chd[bigchild]);
		last[0][u] = last[0][bigchild];
		last[1][u] = last[1][bigchild];
	}
	
	for (auto v: g[u]) {
		if (v == p) continue;
		ans += zig * SEG2::get(last[1][v], 0, a[u] - 1);
		ans += zag * SEG1::get(last[0][v], a[u] + 1, n);
		zig += SEG2::get(last[1][v], 0, a[u] - 1);
		zag += SEG1::get(last[0][v], a[u] + 1, n);
	}
	ans += zig + zag;
	

	zig += 1, zag += 1;
	for (auto v: g[u]) {
		if (v == p || bigchild == v) continue;
		for (auto it = chd[v].begin(); it != chd[v].end(); it ++) {
			int k = (*it);
			ans += SEG1::get(last[0][v], k, k) * SEG2::get(last[1][u], 0, k - 1);
			ans += SEG2::get(last[1][v], k, k) * SEG1::get(last[0][u], k + 1, n);
			chd[u].insert((*it));
		}
		for (auto it = chd[v].begin(); it != chd[v].end(); it ++) {
			last[0][u] = SEG1::update(last[0][u], (*it), (*it), SEG1::get(last[0][v], (*it), (*it)));
			last[1][u] = SEG2::update(last[1][u], (*it), (*it), SEG2::get(last[1][v], (*it), (*it)));
		}
	}
	last[0][u] = SEG1::update(last[0][u], a[u], a[u], zig);
	last[1][u] = SEG2::update(last[1][u], a[u], a[u], zag);
	chd[u].insert(a[u]);
	if (u == 1) {
		for (auto it = chd[u].begin(); it != chd[u].end(); it ++) {
			int k = (*it);
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	SEG1::init(0, n);
	SEG2::init(0, n);
	ans = 0;
	for (int i = 0; i <= n; i ++) {
		chd[i].clear();
		siz[i] = 0;
		g[i].clear();
		last[0][i] = last[1][i] = 0;
	}
	for (int i = 1; i < n; i ++) {
		int p;
		cin >> p;
		p --;
		g[p].push_back(i);
		g[i].push_back(p);
	}
	dfs(0, -1);
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int Tc = 1;
	cin >> Tc;
	while (Tc --) {
		solve();
	}
	return 0;
}
