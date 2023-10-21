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

struct line {
    ll m, c, p;

    db insx(line& l) {
        if (m == l.m) return c < l.c ? LNF : -LNF;
        return (1.0 * l.c - c) / (1.0 * m - l.m);
    }

    bool operator<(const line& x) {
        return m < x.m;
    }

    bool operator<(const ll x) {
        return m < x;
    }
};

struct segment {
    db x;
    line l;

    bool operator<(const ll y) {
        return x < y;
    }
};

struct convex {
    vector<line> e;
    vector<segment> mc;
    vector<vector<segment>> sc;
    
    void build() {
        sort(e.begin(), e.end());
        
        l0r(i, e.size()) e[i].p = i;

        for (auto& l : e) {
            while (!mc.empty() && l.insx(mc.bk().l) <= mc.bk().x) mc.pb();
            mc.eb((segment) { mc.empty() ? 0 : l.insx(mc.bk().l), l } );
        }

        int sz = mc.size();
        sc.resize(sz);

        l0r(i, sz) {
            int lb = lower_bound(e.bg(), e.ed(), i == 0 ? 0 : mc[i - 1].l.m) - e.bg();
            int rb = lower_bound(e.bg(), e.ed(), i == sz - 1 ? INF : mc[i + 1].l.m + 1) - e.bg(); 

            auto& cc = sc[i];
            lor(j, lb, rb) {
                if (j == mc[i].l.p) continue;

                line& l = e[j];
                while (!cc.empty() && l.insx(cc.bk().l) <= cc.bk().x) cc.pb();
                cc.eb((segment) { cc.empty() ? 0 : l.insx(cc.bk().l), l } );
            }
        }
    };
};

vector<pii> G[maxn], Q[maxn];
ll f[maxn], g[maxn], res[maxn];

void init(int u, int fa) {
    for (auto& [v, w] : G[u]) {
        if (v == fa) continue;
        init(v, u);
        g[u] = max(g[u], max(g[v], f[u] + f[v] + w));
        f[u] = max(f[u], f[v] + w);
    } 
}

void dfs(int u, int fa, ll fw, ll ff) {
    if (Q[u].size() > 0) {
        convex conv;
        conv.e.eb((line) { 0, 0 });
        conv.e.eb((line) { fw, ff});
        for (auto& [v, w] : G[u]) {
            if (v == fa) continue;
            conv.e.eb((line) { w, f[v] });
        }
        conv.build();

        for (auto& [i, k] : Q[u]) {
            int j = lower_bound(conv.mc.bg(), conv.mc.ed(), k + 1e-9) - conv.mc.bg() - 1;
            int x = lower_bound(conv.sc[j].bg(), conv.sc[j].end(), k + 1e-9) - conv.sc[j].bg() - 1;
            ll mx0 = conv.mc[j].l.m * k + conv.mc[j].l.c;
            ll mx1 = conv.sc[j][x].l.m * k + conv.sc[j][x].l.c;
            res[i] = max(mx0 + mx1, g[1]);
        }
    }

    ll fmx[2] = { fw + ff, 0 };
    for (auto& [v, w] : G[u]) {
        if (v == fa) continue;
        ll fc = w + f[v];
        l0r(i, 2) if (fmx[i] < fc) swap(fmx[i], fc);
    }

    for (auto& [v, w] : G[u]) {
        if (v == fa) continue;
        dfs(v, u, w, fmx[fmx[0] == (w + f[v])]);
    }
}

void solve() {
    int n; cin >> n;

    l0r(i, n-1) {
        int u, v, w; cin >> u >> v >> w;
        G[u].eb(v, w), G[v].eb(u, w);
    }

    int q; cin >> q;
    l0r(i, q) {
        int x, k; cin >> x >> k;
        Q[x].eb(i, k);
    }

    init(1, 1);
    dfs(1, 1, 0, 0);

    l0r(i, q) cout << res[i] << '\n';
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