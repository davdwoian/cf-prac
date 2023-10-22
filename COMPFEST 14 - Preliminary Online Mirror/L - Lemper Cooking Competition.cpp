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

ll a[maxn], b[maxn];

ll merge(int l, int r, ll cnt = 0) {
    if (r - l <= 1) return 0;

    int m = (l + r) / 2;
    cnt += merge(l, m), cnt += merge(m, r);

    lor(i, l, m) b[i] = a[i];
    for (int i = l, j = m, k = l; i < m; ++ i) {
        while (j < r && a[j] < b[i]) a[k ++] = a[j ++];
        a[k ++] = b[i];
        cnt += j - m;
    }
    
    return cnt;
}

void solve() {
    int n; cin >> n;
    lor(i, 1, n+1) cin >> a[i];
    ll mn = LNF, mx = -LNF;
    lor(i, 1, n+1) a[i] += a[i-1], mn = min(mn, a[i]), mx = max(mx, a[i]);
    cout << (mn < 0 || mx != a[n] ? -1 : merge(1, n)) << '\n';
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