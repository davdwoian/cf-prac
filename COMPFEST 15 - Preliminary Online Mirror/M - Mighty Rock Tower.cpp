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

ll pp[110], f[maxn], g[maxn][110];
int p[maxn];

ll fp(ll b, ll p=MOD-2, ll mu=1) {
    for (; p; b=b*b%MOD, p>>=1) if (p&1) mu=mu*b%MOD; return mu;
}

void solve() {
    int n; cin >> n;

    l0r(i, 101) pp[i] = 1ll * i * fp(100) % MOD;
    lor(i, 1, n+1) cin >> p[i];

    ll res = 0;
    lor(i, 1, n+1) {
        f[i] = 1ll * (1 + g[i][p[i]]) * fp(pp[100 - p[i]]) % MOD;
        l0r(j, 100) {
            g[i+1][j] = pp[j] * ((pp[j] * f[i] % MOD + g[i][j]) % MOD) % MOD;
        }
        res = (res + f[i]) % MOD;
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