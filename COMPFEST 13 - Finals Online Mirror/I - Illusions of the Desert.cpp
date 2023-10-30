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


#define maxn 100010

// graph

int a[maxn], f[maxn], dep[maxn], top[maxn], sz[maxn], son[maxn], dfn[maxn], cdfn;
vector<int> G[maxn];

int cost(int u, int v) {
    return max(abs(a[u] + a[v]), abs(a[u] - a[v]));
}

void init(int u=1, int fa=1, int d=1) {
    f[u] = fa, dep[u] = d, sz[u] = 1;
    
    for (auto& v : G[u]) {
        if (v == fa) continue;
        init(v, u, d + 1);

        sz[u] = sz[u] + sz[v];
        son[u] = u && sz[son[u]] >= sz[v] ? son[u] : v;
    }
}

void dfs(int u=1, int t=1) {
    top[u] = t, dfn[u] = cdfn ++;

    if (son[u]) dfs(son[u], t);

    for (auto& v : G[u]) {
        if (v == f[u] || v == son[u]) continue;
        dfs(v, v);
    }
}

// segment tree

ll seg[maxn << 2], sn;

void pushup(int u) {
    seg[u] = seg[u << 1] + seg[(u << 1) + 1];
}

void update(int x, int v, int l=0, int r=sn, int u=1) {
    if (l == r - 1) (seg[u] = v);
    if (l >= r - 1) return;

    int m = (l + r) >> 1;

    if (x < m) update(x, v, l, m, u << 1);
    else update(x, v, m, r, (u << 1) + 1);
    pushup(u);
}

ll query(int ql, int qr, int l=0, int r=sn, int u=1) {
    if (ql >= qr) return 0;
    if (ql <= l && r <= qr) return seg[u];
    
    int m = (l + r) >> 1;

    ll res = 0;
    if (ql < m) res += query(ql, min(qr, m), l, m, u << 1);
    if (qr > m) res += query(max(ql, m), qr, m, r, (u << 1) + 1); 

    return res;
}

// mix

ll slca(int u, int v) {
    ll res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            res += query(dfn[top[u]] + 1, dfn[u] + 1) + cost(top[u], f[top[u]]);
            u = f[top[u]];
        } else {
            res += query(dfn[top[v]] + 1, dfn[v] + 1) + cost(top[v], f[top[v]]);
            v = f[top[v]];
        }
    }

    if (dep[u] < dep[v]) res += query(dfn[u] + 1, dfn[v] + 1);
    if (dep[u] > dep[v]) res += query(dfn[v] + 1, dfn[u] + 1);

    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    sn = n;

    lor(i, 1, n+1) cin >> a[i];

    l0r(i, n-1) {
        int u, v; cin >> u >> v;
        G[u].eb(v), G[v].eb(u);
    }

    init();
    dfs();

    lor(i, 1, n+1) update(dfn[i], cost(i, f[i]));

    l0r(i, q) {
        int t; cin >> t;
        
        if (t == 1) {
            int u, c; cin >> u >> c;
            a[u] = c;
            if (top[f[u]] == top[u]) update(dfn[u], cost(u, f[u]));
            if (son[u]) update(dfn[son[u]], cost(son[u], u));
        } else {
            int u, v; cin >> u >> v;
            cout << slca(u, v) << '\n';
        }
    }
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