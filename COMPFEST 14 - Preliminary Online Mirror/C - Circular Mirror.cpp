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

#define maxn 300010

ll fac[maxn], inv[maxn];

ll fp(ll b, ll p=MOD-2, ll mu=1) {
    for (; p; b=b*b%MOD, p>>=1) if (p&1) mu=mu*b%MOD; return mu;
}

void comb() {
    lor(i, fac[0]=1, maxn) fac[i] = (fac[i-1] * i) % MOD;
    inv[maxn-1] = fp(fac[maxn-1]);
    r0r(i, maxn-1) inv[i] = (inv[i+1] * (i+1)) % MOD;
}

ll C(int n, int r) {
    return fac[n] * inv[n - r] % MOD * inv[r] % MOD;
}

ll d[maxn];

void solve() {
    int n, m; cin >> n >> m;
    
    comb();

    lor(i, 1, n+1) cin >> d[i];
    lor(i, 1, n+1) d[i] += d[i-1];

    int p = 0;
    if (d[n] % 2 == 0) {
        set<ll> v;
        l0r(i, n) p += v.find(d[i] - (d[n] / 2)) != v.end(), v.is(d[i]);
    }

    ll res = 0;
    l0r(k, min(p, m) + 1) res = (res + C(m, k) * C(p, k) % MOD * fac[k] % MOD * fp(m - k, p - k) % MOD * fp(m - k - 1, p - k) % MOD * fp(m - k, n - 2 * p) % MOD) % MOD;
    cout << res << '\n';
}

// k: number of diameters with same color [0, min(d, m)]
// mCk * dPk * ((m - k) * (m - k - 1)) ^ (d - k) * (m - k) ^ (n - 2 * d)

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