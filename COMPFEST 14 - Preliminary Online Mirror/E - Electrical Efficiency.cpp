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
#define maxk 18

ll fp(ll b, ll p=MOD-2, ll mu=1) {
    for (; p; b=b*b%MOD, p>>=1) if (p&1) mu=mu*b%MOD; return mu;
}

int np[maxn], pj[maxn], pr[maxn], pi;
vector<int> P[maxn];

void sieve() {
    lor(i, 2, maxn) {
        if (!np[i]) pj[i] = pi, pr[pi ++] = i;
        l0r(j, pi) {
            if (1ll * i * pr[j] >= maxn) break;
            np[i * pr[j]] = 1;
            pj[i * pr[j]] = j;
            if (i % pr[j] == 0) break;
        }
    }
}

int a[maxn], p[maxk][maxn], dep[maxn], dfn[maxn], dbn[maxn], z, n, lgn;
vector<int> G[maxn];

auto icmp = [](int& u, int& v) {
    return dfn[u] < dfn[v];
};

void dfs(int u, int fa, int d) {
    dep[u] = d, dfn[u] = z ++, p[0][u] = fa;
    for (auto& v : G[u]) {
        if (v == fa) continue;
        dfs(v, u, d +1);
    }
    dbn[u] = z;
}

void st() {
    lor(i, 1, lgn+1) {
        lor(j, 1, n+1) {
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int i = 0; d; d >>= 1, ++ i) if (d & 1) u = p[i][u];
    for (int i = lgn; i >= 0; -- i) {
        if (p[i][u] != p[i][v]) {
            u = p[i][u], v = p[i][v];
        }
    }
    return u == v ? u : p[0][u];
}

int dp[maxn], f[maxn];

void solve() {
    cin >> n;
    lgn = log2(n);

    sieve();
    
    lor(i, 1, n+1) cin >> a[i];
    lor(i, 1, n+1) {
        while (a[i] != 1) {
            int j = pj[a[i]];
            P[j].eb(i);
            while (a[i] % pr[j] == 0) a[i] /= pr[j];
        }
    }

    l0r(i, n-1) {
        int u, v; cin >> u >> v;
        G[u].eb(v), G[v].eb(u);
    }    

    dfs(1, 1, 1);
    st();

    ll res = 0;
    l0r(i, pi) {
        if (P[i].size() < 3) continue;

        auto& cv = P[i];
        int pc = cv.size();
        
        sort(cv.bg(), cv.ed(), icmp);
        ror(j, 1, pc) cv.eb(lca(cv[j], cv[j-1]));
        l0r(j, cv.size()) dp[cv[j]] = 0;
        l0r(j, pc) dp[cv[j]] = 1;

        sort(cv.bg(), cv.ed(), icmp);
        cv.erase(unique(cv.bg(), cv.ed()), cv.ed());
        int sz = cv.size();

        vector<int> dq { cv[0] };
        lor(j, 1, sz) {
            while (dbn[dq.bk()] <= dfn[cv[j]]) dq.pb();
            f[cv[j]] = dq.bk(), dq.eb(cv[j]);
        }

        ror(j, 1, sz) {
            int u = cv[j];
            dp[f[u]] += dp[u];
            res = (res + 1ll * (dep[u]-dep[f[u]]) * dp[u] % MOD * (pc-dp[u]) % MOD * (pc-2) % MOD) % MOD;
        }
    }
    cout << (res * fp(2)) % MOD << '\n';
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