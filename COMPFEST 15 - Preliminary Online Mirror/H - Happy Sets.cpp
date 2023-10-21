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

#define maxn 200010

ll fac[maxn], inv[maxn];

ll fp(ll b, ll p = MOD-2, ll mu = 1) {
    for (; p; b=b*b%MOD, p>>=1) if (p&1) mu=mu*b%MOD; return mu;
}

void comb() {
    lor(i, fac[0] = 1, maxn) fac[i] = (fac[i-1] * i) % MOD;
    inv[maxn-1] = fp(fac[maxn-1]);
    r0r(i, maxn-1) inv[i] = (inv[i+1] * (i+1)) % MOD;
} 

ll f[maxn], g[maxn];

void solve() {
    int n, k; cin >> n >> k;

    comb();

    l0r(i, n+1) f[i] = (k < n - i) ? fac[k+1] : (fac[n-i+1] * fp(n-i+1, k-(n-i)) % MOD);
    l0r(i, n+1) g[i] = (f[i] - f[i+1] + MOD) % MOD;

    ll res = 0;
    l0r(i, n+1) res = (res + g[i] * fac[n] % MOD * inv[i] % MOD) % MOD;

    cout << res << '\n';
}

// {}, {x}, {x, x-1}, {x, x-1, x-2}, ...
// k <= n - i: 1 * 2 * 3 .. * (k + 1) = fac(k+1)
// k > n - i: 1 * 2 * 3 .. * (n - i + 1) * ... 
// = (n - i + 1)! * (n - i + 1) ^ (k - (n - i))

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