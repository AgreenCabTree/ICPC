#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 3e5+11;
int n;
int a[N];
vector <int> pos[N];
struct sgt {
    int mi[N<<2];
    void build(int k, int l,int r) {
        mi[k] = 1e9;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(k<<1, l, mid);
        build(k<<1|1, mid+1, r);
    }
    void modify(int k, int l, int r, int w, int s) {
        if (l == r) {
            mi[k] = s;
            return;
        }
        int mid = (l + r) >> 1;
        if (w <= mid) modify(k<<1, l, mid, w, s);
        else modify(k<<1|1, mid+1, r, w, s);
        mi[k] = min(mi[k<<1], mi[k<<1|1]);
    }
    int query(int k, int l, int r, int L, int R) {
        if (L > R) return 1e9;
        if (l >= L && r <= R) return mi[k];
        int ret = 1e9, mid = (l + r) >> 1;
        if (L <= mid) ret = min(ret, query(k<<1, l, mid, L, R));
        if (R > mid) ret = min(ret, query(k<<1|1, mid+1, r, L, R));
        return ret;
    }
} t, t1;
int cur[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) pos[i].clear();
    for (int i = 1; i <= n; i++) 
        cin >> a[i], pos[a[i]].pb(i), cur[a[i]] = 0;
    t.build(1, 1, n); t1.build(1, 1, n);
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[i].size()) {
            ++ num;
            t1.modify(1, 1, n, i, pos[i].back());
            t.modify(1, 1, n, i, pos[i][0]);
        }
    }
    cout << num << endl;
    bool cnt = 1;
    for (int i = 1; i <= n; i++) {
        int lpos = t1.query(1, 1, n, 1, n);
        if (t1.query(1, 1, n, a[i], a[i]) == 1e9) continue;
        if (cnt == 1) {
            if (t.query(1, 1, n, a[i]+1, n) <= lpos) {
                cur[a[i]]++;
                if (cur[a[i]] < pos[a[i]].size()) 
                    t.modify(1, 1, n, a[i], pos[a[i]][cur[a[i]]]);
                else t.modify(1, 1, n, a[i], 1e9);
            }
            else {
                cout << a[i] << ' '; 
                t1.modify(1, 1, n, a[i], 1e9);
                t.modify(1, 1, n, a[i], 1e9);
                cnt ^= 1;
            }
        }
        else {
            if (t.query(1, 1, n, 1, a[i]-1) <= lpos) {
                cur[a[i]]++;
                if (cur[a[i]] < pos[a[i]].size()) 
                    t.modify(1, 1, n, a[i], pos[a[i]][cur[a[i]]]);
                else t.modify(1, 1, n, a[i], 1e9);
            }
            else {
                cout << a[i] << ' '; 
                t1.modify(1, 1, n, a[i], 1e9);
                t.modify(1, 1, n, a[i], 1e9);
                cnt ^= 1;
            }
        }
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}