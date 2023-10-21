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
#define pq priority_queue
#define bcnt __builtin_popcount

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

#define maxn 100010
#define maxp 2000010

int x[maxp], y[maxp], p[maxn];

void solve() {
    int n; cin >> n;
    l0r(i, n) cin >> p[i];
    l0r(i, n) cin >> x[p[i]];

    int m; cin >> m;
    l0r(i, m) cin >> p[i];
    l0r(i, m) cin >> y[p[i]];

    ll res = 1;
    l0r(i, maxp) {
        if (!x[i] && !y[i]) continue;
        if (x[i] < y[i]) res = (res * 0) % MOD;
        if (x[i] != y[i]) res = (res * 2) % MOD;
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