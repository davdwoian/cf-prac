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

ll f[maxn], g[maxn], res;
vector<pii> G[maxn];

void init(int u, int fa) {
    for (auto& [v, w] : G[u]) {
        if (v == fa) continue;
        init(v, u);
        g[u] = max(g[u], max(g[v], f[u] + f[v] + w));
        f[u] = max(f[u], f[v] + w);
    }
}

void dfs(int u, int fa, ll ff, ll fg) {
    ll fmx[4] { ff }, gmx[2] { fg };

    for (auto& [v, w] : G[u]) {
        if (v == fa) continue;
        ll cf = f[v] + w, cg = g[v];
        l0r(i, 4) if (cf > fmx[i]) swap(cf, fmx[i]);
        l0r(i, 2) if (cg > gmx[i]) swap(cg, gmx[i]);
    }

    res = max(res, fmx[0] + fmx[1] + fmx[2] + fmx[3]);

    for (auto& [v, w] : G[u]) {
        if (v == fa) continue;
        ll cf = f[v] + w, cg = g[v];
        ll pf = fmx[fmx[0] == cf], pg = gmx[gmx[0] == cg];
        l0r(i, 3) {
            if (fmx[i] == cf || i == 2) {
                pg = max(pg, fmx[(i+1)%3] + fmx[(i+2)%3]);
                break;
            }
        }
        res = max(res, (w << 1) + cg + pg);
        dfs(v, u, pf + w, pg);
    }
}

void solve() {
    int n; cin >> n;

    ll sw = 0;
    l0r(i, n-1) {
        int u, v, w; cin >> u >> v >> w;
        G[u].eb(v, w), G[v].eb(u, w);
        sw += w;
    }

    init(1, 1);
    dfs(1, 1, 0, 0);
    cout << (2 * sw) - res << '\n';
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