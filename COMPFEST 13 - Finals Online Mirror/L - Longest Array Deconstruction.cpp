#include "bits/stdc++.h"

using db = long double;
using ll = long long;
using namespace std;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;

#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3fll
#define MOD 998244353

#define eb emplace_back
#define pb pop_back
#define is insert
#define fn front
#define bk back
#define bg begin
#define ed end
#define fi first
#define se second
#define pq priority_queue
#define bcnt __builtin_popcount

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

#define maxn 200010

int fen[maxn];

inline void inc(int i, int x) {
    for (; i < maxn; i += i&-i) fen[i] = max(fen[i], x);
}

inline int qry(int i, int res = 0) {
    for (; i; i -= i&-i) res = max(res, fen[i]); return res;
}

void solve() {
    int n; cin >> n;

    vector<pii> v;
    lor(i, 1, n+1) {
        int x; cin >> x;
        if (i - x >= 0) v.eb(i - x, x);
    }

    int res = 0;

    sort(v.bg(), v.ed());
    for (auto& [c, x] : v) {
        int cur = 1 + qry(x - 1);
        res = max(res, cur);
        inc(x, cur);
    }

    cout << res << '\n';
}

int main()
{
    #ifdef LC
        freopen("zz.in", "r+", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; t = 1;  
    while (t --) solve();

    return 0;
}